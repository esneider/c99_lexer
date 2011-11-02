#include <stdio.h>
#include "token.h"
#include "keyword_token.c"

#define NUM_INPUT ( sizeof( input ) / sizeof( input[0] ) )


const char* input[] = {
    "feq",
    "ferggerwgwer",
    "",
    "continue",
    "3654",
    "#@%%^%@!",
    " \"'",
    "auto",
    "_Bool",
    "int",
    "(){}[]",
    "_Imaginary"
};


int expect[] = {
    KWD_NONE,
    KWD_NONE,
    KWD_NONE,
    KWD_CONTINUE,
    KWD_NONE,
    KWD_NONE,
    KWD_NONE,
    KWD_AUTO,
    KWD__BOOL,
    KWD_INT,
    KWD_NONE,
    KWD__IMAGINARY
};


int main ( void ) {

    for( int i = 0; i < (int)NUM_INPUT; i++ ) {

        int ret = is_keyword( input[i] );

        if ( ret != expect[i] ) {
            printf( "fail\n\texpected: %d\n\treceived: %d\n", expect[i], ret );
            return 1;
        }
    }

    printf( "ok\n" );

    return 0;
}

