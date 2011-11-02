#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "token.h"
#include "constants.h"

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

    char* buffer = calloc( file_size + 10, 1 );
    assert( buffer );

    assert( fread( buffer, 1, file_size, file ) == (size_t)file_size );

    fclose( file );

    struct token_list list = tokenize( buffer );

    for ( int i = 0; i < (int)list.size; i++ ) {

        printf( "(%zd:%zd) `%.*s` -> ", list.tokens[i].line, list.tokens[i].col,
                (int)list.tokens[i].len, list.tokens[i].ptr );

        switch ( list.tokens[i].type ) {
            case TOK_NONE:
                printf( "ERROR" );
                break;
            case TOK_KEYWORD:
                printf( "KEYWORD: %s", keywords[ list.tokens[i].info.keyword ] );
                break;
            case TOK_IDENTIFIER:
                printf( "IDENTIFIER" );
                break;
            case TOK_CONSTANT:
                switch ( list.tokens[i].info.constant ) {
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
                switch ( list.tokens[i].extra.constant_modifier ) {
                    case CONST_MOD_UNSIGNED_INT:
                        printf( ": u" );
                        break;
                    case CONST_MOD_SIGNED_LONG:
                        printf( ": l" );
                        break;
                    case CONST_MOD_UNSIGNED_LONG:
                        printf( ": ul" );
                        break;
                    case CONST_MOD_SIGNED_LONG_LONG:
                        printf( ": ll" );
                        break;
                    case CONST_MOD_UNSIGNED_LONG_LONG:
                        printf( ": ull" );
                        break;
                    case CONST_MOD_FLOAT:
                        printf( ": f" );
                        break;
                    case CONST_MOD_LONG_DOUBLE:
                        printf( ": l" );
                        break;
                    case CONST_MOD_WIDE_CHARACTER:
                        printf( ": wide" );
                        break;
                    default:;
                }
                break;
            case TOK_STRING:
                printf( "STRING" );
                break;
            case TOK_PUNCTUATOR:
                printf( "PUNCTUATOR: %s", punctuators[ list.tokens[i].info.punctuator ] );
                break;
            case TOK_DIRECTIVE:
                printf( "PREPROCESSOR DIRECTIVE: " );
                enum directive_token dir  = list.tokens[i].info.directive;
                unsigned int         flag = list.tokens[i].extra.directive_flag;

                switch ( dir ) {
                    case DIR_OTHER:
                        printf( "OTHER" );
                        break;
                    case DIR_EMPTY:
                        printf( "EMPTY" );
                        break;
                    case DIR_OUTPUT:
                        printf( "OUTPUT: line %u, flag %u", flag >> 4, flag &15 );
                        break;
                    default:
                        printf( "%s", directives[ dir ] );
                }
        }

        printf( "\n" );
    }

    free( list.tokens );
    free( buffer );

    return 0;
}

