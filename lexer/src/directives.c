#include <string.h>
#include <stdio.h>
#include "directives.h"
#include "strings.h"
#include "characters.h"

typedef int (*cmp_f)( const void*, const void* );


struct return_directive is_directive ( char* token ) {

	size_t aux;

	if ( token++[0] != '#' )
		return (struct return_directive){ 0, { DIR_NONE, 0 } };

	char* end = token;
	for ( ; ; ) {
		aux = strspn( end, space_character );
		if ( !end[ aux ] || end[ aux ] == '\n' ) break;
		end += aux;
		end += strcspn( end, delimiter_character );
	}

	size_t size = end - token + 1;

	token += strspn( token, space_character );

	aux = strspn( token, digit_character );

	if ( aux ) {

		struct return_directive dir = { size, { DIR_OUTPUT, 0 } };

		sscanf( token, "%u", &dir.directive.flags );
		dir.directive.flags <<= 4;

		token += aux;
		token += aux = strspn( token, space_character );
		token += aux = is_string( token );

		for ( ; aux; token += aux ) {

			token += aux = strspn( token, space_character );

			if ( !token[0] || token[0] == '\n' )
				return dir;

			size_t flag = 4;
			sscanf( token, "%zu", &flag );
			if ( flag > 0 && flag < 5 )
				dir.directive.flags |= 1 << (flag - 1);

			aux = strspn( token, digit_character );
		}

		return (struct return_directive){ size, { DIR_OTHER, 0 } };
	}

	aux = strspn( token, identifier_character );

	if ( !aux ) {
		if ( !token[0] || token[0] == '\n' )
			return (struct return_directive){ size, { DIR_EMPTY, 0 } };

		return (struct return_directive){ size, { DIR_OTHER, 0 } };
	}

	char c = token[ aux ];
	token[ aux ] = 0;

	const char (*pos)[ MAX_LEN_DIRECTIVES ] =
		bsearch( token, directives, NUM_DIRECTIVES, sizeof( directives[0] ),
		         (cmp_f)strcmp );

	token[ aux ] = c;

	return (struct return_directive){ size, { pos ? pos - directives : DIR_OTHER, 0 } };
}

