#include "array_types.h"


void array_type_copy ( struct array_type* dest, const struct array_type* src ) {

	dest->size = src->size;
	type_copy( &dest->type, &src->type );
}


bool array_type_compare ( const struct array_type* type_a,
                          const struct array_type* type_b ) {

	if ( type_a->size != type_b->size )
		return false;

	return type_compare( &type_a->type, &type_b->type );
}


bool array_type_compatible ( const struct array_type* type_a,
                             const struct array_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}


void array_type_free ( struct array_type* type ) {

	type_free( &type->type );
}

