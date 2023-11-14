
////////////////////////////////////////////////////////////////////////////////
//
//    PLM_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"


class lrstar_parser;

      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[    70]; // Terminal symbols of the grammar.
         static const char *head_symb[   152]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     1]; // Terminal action names found in the grammar.
         static const uint8  head_numb[   255]; // Head symbol number for a production.
         static const uint16 f_tail   [   256]; // First tail in a production.
         static const int16  tail     [   410]; // Tail symbol number.
         static const int8   arga     [    70]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[   190]       ; // Boolean matrix.
         static const uint8  Br[   148]       ; // Boolean matrix row.
         static const uint8  Bc[    70]       ; // Boolean matrix column.
         static const uint8 Bf[    70]       ; // Boolean matrix filter/mask.
         static const int16  Tm[    69]       ; // Terminal transition matrix.
         static const uint8  Tr[   148]       ; // Terminal transition matrix row.
         static const uint8  Tc[    70]       ; // Terminal transition matrix column.
         static const int16  Nm[  2415]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   148]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   255]       ; // Nonterminal transition matrix column.
         static const uint8  Rm[     5]       ; // Reduction matrix.
         static const int16  Rr[   148]       ; // Reduction matrix row.
         static const uint8  Rc[    70]       ; // Reduction matrix column.
         static const int8   PL[   255]       ; // Production length minus one.

         static const int8   tact_numb[    70]; // Terminal action numbers.
      };

//
////////////////////////////////////////////////////////////////////////////////

