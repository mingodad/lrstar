
////////////////////////////////////////////////////////////////////////////////
//
//    Java9_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"

      enum nodecon
      {
         N_start = 0
      };


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   110]; // Terminal symbols of the grammar.
         static const char *head_symb[   366]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const char *node_name[     1]; // Node names found in the grammar.
         static const uint16 head_numb[   733]; // Head symbol number for a production.
         static const uint16 f_tail   [   734]; // First tail in a production.
         static const int16  tail     [  1440]; // Tail symbol number.
         static const int8   arga     [   110]; // Arguments for terminal actions.
         static int8   argx     [   733]; // First arguments for productions.

         private:
         static const uint8  Bm[   663]       ; // Boolean matrix.
         static const uint16 Br[   745]       ; // Boolean matrix row.
         static const uint8  Bc[   110]       ; // Boolean matrix column.
         static const uint8 Bf[   110]       ; // Boolean matrix filter/mask.
         static const int16  Tm[  1526]       ; // Terminal transition matrix.
         static const uint16 Tr[   745]       ; // Terminal transition matrix row.
         static const uint8  Tc[   110]       ; // Terminal transition matrix column.
         static const int16  Nm[ 20133]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   745]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   733]       ; // Nonterminal transition matrix column.
         static const uint16 Rm[  4063]       ; // Reduction matrix.
         static const int16  Rr[   745]       ; // Reduction matrix row.
         static const uint8  Rc[   110]       ; // Reduction matrix column.
         static const int8   PL[   733]       ; // Production length minus one.

         static const int8   tact_numb[   110]; // Terminal action numbers.
         static const int8   node_numb[   733]; // Node numbers for the productions.
         static const int8   nact_numb[   733]; // Node action numbers for the productions.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
         static int    (*nact_func[    1]) (void* v); // Node action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

