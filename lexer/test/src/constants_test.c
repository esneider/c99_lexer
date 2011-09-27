#include <stdio.h>
#include <string.h>
#include "token.h"
#include "constant_token.c"

#define NUM_INPUT ( sizeof( input ) / sizeof( input[0] ) )


const char* input[] = {
    "fe43q",
    "",
    "continue",
    "3654",
    "#@%%^%@!",
    " ''",
    "''",
    "'e'",
    "'\\''",
    "'\\f'",
    "(){}[]",
    "'fewf'fwe",
    "'\\\n\r\\\\fs32\"4$#^@#:>?<\\'",
    "'\\\r\\\\fs32\"4$#^@#:_>?<\\''",
    "'fewfq'",
    "L'fqwf'",
    "4324uLL",
    "435UlL",
    "04352u",
    "0L",
    "0",
    "0x24AbbEll",
    "0x00000",
    "0x324fger",
    "32423.452e-324",
    ".324",
    "324.",
    "324e23",
    "43254e+32",
    "324.4325f",
    ".4324e432L",
    ".",
    "032498.",
    "0x234A.432ffP324",
    "0x234A.432ffp32aa4",
};


struct constant expect[] = {
    { 0,  CONST_NONE,                 0 },
    { 0,  CONST_NONE,                 0 },
    { 0,  CONST_NONE,                 0 },
    { 4,  CONST_DECIMAL,              CONST_MOD_SIGNED_INT },
    { 0,  CONST_NONE,                 0 },
    { 0,  CONST_NONE,                 0 },
    { 0,  CONST_NONE,                 0 },
    { 3,  CONST_CHARACTER,            CONST_MOD_SIGNED_INT },
    { 4,  CONST_CHARACTER,            CONST_MOD_SIGNED_INT },
    { 4,  CONST_CHARACTER,            CONST_MOD_SIGNED_INT },
    { 0,  CONST_NONE,                 0 },
    { 6,  CONST_CHARACTER,            CONST_MOD_SIGNED_INT },
    { 0,  CONST_NONE,                 0 },
    { 24, CONST_CHARACTER,            CONST_MOD_SIGNED_INT },
    { 7,  CONST_CHARACTER,            CONST_MOD_SIGNED_INT },
    { 7,  CONST_CHARACTER,            CONST_MOD_WIDE_CHARACTER },
    { 7,  CONST_DECIMAL,              CONST_MOD_UNSIGNED_LONG_LONG },
    { 5,  CONST_DECIMAL,              CONST_MOD_UNSIGNED_LONG },
    { 6,  CONST_OCTAL,                CONST_MOD_UNSIGNED_INT },
    { 2,  CONST_DECIMAL,              CONST_MOD_SIGNED_LONG },
    { 1,  CONST_DECIMAL,              CONST_MOD_SIGNED_INT },
    { 10, CONST_HEXADECIMAL,          CONST_MOD_SIGNED_LONG_LONG },
    { 7,  CONST_HEXADECIMAL,          CONST_MOD_SIGNED_INT },
    { 6,  CONST_HEXADECIMAL,          CONST_MOD_SIGNED_INT },
    { 14, CONST_DECIMAL_FLOATING,     CONST_MOD_DOUBLE },
    { 4,  CONST_DECIMAL_FLOATING,     CONST_MOD_DOUBLE },
    { 4,  CONST_DECIMAL_FLOATING,     CONST_MOD_DOUBLE },
    { 6,  CONST_DECIMAL_FLOATING,     CONST_MOD_DOUBLE },
    { 9,  CONST_DECIMAL_FLOATING,     CONST_MOD_DOUBLE },
    { 9,  CONST_DECIMAL_FLOATING,     CONST_MOD_FLOAT },
    { 10, CONST_DECIMAL_FLOATING,     CONST_MOD_LONG_DOUBLE },
    { 0,  CONST_NONE,                 0 },
    { 7,  CONST_DECIMAL_FLOATING,     CONST_MOD_DOUBLE },
    { 16, CONST_HEXADECIMAL_FLOATING, CONST_MOD_DOUBLE },
    { 15, CONST_HEXADECIMAL_FLOATING, CONST_MOD_DOUBLE },
};


int main ( void ) {

    for( int i = 0; i < (int)NUM_INPUT; i++ ) {

        struct constant ret = is_constant( input[i] );

        if ( memcmp( &ret, expect + i, sizeof( struct constant ) ) != 0 ) {

            printf( "fail\n\texpected: %zd %d %d\n\treceived: %zd %d %d\n",
                    expect[i].len, expect[i].type, expect[i].modifier,
                    ret.len, ret.type, ret.modifier );
            return 1;
        }
    }

    printf( "ok\n" );

    return 0;
}

