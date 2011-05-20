#include <string.h>
#include "punctuators.h"

typedef int (*cmp_f)( const void*, const void* );


enum punctuators is_punctuator ( const char* token ) {

	const char (*pos)[ MAX_LEN_PUNCTUATORS ] =
		bsearch( token, punctuators, NUM_PUNCTUATORS, sizeof( punctuators[0] ),
		         (cmp_f)strcmp );

	if ( !pos )
		pos = punctuators;

	return pos - punctuators;
}

