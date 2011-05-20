#ifndef _STRUCT_TYPES_H_
#define _STRUCT_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "struct_element_types.h"


struct struct_type {

	const char*                 name;
	size_t                      size;
	struct struct_element_type* elements;
};


void struct_type_copy ( struct struct_type* dest, const struct struct_type* src );

bool struct_type_compare ( const struct struct_type*, const struct struct_type* );

bool struct_type_compatible ( const struct struct_type*, const struct struct_type* );

void struct_type_free ( struct struct_type* );


#endif /* _STRUCT_TYPES_H_ */

