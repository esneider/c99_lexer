#include <string.h>
#include "strings.h"


size_t is_string( const char* token ) {

	size_t ret = 2;

	if ( token[0] == 'L' ) {
		token++;
		ret++;
	}

	if ( token++[0] != '"' )
		return 0;

	for ( ; token[0] != '"' || token[-1] == '\\'; token++, ret++ )
		if ( !token[0] || token[0] == '\n' )
			return 0;

	return ret;
}

