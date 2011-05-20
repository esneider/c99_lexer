#include <assert.h>
#include "struct_types.h"


void struct_type_copy ( struct struct_type* dest, const struct struct_type* src ) {

	dest->name = src->name;
	dest->size = src->size;
	dest->elements = malloc( dest->size * sizeof( struct struct_element_type ) );
	assert( dest->elements );

	for ( size_t i = 0; i < dest->size; i++ )
		struct_element_type_copy( dest->elements + i, src->elements + i );
}


bool struct_type_compare ( const struct struct_type* type_a,
                           const struct struct_type* type_b ) {

	if ( type_a->size != type_b->size )
		return false;

	if ( type_a->name != type_b->name ) /* FIXME: maybe strcmp is necessary */
		return false;

	for ( size_t i = 0; i < type_a->size; i++ )
		if ( !struct_element_type_compare( type_a->elements + i,
		                                   type_b->elements + i ) )
			return false;

	return true;
}


bool struct_type_compatible ( const struct struct_type* type_a,
                              const struct struct_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}


void struct_type_free ( struct struct_type* type ) {

	for ( size_t i = 0; i < type->size; i++ )
		struct_element_type_free( type->elements + i );

	free( type->elements );
}

