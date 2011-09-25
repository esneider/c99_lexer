#include <stdlib.h>
#include <string.h>
#include "utils.h"


static const char punctuators[][5] = {

	"",
	"!",
	"!=",
	"#",
	"##",
	"%",
	"%:",
	"%:%:",
	"%=",
	"%>",
	"&",
	"&&",
	"&=",
	"(",
	")",
	"*",
	"*=",
	"+",
	"++",
	"+=",
	",",
	"-",
	"--",
	"-=",
	"->",
	".",
	"...",
	"/",
	"/=",
	":",
	":>",
	";",
	"<",
	"<%",
	"<:",
	"<<",
	"<<=",
	"<=",
	"=",
	"==",
	">",
	">=",
	">>",
	">>=",
	"?",
	"[",
	"]",
	"^",
	"^=",
	"{",
	"|",
	"|=",
	"||",
	"}",
	"~"
};


#define NUM_PUNCTUATORS     ( sizeof( punctuators ) / sizeof( punctuators[0] ) )
#define MAX_LEN_PUNCTUATORS sizeof( punctuators[0] )


static enum punctuator_token is_punctuator ( const char* token ) {

	const char (*pos)[ MAX_LEN_PUNCTUATORS ] =
                 bsearch( token, punctuators, NUM_PUNCTUATORS,
                          MAX_LEN_PUNCTUATORS, (cmp_f)strcmp );

	 if ( !pos )
		pos = punctuators;

	return pos - punctuators;
}

