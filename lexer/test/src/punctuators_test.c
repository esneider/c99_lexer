#include <stdio.h>
#include "token.h"
#include "punctuator_token.c"

#define NUM_INPUT ( sizeof( input ) / sizeof( input[0] ) )


const char* input[] = {
    "feq",
    "ferggerwgwer",
    "",
    "continue",
    "3654",
    "#@%%^%@!",
    " \"'",
    "_Bool",
    "(){}[]",
    "_Imaginary",
    "+++",
    "++",
    "+",
    "?",
    "##",
    ">",
    "_"
};


int expect[] = {
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_NONE,
    PUNC_INCREMENT,
    PUNC_PLUS,
    PUNC_CONDITIONAL,
    PUNC_DOUBLE_HASH,
    PUNC_GREATER,
    PUNC_NONE
};


int main ( void ) {

    for( int i = 0; i < (int)NUM_INPUT; i++ ) {

        int ret = is_punctuator( input[i] );

        if ( ret != expect[i] ) {
            printf( "fail\n\texpected: %d\n\treceived: %d\n", expect[i], ret );
            return 1;
        }
    }

    printf( "ok\n" );

    return 0;
}

