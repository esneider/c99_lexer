#ifndef _LEXER_H_
#define _LEXER_H_

#include <stdlib.h>
#include <stdbool.h>
#include "keywords.h"
#include "punctuators.h"
#include "identifiers.h"
#include "strings.h"
#include "constants.h"
#include "directives.h"

enum tokens {
	TOK_NONE,
	TOK_KEYWORD,
	TOK_IDENTIFIER,
	TOK_CONSTANT,
	TOK_STRING,
	TOK_PUNCTUATOR,
	TOK_DIRECTIVE
};


struct token {

	size_t     line;
	size_t     col;

	char*      ptr;
	size_t     len;

	enum tokens type;

	union {
		enum keywords          keyword_index;
		enum punctuators       punctuator_index;
		struct lexer_constant  constant;
		struct lexer_directive directive;
	} extra;

	struct token* next;
	struct token* prev;
};


struct token_list {
	size_t size;
	struct token* tokens;
};


struct token_list tokenize ( char* buffer );


#endif /* _LEXER_H_ */

