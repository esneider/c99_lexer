#ifndef _KEYWORDS_H_
#define _KEYWORDS_H_

#include <stdlib.h>


#define NUM_KEYWORDS     ( sizeof( keywords ) / sizeof( keywords[0] ) )
#define MAX_LEN_KEYWORDS sizeof( keywords[0] )

enum keywords {
	KW_NONE,
	KW__BOOL,
	KW__COMPLEX,
	KW__IMAGINARY,
	KW_AUTO,
	KW_BREAK,
	KW_CASE,
	KW_CHAR,
	KW_CONST,
	KW_CONTINUE,
	KW_DEFAULT,
	KW_DO,
	KW_DOUBLE,
	KW_ELSE,
	KW_ENUM,
	KW_EXTERN,
	KW_FLOAT,
	KW_FOR,
	KW_GOTO,
	KW_IF,
	KW_INLINE,
	KW_INT,
	KW_LONG,
	KW_REGISTER,
	KW_RESTRICT,
	KW_RETURN,
	KW_SHORT,
	KW_SIGNED,
	KW_SIZEOF,
	KW_STATIC,
	KW_STRUCT,
	KW_SWITCH,
	KW_TYPEDEF,
	KW_UNION,
	KW_UNSIGNED,
	KW_VOID,
	KW_VOLATILE,
	KW_WHILE
};


static const char keywords[][11] = {
	"",
	"_Bool",
	"_Complex",
	"_Imaginary",
	"auto",
	"break",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",
	"float",
	"for",
	"goto",
	"if",
	"inline",
	"int",
	"long",
	"register",
	"restrict",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"void",
	"volatile",
	"while",
};


enum keywords is_keyword ( const char* token );


#endif /* _KEYWORDS_H_ */

