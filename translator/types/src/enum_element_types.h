#ifndef _ENUM_ELEMENT_TYPES_H_
#define _ENUM_ELEMENT_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"


struct enum_element_type {

	const char* name;
	int         value;
};


void enum_element_type_copy ( struct enum_element_type* dest,
                              const struct enum_element_type* src );

bool enum_element_type_compare ( const struct enum_element_type*,
                                 const struct enum_element_type* );

bool enum_element_type_compatible ( const struct enum_element_type*,
                                    const struct enum_element_type* );

void enum_element_type_free ( struct enum_element_type* );


#endif /* _ENUM_ELEMENT_TYPES_H_ */

