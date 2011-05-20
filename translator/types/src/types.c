#include <string.h>
#include <assert.h>
#include "types.h"
#include "basic_types.h"
#include "array_types.h"
#include "pointer_types.h"
#include "function_types.h"
#include "struct_types.h"
#include "union_types.h"
#include "enum_element_types.h"
#include "enum_types.h"
#include "typedefed_types.h"


void type_copy ( struct type* dest, const struct type* src ) {

	memcpy( dest, src, sizeof( struct type ) );

	switch ( dest->type ) {

		#define malloc_and_redirect( _type ) \
			dest->info._type = malloc( sizeof( struct _type ) ); \
			assert( dest->info._type );                          \
			_type##_copy( dest->info._type, src->info._type )

		case BASIC_TYPE:        malloc_and_redirect( basic_type );        break;
		case ARRAY_TYPE:        malloc_and_redirect( array_type );        break;
		case POINTER_TYPE:      malloc_and_redirect( pointer_type );      break;
		case FUNCTION_TYPE:     malloc_and_redirect( function_type );     break;
		case STRUCT_TYPE:       malloc_and_redirect( struct_type );       break;
		case UNION_TYPE:        malloc_and_redirect( union_type );        break;
		case ENUM_TYPE:         malloc_and_redirect( enum_type );         break;
		case ENUM_ELEMENT_TYPE: malloc_and_redirect( enum_element_type ); break;
		case TYPEDEFED_TYPE:    malloc_and_redirect( typedefed_type );    break;

		#undef malloc_and_redirect
	}
}


bool type_compare ( const struct type* type_a, const struct type* type_b ) {

	if ( memcmp ( &type_a->qualifiers, &type_b->qualifiers,
	              sizeof( struct qualifiers ) ) != 0 )
		return false;

	if ( type_a->type == TYPEDEFED_TYPE )
		return type_compare( type_a->info.typedefed_type->type, type_b );

	if ( type_b->type == TYPEDEFED_TYPE )
		return type_compare( type_a, type_b->info.typedefed_type->type );

	if ( type_a->type != type_b->type )
		return false;

	switch ( type_a->type ) {

		#define redirect( _type ) \
			_type##_compare( type_a->info._type, type_b->info._type )

		case BASIC_TYPE:        return redirect( basic_type );
		case ARRAY_TYPE:        return redirect( array_type );
		case POINTER_TYPE:      return redirect( pointer_type );
		case FUNCTION_TYPE:     return redirect( function_type );
		case STRUCT_TYPE:       return redirect( struct_type );
		case UNION_TYPE:        return redirect( union_type );
		case ENUM_TYPE:         return redirect( enum_type );
		case ENUM_ELEMENT_TYPE: return redirect( enum_element_type );

		default: return false;

		#undef redirect
	}
}


bool type_compatible ( const struct type* type_a, const struct type* type_b ) {

	(void)type_a;
	(void)type_b;

	// TODO

	return false;
}


void type_free ( struct type* type ) {

	switch ( type->type ) {

		#define redirect_and_free( _type ) \
			_type##_free( type->info._type ); \
			free( type->info._type )

		case BASIC_TYPE:        redirect_and_free( basic_type );        break;
		case ARRAY_TYPE:        redirect_and_free( array_type );        break;
		case POINTER_TYPE:      redirect_and_free( pointer_type );      break;
		case FUNCTION_TYPE:     redirect_and_free( function_type );     break;
		case STRUCT_TYPE:       redirect_and_free( struct_type );       break;
		case UNION_TYPE:        redirect_and_free( union_type );        break;
		case ENUM_TYPE:         redirect_and_free( enum_type );         break;
		case ENUM_ELEMENT_TYPE: redirect_and_free( enum_element_type ); break;
		case TYPEDEFED_TYPE:    redirect_and_free( typedefed_type );    break;

		#undef redirect_and_free
	}
}


struct type* usual_arithmetic_conversion ( const struct type* type_a,
                                           const struct type* type_b ) {

	(void)type_a;
	(void)type_b;

	return NULL;
}


struct type* array_decay ( const struct type* type ) {

	(void)type;

	return NULL;
}


struct type* function_raise ( const struct type* type ) {

	(void)type;

	return NULL;
}


char* type_declare ( const struct type* type ) {

	(void)type;

	return NULL;
}


char* type_mangle ( const struct type* type ) {

	(void)type;

	return NULL;
}

