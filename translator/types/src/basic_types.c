#include "basic_types.h"


void basic_type_copy ( struct basic_type* dest, const struct basic_type* src ) {

	dest->type = src->type;
}


bool basic_type_compare ( const struct basic_type* type_a,
                          const struct basic_type* type_b ) {

	return type_a->type == type_b->type;
}


bool basic_type_compatible ( const struct basic_type* type_a,
                             const struct basic_type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return true;
}

void basic_type_free ( struct basic_type* type ) {

	(void)type;
}

