#include "enum_element_types.h"


void enum_element_type_copy ( struct enum_element_type* dest,
                              const struct enum_element_type* src ) {

	dest->name = src->name;
	dest->value = src->value;
}


bool enum_element_type_compare ( const struct enum_element_type* type_a,
                                 const struct enum_element_type* type_b ) {

	if ( type_a->value != type_b->value )
		return false;

	if ( type_a->name != type_b->name ) /* FIXME: maybe strcmp is necessary */
		return false;

	return true;
}


bool enum_element_type_compatible ( const struct enum_element_type* type_a,
                                    const struct enum_element_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}


void enum_element_type_free ( struct enum_element_type* type ) {

	(void)type;
}

