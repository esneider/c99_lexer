#ifndef _EXPRESSIONS_H_
#define _EXPRESSIONS_H_


#include <stdlib.h>
#include "token.h"


struct expression;
struct type_name;
struct initializer_list;


/* expression [ expression ] */
struct array_expression {

	struct expression array;
	struct expression index;
};


/* expression ( expression, expression, ... ) */
struct function_expresion {

	struct expression  function;
	size_t             size;
	struct expression* arguments;
};


/* ( type_name ) { initializer_list }   */
/* ( type_name ) { initializer_list , } */
struct compound_literal_expression {

	struct type_name        type;
	struct initializer_list initializer_list;
};


/* ( type_name ) expression */
struct cast_expression {

	struct type_name  type;
	struct expression object;
};


/* expression . identifier  */
/* expression -> identifier */
struct member_access_expression {

	struct expression object;
	struct token      punctuator;
	struct token      identifier;
};


/* expression ++ */
/* expression -- */
struct post_op_expression {

	struct expression object;
	struct token      punctuator;
};


/* ++ expression */
/* -- expression */
struct pre_op_expression {

	struct token      punctuator;
	struct expression object;
};


/* * expression  */
/* & expression  */
/* + expression  */
/* - expression  */
/* ~ expression  */
/* ! expression  */
struct unary_op_expression {

	struct token      punctuator;
	struct expression object;
};


/* expression * expression  */
/* expression / expression  */
/* expression % expression  */
/* expression + expression  */
/* expression - expression  */
/* expression << expression */
/* expression >> expression */
/* expression < expression  */
/* expression > expression  */
/* expression <= expression */
/* expression >= expression */
/* expression == expression */
/* expression != expression */
/* expression & expression  */
/* expression ^ expression  */
/* expression | expression  */
/* expression && expression */
/* expression || expression */
struct binary_op_expression {

	struct expression left_operand;
	struct token      punctuator;
	struct expression right_operand;
};


/* sizeof expression */
struct sizeof_expression {

	struct expression object;
};


/* sizeof ( type_name ) */
struct sizeof_type_expression {

	struct type_name type;
};


/* expression ? expression : expression */
struct conditional_expression {

	struct expression condition;
	struct expression success;
	struct expression failure;
};


/* expression = expression */
/* expression *= expression */
/* expression /= expression */
/* expression %= expression */
/* expression += expression */
/* expression -= expression */
/* expression <<= expression */
/* expression >>= expression */
/* expression &= expression */
/* expression ^= expression */
/* expression |= expression */
struct assignment_expression {

	struct expression lvalue;
	struct token      punctuator;
	struct expression rvalue;
};


/* expression , expression */
struct comma_expression {

	struct expression left_operand;
	struct expression right_operand;
};


enum expressions {

	IDENTIFIER_EXPRESSION,
	CONSTANT_EXPRESSION,
	STRING_EXPRESSION,
    PARENTHESES_EXPRESSION,

	INDEX_EXPRESSION,
	FUNCTION_EXPRESSION,
	COMPOUND_LITERAL_EXPRESSION,
	CAST_EXPRESSION,

	MEMBER_ACCESS_EXPRESSION,
	POST_OP_EXPRESSION,
	PRE_OP_EXPRESSION,
	UNARY_OP_EXPRESSION,
	BINARY_OP_EXPRESSION,

	SIZEOF_EXPRESSION,
	SIZEOF_TYPE_EXPRESSION,

	CONDITIONAL_EXPRESSION,

	ASSIGNMENT_EXPRESSION,

	COMMA_EXPRESSION
};


struct expression {

	enum expressions type;

	union {
		struct token*      identifier;
		struct token*      constant;
		struct token*      string;
        struct expression* parentheses_expression;

		struct array_expression*            array_expression;
		struct function_expresion*          function_expresion;
		struct compound_literal_expression* compound_literal_expression;
		struct cast_expression*             cast_expression;

		struct member_access_expression*    member_access_expression;
		struct post_op_expression*          post_op_expression;
		struct pre_op_expression*           pre_op_expression;
		struct unary_op_expression*         unary_op_expression;
		struct binary_op_expression*        binary_op_expression;

		struct sizeof_expression*           sizeof_expression;
		struct sizeof_type_expression*      sizeof_type_expression;

		struct conditional_expression*      conditional_expression;

		struct assignment_expression*       assignment_expression;

		struct comma_expression*            comma_expression;

	} expression;
};


#endif /* _EXPRESSIONS_H_ */

