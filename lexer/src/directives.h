#ifndef _DIRECTIVES_H_
#define _DIRECTIVES_H_

#include <stdlib.h>


#define NUM_DIRECTIVES     ( sizeof( directives ) / sizeof( directives[0] ) )
#define MAX_LEN_DIRECTIVES sizeof( directives[0] )


enum directives {

	DIR_NONE,
	DIR_OTHER,
	DIR_EMPTY,
	DIR_OUTPUT,
	DIR_DEFINE,
	DIR_ELIF,
	DIR_ELSE,
	DIR_ENDIF,
	DIR_ERROR,
	DIR_IF,
	DIR_IFDEF,
	DIR_IFNDEF,
	DIR_INCLUDE,
	DIR_LINE,
	DIR_PRAGMA,
	DIR_UNDEF,
};


static const char const directives[][8] = {
	"",
	"",
	"",
	"",
	"define",
	"elif",
	"else",
	"endif",
	"error",
	"if",
	"ifdef",
	"ifndef",
	"include",
	"line",
	"pragma",
	"undef"
};


enum directive_output_flags {

	DIR_FILE_START    = 1,
	DIR_FILE_ENDED    = 2,
	DIR_SYSTEM_HEADER = 4,
	DIR_EXTERN_C      = 8
};


struct lexer_directive {

	enum directives type;
	unsigned int    flags;
};


struct return_directive {

	size_t len;
	struct lexer_directive directive;
};


struct return_directive is_directive ( char* token );


#endif /* _DIRECTIVES_H_ */

