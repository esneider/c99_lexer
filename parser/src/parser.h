#ifndef _PARSER_H_
#define _PARSER_H_


#include <stdlib.h>
#include "lexer.h"
#include "declarations.h"
#include "functions.h"


enum external_declarations {

	EXTERNAL_FUNCTION,
	EXTERNAL_DECLARATION
};


struct external_declaration {

	enum external_declarations type;

	union {
		struct function*    function;
		struct declaration* declaration;
	} external;
};


struct parse_tree {

	size_t                       size;
	struct external_declaration* declarations;
};


struct parse_tree parse ( const struct token_list );


#endif /* _PARSER_H_ */

