#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"
#include "Typedef_LexerTables_typedef.h"

#define MAX    0x80000000

namespace Typedef {
// Terminal number ...
extern const int8 lgr_term_numb[50];
const int8 lgr_term_numb[50] = {

       0,     2,    -1,    -1,     0,     0,     0,     0,     0,     0, 
       0,     0,     2,     2,     2,     2,     2,     0,     2,     2, 
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2, 
       2,     2,     0,     2,     2,     0,     0,     2,     0,     9, 
       8,    10,     4,    11,     7,     5,     3,     1,    -1,     0, 
};

// Terminal transition matrix ...
extern const uint8 lgr_Tm[1170];
const uint8 lgr_Tm[1170] = {

      49,     2,     2,    47,    44,    45,    17,    49,    46,     1, 
       1,    12,     1,     1,     1,     1,     1,    13,     1,     1, 
       1,     1,    14,    15,    16,     1,     0,     0,     0,     0, 
       0,     0,     0,     1,     0,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     0,     2,     2,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     3,     3, 
       0,     0,     3,     3,     3,     3,     3,     3,     3,     3, 
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3, 
       3,     3,     3,     3,     6,     6,     6,     0,     5,     6, 
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6, 
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6, 
       7,     7,     7,     0,     5,     7,    48,     7,     7,     7, 
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7, 
       7,     7,     7,     7,     7,     7,     6,     6,     6,     0, 
       8,     6,     6,     6,     6,     6,     6,     6,     6,     6, 
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6, 
       6,     6,     9,     9,     9,     0,    32,     9,     9,     9, 
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9, 
       9,     9,     9,     9,     9,     9,     9,     9,    10,    10, 
      10,     0,     8,    10,    48,    10,    10,    10,    10,    10, 
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10, 
      10,    10,    10,    10,     9,     9,     9,     0,    35,     9, 
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9, 
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9, 
      11,    11,    11,     0,    36,    11,    11,    11,    11,    11, 
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11, 
      11,    11,    11,    11,    11,    11,    11,    11,    11,     0, 
      38,    11,    11,    11,    11,    11,    11,    11,    11,    11, 
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11, 
      11,    11,     0,     0,     0,     0,     0,     0,     0,     1, 
       0,     1,     1,     1,     1,     1,     1,     1,    18,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0, 
       0,     0,     0,     0,     0,     1,     0,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,    19,     1,     1,     1, 
       1,     1,     1,     1,     0,     0,     0,     0,     0,     0, 
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1, 
      20,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       0,     0,     0,     0,     0,     0,     0,     1,     0,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,    21,     0,     0,     0,     0, 
       0,     0,     0,     1,     0,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,    22,     1,     1,     1,     1,     1, 
       1,     1,     0,     0,     0,     0,     4,     0,     3,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     1,     0,     1,    23,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     0,     0,     0,     0,     0,     0, 
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,    39,     1,     1, 
       0,     0,     0,     0,     0,     0,     0,     1,     0,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,    24, 
       1,     1,     1,     1,     1,     1,     0,     0,     0,     0, 
       0,     0,     0,     1,     0,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,    25,     1,     1,     1, 
       1,     1,     0,     0,     0,     0,     0,     0,     0,     1, 
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,    26,     1,     1,     1,     0,     0, 
       0,     0,     0,     0,     0,     1,     0,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,    40, 
       1,     1,     1,     1,     0,     0,     0,     0,     0,     0, 
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,    27,     1,     1,     1,     1, 
       0,     0,     0,     0,     0,     0,     0,     1,     0,     1, 
       1,     1,     1,    28,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     0,     0,     0,     0, 
       0,     0,     0,     1,     0,     1,     1,     1,     1,     1, 
       1,     1,     1,    29,     1,     1,     1,     1,     1,     1, 
       1,     1,     0,     0,     0,     0,     0,     0,     0,     1, 
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,    41,     1,     1,     0,     0, 
       0,     0,     0,     0,     0,     1,     0,     1,     1,     1, 
      30,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     0,     0,     0,     0,     0,     0, 
       0,     1,     0,     1,     1,     1,     1,     1,     1,    31, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       0,     0,     0,     0,     0,     0,     0,     1,     0,     1, 
       1,     1,     1,    33,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     0,     0,     0,     0, 
       0,     0,     0,     1,     0,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,    34,     1,     1,     1,     1,     1, 
       1,     1,     7,     7,     7,     0,    32,     7,    48,     7, 
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7, 
       7,     7,     7,     7,     7,     7,     7,     7,     0,     0, 
       0,     0,     0,     0,     0,     1,     0,     1,     1,     1, 
       1,     1,    42,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     0,     0,     0,     0,     0,     0, 
       0,     1,     0,     1,     1,     1,     1,    37,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       7,     7,     7,     0,    35,     7,    48,     7,     7,     7, 
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7, 
       7,     7,     7,     7,     7,     7,    10,    10,    10,     0, 
      36,    10,    48,    10,    10,    10,    10,    10,    10,    10, 
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10, 
      10,    10,     0,     0,     0,     0,     0,     0,     0,     1, 
       0,     1,     1,     1,    43,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,    10,    10, 
      10,     0,    38,    10,    48,    10,    10,    10,    10,    10, 
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10, 
      10,    10,    10,    10,     0,     0,     0,     0,     0,     0, 
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       0,     0,     0,     0,     0,     0,     0,     1,     0,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     0,     0,     0,     0, 
       0,     0,     0,     1,     0,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     0,     0,     0,     0,     0,     0,     0,     1, 
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0, 
       0,     0,     0,     0,     0,     1,     0,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
};

// Terminal transition matrix row ...
extern const uint16 lgr_Tr[50];
const uint16 lgr_Tr[50] = {

       0,    26,    52,    78,   104,   130,   156,   182,   208,   234, 
     260,   286,   312,   338,   364,   390,   416,   442,   468,   494, 
     520,   546,   572,   598,   624,   650,   676,   702,   728,   754, 
     780,   806,   832,   858,   884,   910,   936,   962,   988,  1014, 
    1040,  1066,  1092,  1118,  1144,  1144,  1144,  1144,  1144,  1144, 
};

// Terminal transition matrix column ...
extern const uint8 lgr_Tc[256];
const uint8 lgr_Tc[256] = {

    0,     0,     0,     0,     0,     0,     0,     0,     0,     1, 
    2,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
    0,     0,     0,     0,     0,     0,     3,     0,     0,     0, 
    0,     0,     1,     0,     0,     0,     0,     0,     0,     0, 
    0,     0,     4,     0,     5,     0,     0,     6,     7,     7, 
    7,     7,     7,     7,     7,     7,     7,     7,     0,     8, 
    0,     0,     0,     0,     0,     9,     9,     9,     9,     9, 
    9,     9,     9,     9,     9,     9,     9,     9,     9,     9, 
    9,     9,     9,     9,     9,     9,     9,     9,     9,     9, 
    9,     0,     0,     0,     0,     9,     0,    10,     9,    11, 
   12,    13,    14,    15,    16,    17,     9,     9,     9,     9, 
   18,    19,    20,     9,    21,    22,    23,    24,     9,     9, 
    9,    25,     9,     0,     0,     0,     0,     0,     0,     0, 
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


};   /* namespace Typedef */
