#include <string.h>
#include <stdlib.h>
#include "character_constants.h"


size_t is_identifier (const char* token) {

	if (!token[0])
		return 0;
	if (strchr(digit_character, token[0]))
		return 0;

	return strspn(token, identifier_character);
}

