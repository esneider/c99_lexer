#ifndef _STRUCT_ELEMENT_TYPES_H_
#define _STRUCT_ELEMENT_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"


struct struct_element_type {

	const char*  name;
	struct type  type;
	int          bitfield;
};


void struct_element_type_copy ( struct struct_element_type* dest,
                                const struct struct_element_type* src );

bool struct_element_type_compare ( const struct struct_element_type*,
                                   const struct struct_element_type* );

bool struct_element_type_compatible ( const struct struct_element_type*,
                                      const struct struct_element_type* );

void struct_element_type_free ( struct struct_element_type* );


#endif /* _STRUCT_ELEMENT_TYPES_H_ */

