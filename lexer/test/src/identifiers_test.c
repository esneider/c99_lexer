#include <stdio.h>
#include "token.h"
#include "identifier_token.c"

#define NUM_INPUT ( sizeof( input ) / sizeof( input[0] ) )


const char* input[] = {
	"fe43q",
	"f34erGREggeHRTrwgwer",
	"",
	"continue",
	"3654",
	"#@%%^%@!",
	" \"'",
	"_34",
	"(){}[]",
	"_",
	"vef435GR%"
};


int expect[] = {
	5,
	20,
	0,
	8,
	0,
	0,
	0,
	3,
	0,
	1,
	8
};


int main ( void ) {

	for( int i = 0; i < (int)NUM_INPUT; i++ ) {

		int ret = is_identifier( input[i] );

		if ( ret != expect[i] ) {
			printf( "fail\n\texpected: %d\n\treceived: %d\n", expect[i], ret );
			return 1;
		}
	}

	printf( "ok\n" );

	return 0;
}

