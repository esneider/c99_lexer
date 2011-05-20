#include <string.h>
#include "keywords.h"

typedef int (*cmp_f)( const void*, const void* );


enum keywords is_keyword ( const char* token ) {

	const char (*pos)[ MAX_LEN_KEYWORDS ] =
		bsearch( token, keywords, NUM_KEYWORDS, sizeof( keywords[0] ),
		         (cmp_f)strcmp );

	if ( !pos )
		pos = keywords;

	return pos - keywords;
}

