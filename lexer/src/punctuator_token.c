#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "utils.h"


static enum punctuator_token is_punctuator ( const char* token ) {

    const char (*pos)[ MAX_LEN_PUNCTUATORS ] =
                 bsearch( token, punctuators, NUM_PUNCTUATORS,
                          MAX_LEN_PUNCTUATORS, (cmp_f)strcmp );

     if ( !pos )
        pos = punctuators;

    return pos - punctuators;
}

