#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_


#include <stdlib.h>
#include "declarations.h"
#include "statements.h"


struct function {

	struct declaration_specifiers specifiers;
	struct declarator             declarator;
	size_t                        size;
	struct declaration*           declarations;
	struct compound_statement     body;
}


#endif /* _FUNCTIONS_H_ */

