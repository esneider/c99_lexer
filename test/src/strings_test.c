#include <stdio.h>
#include "token.h"
#include "string_token.c"

#define NUM_INPUT ( sizeof( input ) / sizeof( input[0] ) )


const char* input[] = {
    "fe43q",
    "",
    "continue",
    "3654",
    "#@%%^%@!",
    " \"'",
    "(){}[]",
    "\"fewf'fwe",
    "\"\\\n\r\\\\fs324$#^@#:>?<\\\"",
    "\"\\\r\\\\fs324$#^@#:>?<\\\"\"",
    "\"fewfq\"",
    "L\"fqwf\""
};


int expect[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    22,
    7,
    7,
};


int main ( void ) {

    for( int i = 0; i < (int)NUM_INPUT; i++ ) {

        int ret = is_string( input[i] );

        if ( ret != expect[i] ) {
            printf( "fail\n\texpected: %d\n\treceived: %d\n", expect[i], ret );
            return 1;
        }
    }

    printf( "ok\n" );

    return 0;
}

