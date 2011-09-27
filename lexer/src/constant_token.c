#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "character_constants.h"


struct constant {

    size_t                       len;
    enum constant_token          type;
    enum constant_token_modifier modifier;
};


#define WIDE_CHAR_FLAG  0x1000000


static size_t is_char_constant ( const char* token ) {

    size_t ret = 2;

    if ( token[0] == 'L' ) {
        ret++;
        token++;
        ret |= WIDE_CHAR_FLAG;
    }

    if ( token++[0] != '\'' )
        return 0;

    for ( bool slash = false; token[0] != '\'' || slash; token++, ret++ ) {

        slash = !slash && token[0] == '\\';

        if ( !token[0] || token[0] == '\n' )
            return 0;
    }

    /* '' or L'' */
    if ( ret < 4 && token[-1] == '\'' )
        return 0;

    return ret;
}


static void get_integer_modifier ( const char* token, struct constant* ret ) {

    char aux[3];

    aux[0] = toupper( token[0] );
    aux[1] = toupper( token[1] );
    aux[2] = toupper( token[2] );

    if ( ( strncmp( aux, "ULL", 3 ) == 0 && token[1] == token[2] ) ||
         ( strncmp( aux, "LLU", 3 ) == 0 && token[0] == token[1] ) )
    {
        ret->len += 3;
        ret->modifier = CONST_MOD_UNSIGNED_LONG_LONG;
        return;
    }

    if ( strncmp( aux, "UL", 2 ) == 0 || strncmp( aux, "LU", 2 ) == 0 ) {

        ret->len += 2;
        ret->modifier = CONST_MOD_UNSIGNED_LONG;
        return;
    }

    if ( aux[0] == 'U' ) {

        ret->len ++;
        ret->modifier = CONST_MOD_UNSIGNED_INT;
        return;
    }

    if ( aux[0] == 'L' ) {

        if ( aux[1] == 'L' ) {

            ret->len += 2;
            ret->modifier = CONST_MOD_SIGNED_LONG_LONG;
            return;
        }

        ret->len ++;
        ret->modifier = CONST_MOD_SIGNED_LONG;
        return;
    }

    ret->modifier = CONST_MOD_SIGNED_INT;
}


static struct constant is_constant ( const char* token ) {

    struct constant ret;

    ret.len = is_char_constant( token );

    if ( ret.len ) {

        ret.type = CONST_CHARACTER;
        ret.modifier = CONST_MOD_SIGNED_INT;

        if ( ret.len & WIDE_CHAR_FLAG ) {

            ret.len &= ~WIDE_CHAR_FLAG;
            ret.modifier = CONST_MOD_WIDE_CHARACTER;
        }

        return ret;
    }

    /* not character */

    bool zero, hex, point, exponent, empty;
    size_t aux;

    zero = hex = point = exponent = empty = false;

    if ( token[0] == '0' ) {

        zero = true;
        token++;
        ret.len++;

        if ( toupper( token[0] ) == 'X' ) {

            hex = true;
            token++;
            ret.len++;

            aux = strspn( token, hexadecimal_digit_character );
        } else {
            aux = strspn( token, octal_digit_character );
        }
    } else {
        aux = strspn( token, digit_character );
    }

    ret.len += aux;
    token += aux;
    empty = !aux;

    /* integer */

    if ( !token[0] || !strchr( "eEpP.89", token[0] ) ) {

        if ( empty && ( hex || !zero ) )
            return (struct constant){ 0, CONST_NONE, 0 };

        get_integer_modifier( token, &ret );

        if ( hex )
            ret.type = CONST_HEXADECIMAL;
        else
            ret.type = zero && !empty ? CONST_OCTAL : CONST_DECIMAL;

        /* TODO: 6.4.4.1.5 Language - Lexical elements - Constants - Integer Constants - Type */

        return ret;
    }

    /* floating */

    if ( hex )
        ret.type = CONST_HEXADECIMAL_FLOATING;
    else
        ret.type = CONST_DECIMAL_FLOATING;

    if ( zero && !hex ) {
        ret.len += aux = strspn( token, digit_character );
        token += aux;
    }

    /* fractional part */
    if ( token[0] == '.' ) {

        point = true;
        ret.len++;
        token++;

        if ( hex )
            aux = strspn( token, hexadecimal_digit_character );
        else
            aux = strspn( token, digit_character );

        ret.len += aux;
        token += aux;

        if ( empty && !aux )
            return (struct constant){ 0, CONST_NONE, 0 };
    }

    /* exponent part */
    if ( strchr( hex ? "pP" : "eE", token[0] ) && token[0] ) {

        exponent = true;
        ret.len++;
        token++;

        if ( token[0] == '+' || token[0] == '-' ) {
            token++;
            ret.len++;
        }

        aux = strspn( token, digit_character );

        ret.len += aux;
        token += aux;

        if ( !aux )
            return (struct constant){ 0, CONST_NONE, 0 };
    }

    if ( !exponent && ( hex || !point ) )
        return (struct constant){ 0, CONST_NONE, 0 };

    /* modifier */
    ret.modifier = CONST_MOD_DOUBLE;

    if ( toupper( token[0] ) == 'F' ) {

        ret.modifier = CONST_MOD_FLOAT;
        ret.len++;
        token++;
    } else
    if ( toupper( token[0] ) == 'L' ) {

        ret.modifier = CONST_MOD_LONG_DOUBLE;
        ret.len++;
        token++;
    }

    return ret;
}

