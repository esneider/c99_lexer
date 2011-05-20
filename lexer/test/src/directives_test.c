#include <stdio.h>
#include <string.h>
#include "directives.h"

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
	"#906\"/usr/include/stdio.h\"3 4",
	"# 906 \"/usr/include/stdio.h\" 3 4 hello",
	"#     \t\t\n  ",
};


struct return_directive expect[] = {

	{ 0, { DIR_NONE, 0 } },
	{ 0, { DIR_NONE, 0 } },
	{ 0, { DIR_NONE, 0 } },
	{ 0, { DIR_NONE, 0 } },
	{ 0, { DIR_NONE, 0 } },
	{ 0, { DIR_NONE, 0 } },
	{ 12, { DIR_OTHER, 0 } },
	{ 5, { DIR_OTHER, 0 } },
	{ 1, { DIR_EMPTY, 0 } },
	{ 8, { DIR_INCLUDE, 0 } },
	{ 18, { DIR_INCLUDE, 0 } },
	{ 16, { DIR_INCLUDE, 0 } },
	{ 18, { DIR_INCLUDE, 0 } },
	{ 36, { DIR_DEFINE, 0 } },
	{ 0, { DIR_NONE, 0 } },
	{ 13, { DIR_DEFINE, 0 } },
	{ 32, { DIR_OUTPUT, (906 << 4) | (1 << 2) | (1 << 3) } },
	{ 29, { DIR_OUTPUT, (906 << 4) | (1 << 2) | (1 << 3) } },
	{ 38, { DIR_OTHER, 0 } },
	{ 1, { DIR_EMPTY, 0 } }
};


int main ( void ) {

	for( int i = 0; i < (int)NUM_INPUT; i++ ) {

		struct return_directive ret = is_directive( input[i] );

		if ( memcmp( &ret, expect + i, sizeof( struct return_directive ) ) != 0 ) {

			printf( "fail\n\texpected: %d %d %d\n\treceived: %d %d %d\n",
					expect[i].len, expect[i].directive.type, expect[i].directive.flags,
					ret.len, ret.directive.type, ret.directive.flags );
			return 1;
		}
	}

	printf( "ok\n" );

	return 0;
}

