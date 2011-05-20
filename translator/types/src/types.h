#ifndef _TYPES_H_
#define _TYPES_H_


#include <stdlib.h>
#include <stdbool.h>


struct basic_type;
struct array_type;
struct pointer_type;
struct function_type;
struct struct_type;
struct union_type;
struct enum_type;
struct enum_element_type;
struct typedefed_type;


struct qualifiers {

	bool volatile_qual: 1;
	bool const_qual: 1;
	bool restrict_qual: 1;
};


enum types {

	BASIC_TYPE = 1,
	ARRAY_TYPE,
	POINTER_TYPE,
	FUNCTION_TYPE,
	STRUCT_TYPE,
	UNION_TYPE,
	ENUM_TYPE,
	ENUM_ELEMENT_TYPE,
	TYPEDEFED_TYPE
};


struct type {

	struct qualifiers qualifiers;
	enum types        type;

	union {
		struct basic_type*        basic_type;
		struct array_type*        array_type;
		struct pointer_type*      pointer_type;
		struct function_type*     function_type;
		struct struct_type*       struct_type;
		struct union_type*        union_type;
		struct enum_type*         enum_type;
		struct enum_element_type* enum_element_type;
		struct typedefed_type*    typedefed_type;
	} info;
};


void type_copy ( struct type* dest, const struct type* src );

bool type_compare ( const struct type*, const struct type* );

bool type_compatible ( const struct type*, const struct type* );

void type_free ( struct type* );


struct type* usual_arithmetic_conversion ( const struct type*, const struct type* );

struct type* array_decay ( const struct type* );

struct type* function_raise ( const struct type* );


extern void typedef_register ( const char* name, const struct type* type );

extern struct type* typedef_get ( const char* name );


char* type_declare ( const struct type* );

char* type_mangle ( const struct type* );


#endif /* _TYPES_H_ */

