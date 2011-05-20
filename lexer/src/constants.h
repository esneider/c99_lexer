#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <stdlib.h>


enum constants {
	CONST_NONE,
	CONST_DECIMAL,
	CONST_OCTAL,
	CONST_HEXADECIMAL,
	CONST_DECIMAL_FLOATING,
	CONST_HEXADECIMAL_FLOATING,
	CONST_CHARACTER
};


enum modifiers {
	MOD_SIGNED_INT,
	MOD_UNSIGNED_INT,
	MOD_SIGNED_LONG,
	MOD_UNSIGNED_LONG,
	MOD_SIGNED_LONG_LONG,
	MOD_UNSIGNED_LONG_LONG,
	MOD_FLOAT,
	MOD_DOUBLE,
	MOD_LONG_DOUBLE,
	MOD_CHARACTER,
	MOD_WIDE_CHARACTER
};


struct lexer_constant {

	enum constants type;
	enum modifiers modifier;
};


struct return_constant {
	size_t len;
	struct lexer_constant constant;
};


struct return_constant is_constant ( const char* token );


#endif /* _CONSTANTS_H_ */

