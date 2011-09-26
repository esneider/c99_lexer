#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <stdlib.h>


enum punctuator_token {

    PUNC_NONE,
    PUNC_NOT,
    PUNC_NO_EQUAL,
    PUNC_HASH,
    PUNC_DOUBLE_HASH,
    PUNC_MODULUS,
    PUNC_HASH_ALT,
    PUNC_DOUBLE_HASH_ALT,
    PUNC_MODULUS_ASSIGN,
    PUNC_RIGH_CURLY_BRACKE_ALT,
    PUNC_BITWISE_AND,
    PUNC_AND,
    PUNC_BITWISE_AND_ASSIGN,
    PUNC_LEF_ROUND_BRACKET,
    PUNC_RIGH_ROUND_BRACKET,
    PUNC_MULTIPLICATION,
    PUNC_MULTIPLICATION_ASSIGN,
    PUNC_PLUS,
    PUNC_INCREMENT,
    PUNC_PLUS_ASSIGN,
    PUNC_COMMA,
    PUNC_MINUS,
    PUNC_DECREMENT,
    PUNC_MINUS_ASSIGN,
    PUNC_POINTER_MEMBER,
    PUNC_MEMBER,
    PUNC_ELLIPSIS,
    PUNC_DIVISION,
    PUNC_DIVISION_ASSIGN,
    PUNC_COLON,
    PUNC_RIGH_SQUARE_BRACKE_ALT,
    PUNC_SEMICOLON,
    PUNC_LESS,
    PUNC_LEF_CURLY_BRACKE_ALT,
    PUNC_LEF_SQUARE_BRACKE_ALT,
    PUNC_LEF_SHIFT,
    PUNC_LEF_SHIF_ASSIGN,
    PUNC_LESS_EQUAL,
    PUNC_ASSIGN,
    PUNC_EQUAL,
    PUNC_GREATER,
    PUNC_GREATER_EQUAL,
    PUNC_RIGH_SHIFT,
    PUNC_RIGH_SHIF_ASSIGN,
    PUNC_CONDITIONAL,
    PUNC_LEF_SQUARE_BRACKET,
    PUNC_RIGH_SQUARE_BRACKET,
    PUNC_BITWISE_XOR,
    PUNC_BITWISE_XOR_ASSIGN,
    PUNC_LEF_CURLY_BRACKET,
    PUNC_BITWISE_OR,
    PUNC_BITWISE_OR_ASSIGN,
    PUNC_OR,
    PUNC_RIGH_CURLY_BRACKET,
    PUNC_BITWISE_COMPLEMENT
};


enum keyword_token {

    KWD_NONE,
    KWD__BOOL,
    KWD__COMPLEX,
    KWD__IMAGINARY,
    KWD_AUTO,
    KWD_BREAK,
    KWD_CASE,
    KWD_CHAR,
    KWD_CONST,
    KWD_CONTINUE,
    KWD_DEFAULT,
    KWD_DO,
    KWD_DOUBLE,
    KWD_ELSE,
    KWD_ENUM,
    KWD_EXTERN,
    KWD_FLOAT,
    KWD_FOR,
    KWD_GOTO,
    KWD_IF,
    KWD_INLINE,
    KWD_INT,
    KWD_LONG,
    KWD_REGISTER,
    KWD_RESTRICT,
    KWD_RETURN,
    KWD_SHORT,
    KWD_SIGNED,
    KWD_SIZEOF,
    KWD_STATIC,
    KWD_STRUCT,
    KWD_SWITCH,
    KWD_TYPEDEF,
    KWD_UNION,
    KWD_UNSIGNED,
    KWD_VOID,
    KWD_VOLATILE,
    KWD_WHILE
};


enum directive_token {

    DIR_NONE,
    DIR_OTHER,
    DIR_EMPTY,
    DIR_OUTPUT,
    DIR_DEFINE,
    DIR_ELIF,
    DIR_ELSE,
    DIR_ENDIF,
    DIR_ERROR,
    DIR_IF,
    DIR_IFDEF,
    DIR_IFNDEF,
    DIR_INCLUDE,
    DIR_LINE,
    DIR_PRAGMA,
    DIR_UNDEF,
};


enum output_directive_token_flag {

    DIR_FLAG_FILE_START    = 1,
    DIR_FLAG_FILE_ENDED    = 2,
    DIR_FLAG_SYSTEM_HEADER = 4,
    DIR_FLAG_EXTERN_C      = 8
};


enum constant_token {

    CONST_NONE,
    CONST_DECIMAL,
    CONST_OCTAL,
    CONST_HEXADECIMAL,
    CONST_DECIMAL_FLOATING,
    CONST_HEXADECIMAL_FLOATING,
    CONST_CHARACTER
};


enum constant_token_modifier {

    CONST_MOD_SIGNED_INT,
    CONST_MOD_UNSIGNED_INT,
    CONST_MOD_SIGNED_LONG,
    CONST_MOD_UNSIGNED_LONG,
    CONST_MOD_SIGNED_LONG_LONG,
    CONST_MOD_UNSIGNED_LONG_LONG,
    CONST_MOD_FLOAT,
    CONST_MOD_DOUBLE,
    CONST_MOD_LONG_DOUBLE,
    CONST_MOD_CHARACTER,
    CONST_MOD_WIDE_CHARACTER
};


enum tokens {

    TOK_NONE,
    TOK_KEYWORD,
    TOK_IDENTIFIER,
    TOK_CONSTANT,
    TOK_STRING,
    TOK_PUNCTUATOR,
    TOK_DIRECTIVE
};


struct token {

    size_t line;
    size_t col;

    char*  ptr;
    size_t len;

    enum tokens type;

    union {
        enum keyword_token    keyword;
        enum punctuator_token punctuator;
        enum directive_token  directive;
        enum constant_token   constant;
    } info;

    union {
        unsigned int                 directive_flag;
        enum constant_token_modifier constant_modifier;
    } extra;

    struct token* next;
    struct token* prev;
};


struct token_list {

    size_t size;
    struct token* tokens;
};


/**
 * Analize the buffer and build a list of tokens based on it.
 *
 * @warning Do not free the buffer until you are done with the list,
 * because the list contains pointers to the buffer
 *
 * @param buffer NULL-terminated string
 *
 * @return a linear list of tokens
 */
struct token_list tokenize ( char* buffer );


#endif /* _TOKEN_H_ */

