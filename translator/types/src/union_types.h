#ifndef _UNION_TYPES_H_
#define _UNION_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "struct_element_types.h"


struct union_type {

	const char*                 name;
	size_t                      size;
	struct struct_element_type* elements;
};


void union_type_copy ( struct union_type* dest, const struct union_type* src );

bool union_type_compare ( const struct union_type*, const struct union_type* );

bool union_type_compatible ( const struct union_type*, const struct union_type* );

void union_type_free ( struct union_type* );


#endif /* _UNION_TYPES_H_ */

