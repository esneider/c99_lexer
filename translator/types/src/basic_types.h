#ifndef _BASIC_TYPES_H_
#define _BASIC_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"


enum basic_types {

	TYPE_VOID,

	TYPE_CHAR,
	TYPE_SIGNED_CHAR,
	TYPE_UNSIGNED_CHAR,

	TYPE_SIGNED_SHORT,
	TYPE_UNSIGNED_SHORT,
	TYPE_SIGNED_INT,
	TYPE_UNSIGNED_INT,
	TYPE_SIGNED_LONG,
	TYPE_UNSIGNED_LONG,
	TYPE_SIGNED_LONG_LONG,
	TYPE_UNSIGNED_LONG_LONG,

	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_LONG_DOUBLE,

	TYPE__BOOL,
	TYPE_FLOAT__COMPLEX,
	TYPE_DOUBLE__COMPLEX,
	TYPE_LONG_DOUBLE__COMPLEX,
	TYPE__IMAGINARY
};


struct basic_type {

	enum basic_types type;
};


void basic_type_copy ( struct basic_type* dest, const struct basic_type* src );

bool basic_type_compare ( const struct basic_type*, const struct basic_type* );

bool basic_type_compatible ( const struct basic_type*, const struct basic_type* );

void basic_type_free ( struct basic_type* );


#endif /* _BASIC_TYPES_H_ */

