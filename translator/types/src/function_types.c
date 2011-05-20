#include <assert.h>
#include "function_types.h"


void function_type_copy ( struct function_type* dest, const struct function_type* src ) {

	dest->size = src->size;

	type_copy( &dest->type, &src->type );

	dest->arguments = malloc( dest->size * sizeof( struct type ) );
	assert( dest->arguments );

	for ( size_t i = 0; i < dest->size; i++ )
		type_copy( dest->arguments + i, src->arguments + i );
}


bool function_type_compare ( const struct function_type* type_a,
                             const struct function_type* type_b ) {

	if ( type_a->size != type_b->size )
		return false;

	if ( !type_compare( &type_a->type, &type_b->type ) )
		return false;

	for ( size_t i = 0; i < type_a->size; i++ )
		if ( !type_compare( type_a->arguments + i, type_b->arguments + i ) )
			return false;

	return true;
}


bool function_type_compatible ( const struct function_type* type_a,
                                const struct function_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}


void function_type_free ( struct function_type* type ) {

	type_free( &type->type );

	for ( size_t i = 0; i < type->size; i++ )
		type_free( type->arguments + i );

	free( type->arguments );
}

