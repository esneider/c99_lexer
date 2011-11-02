#include <stdbool.h>
#include "token.h"


static bool is_string ( const char* token, struct token* ret ) {

    ret->len  = 2;
    ret->type = TOK_STRING;

    if ( token[0] == 'L' ) {

        token++;
        ret->len++;
    }

    if ( token++[0] != '"' )
         return false;

    for ( bool slash = false; token[0] != '"' || slash; token++, ret->len++ ) {

        slash = !slash && token[0] == '\\';

        if ( !token[0] || token[0] == '\n' )
            return false;
    }

    return true;
}

