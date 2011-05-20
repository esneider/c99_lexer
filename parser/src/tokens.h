#ifndef _TOKENS_H_
#define _TOKENS_H_


#include "lexer.h"
#include "keywords.h"
#include "puntuators.h"


struct keyword {

	struct token* token;
	enum keywords index;
};


struct punctuator {

	struct token*    token;
	enum punctuators index;
}


struct identifier {

	struct token* token;
};


struct constant {

	struct token* token;
};


struct string {

	struct token* token;
};


#endif /* _TOKENS_H_ */

