#include <string.h>
#include <stdlib.h>


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


#define NUM_KEYWORDS     (sizeof(keywords) / sizeof(keywords[0]))
#define MAX_LEN_KEYWORDS sizeof(keywords[0])


typedef int (*cmp_f)(const void*, const void*);


enum keyword_token is_keyword (const char* token) {

	const char (*pos)[ MAX_LEN_KEYWORDS ] = bsearch(token, keywords, NUM_KEYWORDS,
                                                    MAX_LEN_KEYWORDS, (cmp_f)strcmp);

	if (!pos) {
		pos = keywords;
    }

	return pos - keywords;
}

