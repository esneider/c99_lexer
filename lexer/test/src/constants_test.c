#include <stdio.h>
#include <string.h>
#include "constants.h"

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


struct return_constant expect[] = {
	{ 0, { CONST_NONE,0 } },
	{ 0, { CONST_NONE,0 } },
	{ 0, { CONST_NONE,0 } },
	{ 4, { CONST_DECIMAL,MOD_SIGNED_INT } },
	{ 0, { CONST_NONE,0 } },
	{ 0, { CONST_NONE,0 } },
	{ 0, { CONST_NONE,0 } },
	{ 3, { CONST_CHARACTER,MOD_CHARACTER } },
	{ 4, { CONST_CHARACTER,MOD_CHARACTER } },
	{ 4, { CONST_CHARACTER,MOD_CHARACTER } },
	{ 0, { CONST_NONE,0 } },
	{ 6, { CONST_CHARACTER,MOD_CHARACTER } },
	{ 0, { CONST_NONE,0 } },
	{ 24, { CONST_CHARACTER,MOD_CHARACTER } },
	{ 7, { CONST_CHARACTER,MOD_CHARACTER } },
	{ 7, { CONST_CHARACTER,MOD_WIDE_CHARACTER } },
	{ 7, { CONST_DECIMAL,MOD_UNSIGNED_LONG_LONG } },
	{ 5, { CONST_DECIMAL,MOD_UNSIGNED_LONG } },
	{ 6, { CONST_OCTAL,MOD_UNSIGNED_INT } },
	{ 2, { CONST_DECIMAL,MOD_SIGNED_LONG } },
	{ 1, { CONST_DECIMAL,MOD_SIGNED_INT } },
	{ 10, { CONST_HEXADECIMAL,MOD_SIGNED_LONG_LONG } },
	{ 7, { CONST_HEXADECIMAL,MOD_SIGNED_INT } },
	{ 6, { CONST_HEXADECIMAL,MOD_SIGNED_INT } },
	{ 14, { CONST_DECIMAL_FLOATING,MOD_DOUBLE } },
	{ 4, { CONST_DECIMAL_FLOATING,MOD_DOUBLE } },
	{ 4, { CONST_DECIMAL_FLOATING,MOD_DOUBLE } },
	{ 6, { CONST_DECIMAL_FLOATING,MOD_DOUBLE } },
	{ 9, { CONST_DECIMAL_FLOATING,MOD_DOUBLE } },
	{ 9, { CONST_DECIMAL_FLOATING,MOD_FLOAT } },
	{ 10, { CONST_DECIMAL_FLOATING,MOD_LONG_DOUBLE } },
	{ 0, { CONST_NONE,0 } },
	{ 7, { CONST_DECIMAL_FLOATING,MOD_DOUBLE } },
	{ 16, { CONST_HEXADECIMAL_FLOATING,MOD_DOUBLE } },
	{ 15, { CONST_HEXADECIMAL_FLOATING,MOD_DOUBLE } },
};


int main ( void ) {

	for( int i = 0; i < (int)NUM_INPUT; i++ ) {

		struct return_constant ret = is_constant( input[i] );

		if ( memcmp( &ret, expect + i, sizeof( struct return_constant ) ) != 0 ) {

			printf( "fail\n\texpected: %d %d %d\n\treceived: %d %d %d\n",
					expect[i].len, expect[i].constant.type, expect[i].constant.modifier,
					ret.len, ret.constant.type, ret.constant.modifier );
			return 1;
		}
	}

	printf( "ok\n" );

	return 0;
}

