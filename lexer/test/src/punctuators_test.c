#include <stdio.h>
#include "punctuators.h"

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
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_NONE,
	PNT_INCREMENT,
	PNT_PLUS,
	PNT_CONDITIONAL,
	PNT_DOUBLE_HASH,
	PNT_GREATER,
	PNT_NONE
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

