#include <stdio.h>
#include <string.h>
#include "token.h"
#include "string_token.c"
#include "directive_token.c"

#define NUM_INPUT ( sizeof( input ) / sizeof( input[0] ) )


char input[][50] = {

    "grewgoj",
    "4325623",
    "$^%^%&^%",
    "sdw#verwg",
    "\n\n\n#",
    " #ferwrgwg",
    "#fewfgwe few",
    "##### ",
    "#",
    "#include",
    "#include fregferfe",
    "#include #define   ",
    "#include <stdio.h>",
    "#define min(a,b) (((a)<(b))?(a):(b))",
    "",
    "#define HELLO\n WORLD",
    "# 906 \"/usr/include/stdio.h\" 3 4",
    "#906 \"/usr/include/stdio.h\"3 4",
    "#906\"/usr/include/stdio.h\" 3 4",
    "# 906 \"/usr/include/stdio.h\" 3 4 hello",
    "#     \t\t\n  ",
};


struct directive expect[] = {

    { 0,  DIR_NONE,    0 },
    { 0,  DIR_NONE,    0 },
    { 0,  DIR_NONE,    0 },
    { 0,  DIR_NONE,    0 },
    { 0,  DIR_NONE,    0 },
    { 0,  DIR_NONE,    0 },
    { 12, DIR_OTHER,   0 },
    { 5,  DIR_OTHER,   0 },
    { 1,  DIR_EMPTY,   0 },
    { 8,  DIR_INCLUDE, 0 },
    { 18, DIR_INCLUDE, 0 },
    { 16, DIR_INCLUDE, 0 },
    { 18, DIR_INCLUDE, 0 },
    { 36, DIR_DEFINE,  0 },
    { 0,  DIR_NONE,    0 },
    { 13, DIR_DEFINE,  0 },
    { 32, DIR_OUTPUT,  (906 << 4) | (1 << 2) | (1 << 3) },
    { 30, DIR_OTHER,   0 },
    { 30, DIR_OTHER,   0 },
    { 38, DIR_OTHER,   0 },
    { 1,  DIR_EMPTY,   0 }
};


int main ( void ) {

    for( int i = 0; i < (int)NUM_INPUT; i++ ) {

        struct directive ret = is_directive( input[i] );

        if ( memcmp( &ret, expect + i, sizeof( struct directive ) ) != 0 ) {

            printf( "fail\n\texpected: %zd %d %d\n\treceived: %zd %d %d\n",
                    expect[i].len, expect[i].type, expect[i].flag,
                    ret.len, ret.type, ret.flag );
            return 1;
        }
    }

    printf( "ok\n" );

    return 0;
}

