
////////////////////////////////////////////////////////////////////////////////
//
//    COBOL_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"


class lrstar_parser;

      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   351]; // Terminal symbols of the grammar.
         static const char *head_symb[   425]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uint16 head_numb[  1005]; // Head symbol number for a production.
         static const uint16 f_tail   [  1006]; // First tail in a production.
         static const int16  tail     [  1841]; // Tail symbol number.
         static const int8   arga     [   351]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[  4284]       ; // Boolean matrix.
         static const uint16 Br[   887]       ; // Boolean matrix row.
         static const uint8  Bc[   351]       ; // Boolean matrix column.
         static const uint8 Bf[   351]       ; // Boolean matrix filter/mask.
         static const int16  Tm[  2986]       ; // Terminal transition matrix.
         static const uint16 Tr[   887]       ; // Terminal transition matrix row.
         static const uint16 Tc[   351]       ; // Terminal transition matrix column.
         static const int16  Nm[  6183]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   887]       ; // Nonterminal transition matrix row.
         static const uint16 Nc[  1005]       ; // Nonterminal transition matrix column.
         static const uint16 Rm[   239]       ; // Reduction matrix.
         static const int16  Rr[   887]       ; // Reduction matrix row.
         static const uint8  Rc[   351]       ; // Reduction matrix column.
         static const int8   PL[  1005]       ; // Production length minus one.

         static const int8   tact_numb[   351]; // Terminal action numbers.
      };

//
////////////////////////////////////////////////////////////////////////////////

