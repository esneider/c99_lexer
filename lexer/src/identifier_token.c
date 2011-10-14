#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "token.h"
#include "constants.h"


static bool is_identifier ( const char* token, struct token* ret ) {

    if ( strchr( dec_digit_character, token[0] ) )
        return false;

    ret->len  = 0;
    ret->type = TOK_IDENTIFIER;

    for ( size_t aux; ; ) {

        ret->len += aux = strspn( token, identifier_character );
        token    += aux;

        /* check for universal character name (aka \uxxxx or \Uxxxxxxxx) */

        if ( token[0] != '\\' || toupper( token[1] ) != 'U' )
            break;

        aux = strspn( token + 2, hex_digit_character );

        if ( aux < ( 4 << ( token[1] == 'U' ) ) )
            return false;

        ret->len += 2 + aux;
        token    += 2 + aux;

        /* and again */
    }

    return true;
}

