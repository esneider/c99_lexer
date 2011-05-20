#ifndef _ENUM_TYPES_H_
#define _ENUM_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "enum_element_types.h"


struct enum_type {

	const char*               name;
	size_t                    size;
	struct enum_element_type* elements;
};


void enum_type_copy ( struct enum_type* dest, const struct enum_type* src );

bool enum_type_compare ( const struct enum_type*, const struct enum_type* );

bool enum_type_compatible ( const struct enum_type*, const struct enum_type* );

void enum_type_free ( struct enum_type* );


#endif /* _ENUM_TYPES_H_ */

