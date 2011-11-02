#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <limits.h>


static const char* const non_digit_character =
    "_"
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const char* const dec_digit_character =
    "0123456789";

static const char* const identifier_character =
    "_"
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";

static const char* const oct_digit_character =
    "01234567";

static const char* const hex_digit_character =
    "0123456789"
    "abcdef"
    "ABCDEF";

static const char* const space_character =
    " \t\r\v\f";

static const char* const delimiter_character =
    " \t\n\r\v\f";

#define NUM_DIRECTIVES   ( sizeof( directives ) / sizeof( directives[0] ) )
#define MAX_LEN_DIRECTIVES sizeof( directives[0] )
static const char const directives[][8] = {

    "",
    "",
    "",
    "",
    "define",
    "elif",
    "else",
    "endif",
    "error",
    "if",
    "ifdef",
    "ifndef",
    "include",
    "line",
    "pragma",
    "undef"
};

#define NUM_KEYWORDS   ( sizeof( keywords ) / sizeof( keywords[0] ) )
#define MAX_LEN_KEYWORDS sizeof( keywords[0] )
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
    "while"
};

#define NUM_PUNCTUATORS   ( sizeof( punctuators ) / sizeof( punctuators[0] ) )
#define MAX_LEN_PUNCTUATORS sizeof( punctuators[0] )
static const char punctuators[][5] = {

    "",
    "!",
    "!=",
    "#",
    "##",
    "%",
    "%:",
    "%:%:",
    "%=",
    "%>",
    "&",
    "&&",
    "&=",
    "(",
    ")",
    "*",
    "*=",
    "+",
    "++",
    "+=",
    ",",
    "-",
    "--",
    "-=",
    "->",
    ".",
    "...",
    "/",
    "/=",
    ":",
    ":>",
    ";",
    "<",
    "<%",
    "<:",
    "<<",
    "<<=",
    "<=",
    "=",
    "==",
    ">",
    ">=",
    ">>",
    ">>=",
    "?",
    "[",
    "]",
    "^",
    "^=",
    "{",
    "|",
    "|=",
    "||",
    "}",
    "~"
};

#define TARGET_INT_MAX    INT_MAX
#define TARGET_UINT_MAX   UINT_MAX
#define TARGET_LONG_MAX   LONG_MAX
#define TARGET_ULONG_MAX  ULONG_MAX
#define TARGET_LLONG_MAX  LLONG_MAX
#define TARGET_ULLONG_MAX ULLONG_MAX

#define DEC_ULLONG_MAX_LEN ( sizeof( dec_ullong_max ) - 1 )
static const char dec_ullong_max[] =
    "18446744073709551615";

#define OCT_ULLONG_MAX_LEN ( sizeof( oct_ullong_max ) - 1 )
static const char oct_ullong_max[] =
    "01777777777777777777777";

#define HEX_ULLONG_MAX_LEN ( sizeof( hex_ullong_max ) - 1 )
static const char hex_ullong_max[] =
    "0xFFFFFFFFFFFFFFFF";

static const unsigned long long int_limits[] = {

    [ CONST_MOD_SIGNED_INT ]         = TARGET_INT_MAX,
    [ CONST_MOD_UNSIGNED_INT ]       = TARGET_UINT_MAX,
    [ CONST_MOD_SIGNED_LONG ]        = TARGET_LONG_MAX,
    [ CONST_MOD_UNSIGNED_LONG ]      = TARGET_ULONG_MAX,
    [ CONST_MOD_SIGNED_LONG_LONG ]   = TARGET_LLONG_MAX,
    [ CONST_MOD_UNSIGNED_LONG_LONG ] = TARGET_ULLONG_MAX
};

static const int signed_dec_const_types[] = {

    CONST_MOD_SIGNED_INT,
    CONST_MOD_SIGNED_LONG,
    CONST_MOD_SIGNED_LONG_LONG,
    -1
};

static const int unsigned_const_types[] = {

    CONST_MOD_UNSIGNED_INT,
    CONST_MOD_UNSIGNED_LONG,
    CONST_MOD_UNSIGNED_LONG_LONG,
    -1
};

static const int signed_hex_const_types[] = {

    CONST_MOD_SIGNED_INT,
    CONST_MOD_UNSIGNED_INT,
    CONST_MOD_SIGNED_LONG,
    CONST_MOD_UNSIGNED_LONG,
    CONST_MOD_SIGNED_LONG_LONG,
    CONST_MOD_UNSIGNED_LONG_LONG,
    -1
};

#define DEC_CONST ( 1 << 4 )
static const int * const int_const_types[] = {

    [ DEC_CONST | CONST_MOD_SIGNED_INT ]         = signed_dec_const_types,
    [ DEC_CONST | CONST_MOD_UNSIGNED_INT ]       = unsigned_const_types,
    [ DEC_CONST | CONST_MOD_SIGNED_LONG ]        = signed_dec_const_types + 1,
    [ DEC_CONST | CONST_MOD_UNSIGNED_LONG ]      = unsigned_const_types + 1,
    [ DEC_CONST | CONST_MOD_SIGNED_LONG_LONG ]   = signed_dec_const_types + 2,
    [ DEC_CONST | CONST_MOD_UNSIGNED_LONG_LONG ] = unsigned_const_types + 2,

    [ CONST_MOD_SIGNED_INT ]         = signed_hex_const_types,
    [ CONST_MOD_UNSIGNED_INT ]       = unsigned_const_types,
    [ CONST_MOD_SIGNED_LONG ]        = signed_hex_const_types + 2,
    [ CONST_MOD_UNSIGNED_LONG ]      = unsigned_const_types + 1,
    [ CONST_MOD_SIGNED_LONG_LONG ]   = signed_hex_const_types + 4,
    [ CONST_MOD_UNSIGNED_LONG_LONG ] = unsigned_const_types + 2,
};


#endif /* _CONSTANTS_H_ */

