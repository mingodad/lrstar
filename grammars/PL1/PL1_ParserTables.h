
////////////////////////////////////////////////////////////////////////////////
//
//    PL1_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #undef  GRAMMAR
      #undef  PARSER
      #undef  PARSER_TABLES
      #undef  LEXER
      #undef  ACTIONS
      #undef  TERM_ACTIONS
      #undef  NODE_ACTIONS
      #undef  INSENSITIVE
      #undef  LOOKAHEADS
      #undef  DEBUG_PARSER
      #undef  DEBUG_TRACE
      #undef  MAKE_AST
      #undef  EXPECTING
      #undef  REVERSABLE
      #undef  SEMANTICS
      #undef  ND_PARSING
      #undef  ND_THREADS

      #define GRAMMAR      "PL1"
      #define PARSER        PL1_Parser
      #define PARSER_TABLES PL1_ParserTables
      #define LEXER         PL1_Lexer
      #define ACTIONS       PL1_Actions
      #define TERM_ACTIONS  PL1_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING

      typedef unsigned int   uint;
      typedef unsigned char  uchar;
      typedef unsigned short ushort;

      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class PL1_ParserTables
      {
         friend class PL1_Parser;
         public:
         static char*  term_symb[   226]; // Terminal symbols of the grammar.
         static char*  head_symb[   632]; // Nonterminal symbols of the grammar.
         static char*  tact_name[     2]; // Terminal action names found in the grammar.
         static ushort head_numb[  1272]; // Head symbol number for a production.
         static ushort f_tail   [  1273]; // First tail in a production.
         static short  tail     [  2199]; // Tail symbol number.
         static char   arga     [   226]; // Arguments for terminal actions.

         private:
         static uchar  Bm[   668]       ; // Boolean matrix.
         static ushort Br[   860]       ; // Boolean matrix row.
         static uchar  Bc[   226]       ; // Boolean matrix column.
         static uchar  Bf[   226]       ; // Boolean matrix filter/mask.
         static short  Tm[  2354]       ; // Terminal transition matrix.
         static ushort Tr[   860]       ; // Terminal transition matrix row.
         static uchar  Tc[   226]       ; // Terminal transition matrix column.
         static short  Nm[ 12401]       ; // Nonterminal transition matrix.
         static ushort Nr[   860]       ; // Nonterminal transition matrix row.
         static ushort Nc[  1272]       ; // Nonterminal transition matrix column.
         static ushort Rm[   121]       ; // Reduction matrix.
         static short  Rr[   860]       ; // Reduction matrix row.
         static uchar  Rc[   226]       ; // Reduction matrix column.
         static char   PL[  1272]       ; // Production length minus one.

         static char   tact_numb[   226]; // Terminal action numbers.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

