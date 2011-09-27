#ifndef _DECLARATIONS_H_
#define _DECLARATIONS_H_


#include <stdlib.h>
#include "expressions.h"
#include "tokens.h"


/***********************/
/*** pointer, page 1 ***/
/***********************/


#define MAX_LEN_TYPE_QUALIFIERS sizeof( type_qualifiers[0] )
#define NUM_TYPE_QUALIFIERS \
	( sizeof( type_qualifiers ) / sizeof( type_qualifiers[0] ) )


enum type_qualifiers {
	TYPE_QUAL_CONST,
	TYPE_QUAL_RESTRICT,
	TYPE_QUAL_VOLATILE,
};


static const char type_qualifiers[][9] = {
	"const",
	"restrict",
	"volatile",
};


/* type_qualifier type_qualifier ... */
struct type_qualifier_list {

	size_t                size;
	enum type_qualifiers* qualifiers;
};


/* * type_qualifier_list * type_qualifier_list ... */
struct pointer {

	size_t                      size;
	struct type_qualifier_list* qualifier_lists;
};


/******************************/
/*** enum_specifier, page 6 ***/
/******************************/


/* enumeration_constant */
/* enumeration_constant = constant_expression */
struct enumerator {

	struct identifier  name;
	struct expression* value;
};


/* enumerator , enumerator , ... */
struct enumerator_list {

	size_t             size;
	struct enumerator* enumerators;
};


/* enum identifier OPT { enumerator_list } */
/* enum identifier OPT { enumerator_list , } */
/* enum identifier */
struct enum_specifier {

	struct identifier*      name;
	struct enumerator_list* enumerator_list;
};


/****************************/
/*** typedef_name, page 6 ***/
/****************************/


/* identifier */
struct typedef_name {

	struct identifier name;
};


/*******************************/
/*** identifier_list, page 6 ***/
/*******************************/


/* identifier , identifier , ... */
struct identifier_list {

	size_t             size;
	struct identifier* identifiers;
};


/***************************/
/*** initializer, page 7 ***/
/***************************/


enum designators {

	POSITION_DESIGNATOR,
	MEMBER_DESIGNATOR,
};


struct designator {

	enum designators type;

	union {
		struct expression* expression; /* [ constant_expression ] */
		struct identifier* identifier; /* . identifier */

	} designator;
};


/* designator designator ... = */
struct designation {

	size_t             size;
	struct designator* designators;
};


struct initializer_list;


enum initializers {

	INITIALIZER_EXPRESSION,
	INITIALIZER_LIST,
};


/* assignment_expression */
/* { initializer_list } */
/* { initializer_list , } */
struct initializer {

	enum initializers type;

	union {
		struct assignment_expression* expression;
		struct initializer_list*      initializer_list;

	} initializer;
};


/* designation OPT initializer */
struct initializer_element {

	struct designation designation;
	struct initializer initializer;
};


/* initializer_element , initializer_element , ... */
struct initializer_list {

	size_t                      size;
	struct initializer_element* elements;
};


/***************/
/***  page 3 ***/
/***************/


#define MAX_LEN_STORAGE_SPECIFIERS sizeof( storage_class_specifiers[0] )
#define NUM_STORAGE_SPECIFIERS \
	( sizeof( storage_class_specifiers ) / sizeof( storage_class_specifiers[0] ) )


enum storage_class_specifiers {

	STORAGE_SPEC_AUTO,
	STORAGE_SPEC_EXTERN,
	STORAGE_SPEC_REGISTER,
	STORAGE_SPEC_STATIC,
	STORAGE_SPEC_TYPEDEF,
};


static const char storage_class_specifiers[][9] = {
	"auto",
	"extern",
	"register",
	"static",
	"typedef",
};


/* TODO TODO TODO */


#endif /* _DECLARATIONS_H_ */

