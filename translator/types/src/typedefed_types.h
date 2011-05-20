#ifndef _TYPEDEFED_TYPES_H_
#define _TYPEDEFED_TYPES_H_


#include <stdlib.h>
#include <stdbool.h>
#include "types.h"


struct typedefed_type {

	const char*  name;
	struct type* type;
};


void typedefed_type_copy ( struct typedefed_type* dest,
                           const struct typedefed_type* src );

bool typedefed_type_compare ( const struct typedefed_type*,
                              const struct typedefed_type* );

bool typedefed_type_compatible ( const struct typedefed_type*,
                                 const struct typedefed_type* );

void typedefed_type_free ( struct typedefed_type* );


void typedef_register ( const char* name, const struct type* type );


struct type* typedef_get ( const char* name );


#endif /* _TYPEDEFED_TYPES_H_ */

