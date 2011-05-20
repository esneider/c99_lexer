#ifndef _POINTER_TYPES_H_
#define _POINTER_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"


struct pointer_type {

	struct type type;
};


void pointer_type_copy ( struct pointer_type* dest, const struct pointer_type* src );

bool pointer_type_compare ( const struct pointer_type*, const struct pointer_type* );

bool pointer_type_compatible ( const struct pointer_type*, const struct pointer_type* );

void pointer_type_free ( struct pointer_type* );


#endif /* _POINTER_TYPES_H_ */

