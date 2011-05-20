#ifndef _CHARACTERS_H_
#define _CHARACTERS_H_


static const char* const non_digit_character =
	"_"
	"abcdefghijklmnopqrstuvwxyz"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const char* const digit_character =
	"0123456789";

static const char* const identifier_character =
	"_"
	"abcdefghijklmnopqrstuvwxyz"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"0123456789";

static const char* const octal_digit_character =
	"01234567";

static const char* const hexadecimal_digit_character =
	"0123456789"
	"abcdef"
	"ABCDEF";

static const char* const space_character =
	" \t\r\v\f";

static const char* const delimiter_character =
	" \t\n\r\v\f\0";


#endif

