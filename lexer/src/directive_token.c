#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "utils.h"


struct directive {

    size_t               len;
    enum directive_token type;
    unsigned int         flag;
};


static struct directive is_directive ( char* token ) {

    size_t aux, size;

    if ( token[0] == '#' ) {

        token++;
        size = 1;

    } else
    if ( token[0] == '%' && token[1] == ':' ) {

        token += 2;
        size   = 2;

    } else
        return (struct directive){ 0, DIR_NONE, 0 };

    char* end = token;
    for ( ; ; ) {
        aux = strspn( end, space_character );
        if ( !end[aux] || end[aux] == '\n' )
            break;
        end += aux;
        end += strcspn( end, delimiter_character );
    }

    size  += end - token;
    token += strspn( token, space_character );
    aux    = strspn( token, digit_character );

    if ( aux ) {

        struct directive dir = { size, DIR_OUTPUT, 0 };

        if ( !sscanf( token, "%u", &dir.flag ) )
            return (struct directive){ size, DIR_OTHER, 0 };

        dir.flag <<= 4;

        token += aux;
        token += aux = strspn( token, space_character );

        if ( !aux )
            return (struct directive){ size, DIR_OTHER, 0 };

        token += aux = is_string( token );

        if ( !aux )
            return (struct directive){ size, DIR_OTHER, 0 };

        while ( ( aux = strspn( token, space_character ) ) ) {

            token += aux;

            if ( token[0] < '1' || token[0] > '4' ) break;

            dir.flag |= 1 << ( token++[0] - '1' );
        }

        if ( token[0] == 0 || token[0] == '\n' )
            return dir;

        return (struct directive){ size, DIR_OTHER, 0 };
    }

    aux = strspn( token, identifier_character );

    if ( !aux ) {
        if ( !token[0] || token[0] == '\n' )
            return (struct directive){ size, DIR_EMPTY, 0 };

        return (struct directive){ size, DIR_OTHER, 0 };
    }

    char c = token[ aux ];
    token[ aux ] = 0;

    const char (*pos)[ MAX_LEN_DIRECTIVES ] =
                 bsearch( token, directives, NUM_DIRECTIVES,
                          MAX_LEN_DIRECTIVES, (cmp_f)strcmp );

    token[ aux ] = c;

    return (struct directive){ size, pos ? pos - directives : DIR_OTHER, 0 };
}

