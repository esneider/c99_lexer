#ifndef _STATEMENTS_H_
#define _STATEMENTS_H_


#include <stdlib.h>
#include "expressions.h"
#include "declarations.h"
#include "tokens.h"


struct statement;


/* identifier : statement */
struct identifier_label_statement {

	struct identifier label;
	struct statement  statement;
};


/* case expression : statement */
struct case_label_statement {

	struct expression condition;
	struct statement  statement;
};


/* default : statement */
struct default_label_statement {

	struct statement statement;
};


/* { statement statement ... } */
struct compound_statement {

	size_t            size;
	struct statement* statements;
};


/* if ( expression ) statement */
struct if_statement {

	struct expression condition;
	struct statement  statement;
};


/* if ( expression ) statement else statement */
struct if_else_statement {

	struct expression condition;
	struct statement  statement;
	struct statement  else_statement;
};


/* switch ( expression ) statement */
struct switch_statement {

	struct expression expression;
	struct statement  statement;
};


/* while ( expression ) statement */
struct while_statement {

	struct expression condition;
	struct statement  statement;
};


/* do statement while ( expression ) ; */
struct do_while_statement {

	struct statement  statement;
	struct expression condition;
};


/* for ( expression OPT ; expression OPT; expression OPT ) statement */
struct for_statement {

	struct expression* init;
	struct expression* condition;
	struct expression* repeat;
	struct statement   statement;
};


/* for ( declaration expression OPT; expression OPT ) statement */
struct for_declaration_statement {

	struct declaration init;
	struct expression* condition;
	struct expression* repeat;
	struct statement   statement;
};


/* goto identifier ; */
struct goto_statement {

	struct identifier label;
};


/* continue ; */
struct continue_statement {

	char dummy;
};


/* break ; */
struct break_statement {

	char dummy;
};


/* return expression OPT ; */
struct return_statement {

	struct expression* value;
};


enum statements {

	DECLARATION_STATEMENT,
	EXPRESSION_STATEMENT,

	IDENTIFIER_LABEL_STATEMENT,
	CASE_LABEL_STATEMENT,
	DEFAULT_LABEL_STATEMENT,

	COMPOUND_STATEMENT,

	IF_STATEMENT,
	IF_ELSE_STATEMENT,
	SWITCH_STATEMENT,

	WHILE_STATEMENT,
	DO_WHILE_STATEMENT,
	FOR_STATEMENT,
	FOR_DECLARATION_STATEMENT,

	GOTO_STATEMENT,
	CONTINUE_STATEMENT,
	BREAK_STATEMENT,
	RETURN_STATEMENT
};


struct statement {

	enum statements type;

	union {
		struct declaration*  declaration;
		struct expression*   expression; /* expression OPT ; */

		struct identifier_label_statement* identifier_label_statement;
		struct case_label_statement*       case_label_statement;
		struct default_label_statement*    default_label_statement;

		struct compound_statement*         compound_statement;

		struct if_statement*               if_statement;
		struct if_else_statement*          if_else_statement;
		struct switch_statement*           switch_statement;

		struct while_statement*            while_statement;
		struct do_while_statement*         do_while_statement;
		struct for_statement*              for_statement;
		struct for_declaration_statement*  for_declaration_statement;

		struct goto_statement*             goto_statement;
		struct continue_statement*         continue_statement;
		struct break_statement*            break_statement;
		struct return_statement*           return_statement;

	} statement;
};


#endif /* _STATEMENTS_H_ */

