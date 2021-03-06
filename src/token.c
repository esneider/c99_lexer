#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "token.h"
#include "keyword_token.c"
#include "identifier_token.c"
#include "constant_token.c"
#include "string_token.c"
#include "punctuator_token.c"
#include "directive_token.c"


struct token_node {

    struct token       token;
    struct token_node* next;
    struct token_node* prev;
};


struct token_head {

    size_t size;
    struct token_node* first;
    struct token_node* last;
};


static void list_push_back ( struct token_head* head, struct token* token ) {

    struct token_node* node = malloc( sizeof( struct token_node ) );
    assert( node );

    memcpy( &node->token, token, sizeof( struct token ) );
    head->size++;
    node->next = NULL;
    node->prev = head->last;
    head->last = node;

    if ( node->prev )
        node->prev->next = node;
    else
        head->first = node;
}


static void next_token_start ( struct token* token ) {

    for ( ; token->ptr[0]; token->ptr++ ) {

        switch ( token->ptr[0] ) {

            case '\n':
                token->col = 0;
                token->line++;
            break;

            case '\r':
                token->col = 0;
                break;

            case '\t':
            case '\v':
            case '\f':
            case ' ':
                token->col++;
                break;

            default:
                return;
        }
    }
}


/* We are all cache-friendly around here :) */
static struct token_list make_token_list ( struct token_head* head ) {

    struct token_list list;

    list.size = head->size;
    list.tokens = malloc( list.size * sizeof( struct token ) );
    assert( list.tokens );

    struct token_node *node = head->first, *aux;
    struct token *pos = list.tokens;

    for ( ; node; pos++ ) {

        memcpy( pos, &node->token, sizeof( struct token ) );

        aux = node;
        node = node->next;
        free( aux );

        pos->next = pos+1;
        pos->prev = pos-1;
    }

    list.tokens[0].prev = pos[-1].next = NULL;

    return list;
}


static void next_token_end ( struct token_head* head, struct token* token ) {

    /* if starting a new line, check for directive */
    if ( !head->size || head->last->token.line != token->line ) {

        struct directive dir = is_directive( token->ptr );

        if ( dir.type ) {

            token->len                  = dir.len;
            token->type                 = TOK_DIRECTIVE;
            token->info.directive       = dir.type;
            token->extra.directive_flag = dir.flag;

            return;
        }
    }

    /* check for literal strings */
    token->len = is_string( token->ptr );

    if ( token->len ) {

        token->type = TOK_STRING;
        return;
    }

    /* now for constants */
    struct constant con = is_constant( token->ptr );

    if ( con.type ) {

        token->len                     = con.len;
        token->type                    = TOK_CONSTANT;
        token->info.constant           = con.type;
        token->extra.constant_modifier = con.modifier;

        return;
    }

    /* check for identifiers and keywords */
    token->len = is_identifier( token->ptr );

    if ( token->len ) {

        char c = token->ptr[ token->len ];
        token->ptr[ token->len ] = 0;

        token->info.keyword = is_keyword( token->ptr );

        token->ptr[ token->len ] = c;

        token->type = token->info.keyword ? TOK_KEYWORD : TOK_IDENTIFIER;

        return;
    }

    /* and finally, puntuators */
    for ( int i = MAX_LEN_PUNCTUATORS; --i; ) {

        char c = token->ptr[i];
        token->ptr[i] = 0;

        token->info.punctuator = is_punctuator( token->ptr );

        token->ptr[i] = c;

        if ( token->info.punctuator ) {

            token->type = TOK_PUNCTUATOR;
            token->len = strlen( punctuators[ token->info.punctuator ] );

            return;
        }
    }

    /* else, error */
    token->type = TOK_NONE;
    token->len  = strcspn( token->ptr, delimiter_character );
}


struct token_list tokenize ( char* buffer ) {

    struct token_head head = { 0, NULL, NULL };
    struct token      token;

    token.line = 1;
    token.col  = 0;
    token.ptr  = buffer;

    for ( ; ; ) {

        next_token_start( &token );

        if ( !token.ptr[0] )
            return make_token_list( &head );

        next_token_end( &head, &token );
        list_push_back( &head, &token );

        token.ptr += token.len;
        token.col += token.len;
    }
}

