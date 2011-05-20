#include "typedefed_types.h"


void typedefed_type_copy ( struct typedefed_type* dest, const struct typedefed_type* src ) {

	dest->name = src->name;
	dest->type = src->type;
}


bool typedefed_type_compare ( const struct typedefed_type* type_a,
                             const struct typedefed_type* type_b ) {

	if ( type_a->name == type_b->name )
		return true;

	return type_compare( type_a->type, type_b->type );
}


bool typedefed_type_compatible ( const struct typedefed_type* type_a,
                                const struct typedefed_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}


void typedefed_type_free ( struct typedefed_type* type ) {

	(void)type;
}


void typedef_register ( const char* name, const struct type* type ) {

	(void)name;
	(void)type;
}


struct type* typedef_get ( const char* name ) {

	(void)name;

	return NULL;
}

