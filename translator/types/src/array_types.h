#ifndef _ARRAY_TYPES_H_
#define _ARRAY_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"


struct array_type {

	struct type type;
	int         size;
};


void array_type_copy ( struct array_type* dest, const struct array_type* src );

bool array_type_compare ( const struct array_type*, const struct array_type* );

bool array_type_compatible ( const struct array_type*, const struct array_type* );

void array_type_free ( struct array_type* );


#endif /* _ARRAY_TYPES_H_ */

