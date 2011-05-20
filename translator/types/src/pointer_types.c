#include "pointer_types.h"


void pointer_type_copy ( struct pointer_type* dest, const struct pointer_type* src ) {

	type_copy( &dest->type, &src->type );
}


bool pointer_type_compare ( const struct pointer_type* type_a,
                            const struct pointer_type* type_b ) {

	return type_compare( &type_a->type, &type_b->type );
}


bool pointer_type_compatible ( const struct pointer_type* type_a,
                               const struct pointer_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}


void pointer_type_free ( struct pointer_type* type ) {

	type_free( &type->type );
}

