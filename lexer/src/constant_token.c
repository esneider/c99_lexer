#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "constants.h"


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

        ret->len++;
        ret->modifier = CONST_MOD_UNSIGNED_INT;
        return;
    }

    if ( aux[0] == 'L' ) {

        if ( aux[1] == 'L' ) {

            ret->len += 2;
            ret->modifier = CONST_MOD_SIGNED_LONG_LONG;
            return;
        }

        ret->len++;
        ret->modifier = CONST_MOD_SIGNED_LONG;
        return;
    }

    ret->modifier = CONST_MOD_SIGNED_INT;
}


static bool read_overflows ( const char* str, int flag,
                             unsigned long long* num )
{

    #define includes( s, c ) ( str[c] && strchr( (s), str[c] ) )

    switch ( flag ) {

        case 0: /* decimal */

            sscanf( str, "%llu", num );

            return *num == TARGET_ULLONG_MAX &&
                   ( includes( dec_digit_character, DEC_ULLONG_MAX_LEN ) ||
                      strncmp( str, dec_ullong_max, DEC_ULLONG_MAX_LEN ) != 0 );


        case 1: /* octal */

            sscanf( str, "%llo", num );

            return *num == TARGET_ULLONG_MAX &&
                   ( includes( oct_digit_character, OCT_ULLONG_MAX_LEN ) ||
                      strncmp( str, oct_ullong_max, OCT_ULLONG_MAX_LEN ) != 0 );

        case 2: /* hexadecimal */

            sscanf( str, "%llx", num );

            if ( *num == TARGET_ULLONG_MAX ) {

                if ( includes( hex_digit_character, HEX_ULLONG_MAX_LEN ) )

                    return true;

                for ( int i = 2; i < 18; i++ )

                    if ( toupper( str[i] ) != hex_ullong_max[i] )

                        return true;
            }
            return false;
    }

    #undef includes

    /* Should never reach this */
    return false;
}


static struct constant check_integer_type ( const char* str, int flag,
                                           struct constant ret )
{
    unsigned long long num;

    if ( read_overflows( str, flag, &num ) )

        return (struct constant){ 0, CONST_NONE, 0 };

    /* promote to sufficiently large type */
    const int * types;

    if ( !flag )
        ret.modifier |= DEC_CONST;

    for( types = int_const_types[ ret.modifier ]; *types != -1; types++ ) {

        if ( num <= int_limits[ *types ] ) {

            ret.modifier = *types;
            break;
        }
    }

    if ( *types == -1 )
        return (struct constant){ 0, CONST_NONE, 0 };

    return ret;
}


static struct constant get_float( const char* token, bool empty, bool hex,
                                  struct constant ret )
{
    bool point, exponent;
    size_t aux;

    point = exponent = false;

    /* fractional part */

    if ( token[0] == '.' ) {

        point = true;
        ret.len++;
        token++;

        if ( hex )
            aux = strspn( token, hex_digit_character );
        else
            aux = strspn( token, dec_digit_character );

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

        aux = strspn( token, dec_digit_character );

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

    if ( strchr( identifier_character, *token ) )

        return (struct constant){ 0, CONST_NONE, 0 };

    return ret;
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

    const char* original_token = token;

    bool empty, zero, hex;
    size_t aux;

    empty = zero = hex = false;

    if ( token[0] == '0' ) {

        zero = true;
        token++;
        ret.len++;

        if ( toupper( token[0] ) == 'X' ) {

            hex = true;
            token++;
            ret.len++;

            aux = strspn( token, hex_digit_character );
        } else {
            aux = strspn( token, oct_digit_character );
        }
    } else {
        aux = strspn( token, dec_digit_character );
    }

    ret.len += aux;
    token += aux;
    empty = !aux;

    /* integer */

    if ( !token[0] || !strchr( "eEpP.89", token[0] ) ) {

        if ( empty && ( hex || !zero ) )
            return (struct constant){ 0, CONST_NONE, 0 };

        if ( hex )
            ret.type = CONST_HEXADECIMAL;
        else
            ret.type = zero && !empty ? CONST_OCTAL : CONST_DECIMAL;

        get_integer_modifier( token, &ret );

        if ( strchr( identifier_character, original_token[ ret.len ] ) )

            return (struct constant){ 0, CONST_NONE, 0 };

        /* 0xFFFFFFF < INT_MAX                                  */
        /* 077777777 < INT_MAX so if len < 10 => fits in an int */
        /* 999999999 < INT_MAX                                  */

        if ( aux < 10 )
            return ret;

        /*
         * 6.4.4.1.5
         * Language - Lexical elements - Constants - Integer Constants - Type
         */
        return check_integer_type( original_token, zero + hex, ret );
    }

    /* floating */

    if ( hex )
        ret.type = CONST_HEXADECIMAL_FLOATING;
    else
        ret.type = CONST_DECIMAL_FLOATING;

    if ( zero && !hex ) {
        ret.len += aux = strspn( token, dec_digit_character );
        token += aux;
    }

    return get_float( token, empty, hex, ret );
}

