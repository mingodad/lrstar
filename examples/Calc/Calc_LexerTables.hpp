
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Calc_LexerTables.hpp (generated by DFA 24.0.016)

      #define uint   unsigned int
      #define uchar  unsigned char
      #define ushort unsigned short
      #define MAX    0x80000000

   // Terminal transition matrix ...
      static uchar Tm[1428] = 
      {
         54,    3,    3,   50,   17,   41,   42,   43,   44,   45,   18,    2,   46,   19,    1,   47,    1,    1,   13,    1,
          1,    1,   14,    1,    1,    1,    1,   15,    1,    1,   16,   48,   49,   54,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
          1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    3,    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    4,    4,    0,    0,
          4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
          4,    4,    4,    4,    4,    4,    4,    4,    4,    0,    7,    7,    7,    0,    7,    7,    7,    6,    7,    7,
          7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
          7,    7,    7,    0,    8,    8,    8,    0,    8,    8,    8,    6,    8,    8,   53,    8,    8,    8,    8,    8,
          8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    0,    7,    7,
          7,    0,    7,    7,    7,    9,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
          7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,    0,   10,   10,   10,    0,   10,   10,   10,   31,
         10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
         10,   10,   10,   10,   10,    0,   11,   11,   11,    0,   11,   11,   11,    9,   11,   11,   53,   11,   11,   11,
         11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,    0,
         10,   10,   10,    0,   10,   10,   10,   33,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
         10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,    0,   12,   12,   12,    0,   12,   12,
         12,   34,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
         12,   12,   12,   12,   12,   12,   12,    0,   12,   12,   12,    0,   12,   12,   12,   35,   12,   12,   12,   12,
         12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
         12,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,
          1,    1,    1,    1,    1,   20,    1,   21,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,    1,   36,    1,    1,    1,    1,
          1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    1,    0,    0,    1,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,   22,    1,
          1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,
          1,    1,    1,    1,    1,   23,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   51,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
          0,    0,    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   52,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,    1,    1,
          1,    1,    1,    1,    1,    1,    1,    1,    1,   24,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,   25,    1,    1,    1,    1,    1,    1,    1,    1,
          1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
          0,    0,    1,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,   26,    1,    1,    1,    1,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,
         27,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,   37,    1,    1,    1,    1,    1,
          1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    1,    0,    0,    1,    0,    1,    1,    1,    1,    1,    1,   28,    1,    1,    1,    1,    1,    1,    1,
          1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,
          1,    1,    1,    1,   29,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,    1,    1,    1,    1,
          1,    1,    1,   38,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    1,    0,    0,    1,    0,    1,    1,    1,   39,    1,    1,    1,    1,    1,    1,    1,    1,
          1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
          1,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,   30,    1,    1,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,   32,    1,    1,    1,
          1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    8,    8,    8,    0,    8,    8,
          8,   31,    8,    8,   53,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
          8,    8,    8,    8,    8,    8,    8,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
          0,    0,    1,    0,    1,    1,    1,    1,    1,    1,    1,    1,   40,    1,    1,    1,    1,    1,    1,    0,
          0,    0,    8,    8,    8,    0,    8,    8,    8,   33,    8,    8,   53,    8,    8,    8,    8,    8,    8,    8,
          8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,    0,   11,   11,   11,    0,
         11,   11,   11,   34,   11,   11,   53,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
         11,   11,   11,   11,   11,   11,   11,   11,   11,    0,   11,   11,   11,    0,   11,   11,   11,   35,   11,   11,
         53,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
         11,   11,   11,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,
          1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,    1,    1,    1,    1,
          1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    1,    0,    0,    1,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
          1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
          1,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    1,    1,    1,    1,
          1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0
      };

   // Terminal transition matrix row ...
      static ushort Tr[55] = 
      {
          0,   34,   68,  102,  136,  170,  204,  238,  272,  306,  340,  374,  408,  442,  476,  510,  544,  578,  612,  646,
        680,  714,  748,  782,  816,  850,  884,  918,  952,  986, 1020, 1054, 1088, 1122, 1156, 1190, 1224, 1258, 1292, 1326,
       1360, 1394, 1394, 1394, 1394, 1394, 1394, 1394, 1394, 1394, 1394, 1394, 1394, 1394, 1394
      };

   // Terminal transition matrix column ...
      static uchar Tc[256] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    3,    0,    0,    0,    0,    0,    1,    4,    0,    0,    0,    0,    0,    0,
          5,    6,    7,    8,    0,    9,    0,   10,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,    0,   12,
          0,   13,    0,    0,    0,   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
         14,   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,    0,    0,    0,   15,   14,    0,   16,   14,   14,
         17,   18,   19,   20,   21,   22,   14,   14,   23,   24,   25,   26,   27,   14,   28,   29,   30,   14,   14,   14,
         14,   14,   14,   31,    0,   32,    0,    0,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
         33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
         33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
         33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
         33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
         33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
         33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,   33
      };

   // Terminal number ...
      static char term_numb[55] = 
      {
          0,    2,    3,   -1,   -1,    0,    0,    0,    0,    0,    0,    0,    0,    2,    2,    2,    2,    0,    9,   14,
          2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    0,    2,    0,    0,    0,   16,   21,   20,   17,
         11,   18,   19,    8,    6,    7,   15,   10,   12,   13,    1,    5,    4,   -1,    0
      };

//
////////////////////////////////////////////////////////////////////////////////////////////////////

