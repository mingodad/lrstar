#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"
#include "Goodbye_LexerTables_typedef.h"

#define MAX    0x80000000

namespace Goodbye {
    extern const int8 lgr_term_numb[13];  /* gcc can elide unreferenced constants. */
    const int8 lgr_term_numb[13] = {  /* Terminal number. */

            0,     2,    -1,     2,     2,     2,     2,     2,     2,     3, 
            4,     1,     0, 
    };

    extern const uint8 lgr_Tm[132];  /* gcc can elide unreferenced constants. */
    const uint8 lgr_Tm[132] = {  /* Terminal transition matrix. */

           12,     2,    11,    10,    12,     1,     1,     1,     1,     3, 
            1,     1,     0,     0,     0,     0,     1,     1,     1,     1, 
            1,     1,     1,     1,     0,     2,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            1,     1,     1,     1,     1,     1,     4,     1,     0,     0, 
            0,     0,     1,     1,     1,     1,     1,     1,     5,     1, 
            0,     0,     0,     0,     1,     1,     1,     6,     1,     1, 
            1,     1,     0,     0,     0,     0,     1,     1,     7,     1, 
            1,     1,     1,     1,     0,     0,     0,     0,     1,     1, 
            1,     1,     1,     1,     1,     8,     0,     0,     0,     0, 
            1,     1,     1,     1,     9,     1,     1,     1,     0,     0, 
            0,     0,     1,     1,     1,     1,     1,     1,     1,     1, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0, 
    };

    extern const uint8 lgr_Tr[13];  /* gcc can elide unreferenced constants. */
    const uint8 lgr_Tr[13] = {  /* Terminal transition matrix row. */

            0,    12,    24,    36,    48,    60,    72,    84,    96,   108, 
          120,   120,   120, 
    };

    extern const uint8 lgr_Tc[256];  /* gcc can elide unreferenced constants. */
    const uint8 lgr_Tc[256] = {  /* Terminal transition matrix column. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     1, 
            1,     1,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     2,     0,     0,     0, 
            0,     0,     1,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     3,     0,     4,     4, 
            4,     4,     4,     4,     4,     4,     4,     4,     0,     0, 
            0,     0,     0,     0,     0,     5,     6,     5,     7,     8, 
            5,     9,     5,     5,     5,     5,     5,     5,     5,    10, 
            5,     5,     5,     5,     5,     5,     5,     5,     5,    11, 
            5,     0,     0,     0,     0,     5,     0,     5,     5,     5, 
            5,     5,     5,     5,     5,     5,     5,     5,     5,     5, 
            5,     5,     5,     5,     5,     5,     5,     5,     5,     5, 
            5,     5,     5,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0, 
    };


};   /* namespace Goodbye */