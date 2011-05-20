#include <stdio.h>
#include "keywords.h"

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
	KW_NONE,
	KW_NONE,
	KW_NONE,
	KW_CONTINUE,
	KW_NONE,
	KW_NONE,
	KW_NONE,
	KW_AUTO,
	KW__BOOL,
	KW_INT,
	KW_NONE,
	KW__IMAGINARY
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

