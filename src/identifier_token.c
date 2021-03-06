#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constants.h"


static size_t is_identifier ( const char* token ) {

    if ( strchr( dec_digit_character, token[0] ) )
        return 0;

    size_t len = 0, aux;

    for ( ; ; ) {

        len += aux = strspn( token, identifier_character );
        token += aux;

        /* check for universal character name (aka \uxxxx or \Uxxxxxxxx) */

        if ( token[0] != '\\' || toupper( token[1] ) != 'U' )
            break;

        aux = strspn( token + 2, hex_digit_character );

        if ( aux < ( 4 << ( token[1] == 'U' ) ) )
            return 0;

        len += 2 + aux;
        token += 2 + aux;

        /* and again */
    }

    return len;
}

