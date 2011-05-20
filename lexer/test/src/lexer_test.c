#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "lexer.h"


int main ( int argc, char** argv ) {

	if ( argc != 2 ) {

		printf( "Usage: token_test file\n");
		return 1;
	}

	FILE* file = fopen( argv[1], "rb" );
	long file_size;

	fseek( file, 0, SEEK_END );
	file_size = ftell( file );
	fseek( file, 0, SEEK_SET );

	char* buffer = malloc( file_size + 10 );
	assert( buffer );

	assert( fread( buffer, 1, file_size, file ) == file_size );

	fclose( file );

	struct token_list list = tokenize( buffer );

	for ( int i = 0; i < (int)list.size; i++ ) {

		printf( "(%d:%d) `%.*s` -> ", list.tokens[i].line, list.tokens[i].col,
				list.tokens[i].len, list.tokens[i].ptr );

		switch ( list.tokens[i].type ) {
			case TOK_NONE:
				printf( "ERROR" );
				break;
			case TOK_KEYWORD:
				printf( "KEYWORD: %s", keywords[ list.tokens[i].extra.keyword_index ] );
				break;
			case TOK_IDENTIFIER:
				printf( "IDENTIFIER" );
				break;
			case TOK_CONSTANT:
				switch ( list.tokens[i].extra.constant.type ) {
					case CONST_DECIMAL:
						printf( "DECIMAL" );
						break;
					case CONST_OCTAL:
						printf( "OCTAL" );
						break;
					case CONST_HEXADECIMAL:
						printf( "HEXA" );
						break;
					case CONST_DECIMAL_FLOATING:
						printf( "DEC_FLOAT" );
						break;
					case CONST_HEXADECIMAL_FLOATING:
						printf( "HEX_FLOAT" );
						break;
					case CONST_CHARACTER:
						printf( "CHARACTER" );
						break;
					default:;
				}
				switch ( list.tokens[i].extra.constant.modifier ) {
					case MOD_UNSIGNED_INT:
						printf( ": u" );
						break;
					case MOD_SIGNED_LONG:
						printf( ": l" );
						break;
					case MOD_UNSIGNED_LONG:
						printf( ": ul" );
						break;
					case MOD_SIGNED_LONG_LONG:
						printf( ": ll" );
						break;
					case MOD_UNSIGNED_LONG_LONG:
						printf( ": ull" );
						break;
					case MOD_FLOAT:
						printf( ": f" );
						break;
					case MOD_LONG_DOUBLE:
						printf( ": l" );
						break;
					case MOD_WIDE_CHARACTER:
						printf( ": wide" );
						break;
					default:;
				}
				break;
			case TOK_STRING:
				printf( "STRING" );
				break;
			case TOK_PUNCTUATOR:
				printf( "PUNCTUATOR: %s", punctuators[ list.tokens[i].extra.punctuator_index ] );
				break;
			case TOK_DIRECTIVE:
				printf( "PREPROCESSOR DIRECTIVE: " );
				enum directives dir =   list.tokens[i].extra.directive.type;
				unsigned int    flags = list.tokens[i].extra.directive.flags;

				if ( dir > DIR_OUTPUT )
					printf( "%s", directives[ dir ] );
				else
				if ( dir == DIR_EMPTY )
					printf( "EMPTY" );
				else {
					printf( "OUTPUT: line %d, flags %d",
							flags >> 4, flags &15 );
				}
				break;
		}

		printf( "\n" );
	}

	free( list.tokens );
	free( buffer );

	return 0;
}

