#ifndef _FUNCTION_TYPES_H_
#define _FUNCTION_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"


struct function_type {

	struct type  type;
	size_t       size;
	struct type* arguments;
};


void function_type_copy ( struct function_type* dest, const struct function_type* src );

bool function_type_compare ( const struct function_type*, const struct function_type* );

bool function_type_compatible ( const struct function_type*, const struct function_type* );

void function_type_free ( struct function_type* );


#endif /* _FUNCTION_TYPES_H_ */

