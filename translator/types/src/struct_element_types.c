#include "struct_element_types.h"


void struct_element_type_copy ( struct struct_element_type* dest,
                                const struct struct_element_type* src ) {

	dest->name = src->name;
	dest->bitfield = src->bitfield;

	type_copy( &dest->type, &src->type );
}


bool struct_element_type_compare ( const struct struct_element_type* type_a,
                                   const struct struct_element_type* type_b ) {

	if ( type_a->bitfield != type_b->bitfield )
		return false;

	if ( type_a->name != type_b->name ) /* FIXME: maybe strcmp is necessary */
		return false;

	return type_compare( &type_a->type, &type_b->type );
}


bool struct_element_type_compatible ( const struct struct_element_type* type_a,
                                      const struct struct_element_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}


void struct_element_type_free ( struct struct_element_type* type ) {

	type_free( &type->type );
}

