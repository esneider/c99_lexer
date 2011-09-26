#ifndef _CHARACTER_CONSTANTS_H_
#define _CHARACTER_CONSTANTS_H_


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
    " \t\n\r\v\f";


#endif /* _CHARACTER_CONSTANTS_H_ */

