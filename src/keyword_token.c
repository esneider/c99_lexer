#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "utils.h"


static enum keyword_token is_keyword ( const char* token ) {

    const char (*pos)[ MAX_LEN_KEYWORDS ] =
                 bsearch( token, keywords, NUM_KEYWORDS,
                          MAX_LEN_KEYWORDS, (cmp_f)strcmp );

    if ( !pos )
        pos = keywords;

    return pos - keywords;
}

