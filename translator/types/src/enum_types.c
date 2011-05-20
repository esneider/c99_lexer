#include <assert.h>
#include "enum_types.h"


void enum_type_copy ( struct enum_type* dest, const struct enum_type* src ) {

	dest->name = src->name;
	dest->size = src->size;
	dest->elements = malloc( dest->size * sizeof( struct enum_element_type ) );
	assert( dest->elements );

	for ( size_t i = 0; i < dest->size; i++ )
		enum_element_type_copy( dest->elements + i, src->elements + i );
}


bool enum_type_compare ( const struct enum_type* type_a,
                           const struct enum_type* type_b ) {

	if ( type_a->size != type_b->size )
		return false;

	if ( type_a->name != type_b->name ) /* FIXME: maybe strcmp is necessary */
		return false;

	for ( size_t i = 0; i < type_a->size; i++ )
		if ( !enum_element_type_compare( type_a->elements + i,
		                                   type_b->elements + i ) )
			return false;

	return true;
}


bool enum_type_compatible ( const struct enum_type* type_a,
                              const struct enum_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}


void enum_type_free ( struct enum_type* type ) {

	for ( size_t i = 0; i < type->size; i++ )
		enum_element_type_free( type->elements + i );

	free( type->elements );
}

