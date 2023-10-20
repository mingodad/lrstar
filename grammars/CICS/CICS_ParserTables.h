
////////////////////////////////////////////////////////////////////////////////
//
//    CICS_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "CICS"
      #define PARSER        CICS_Parser
      #define PARSER_TABLES CICS_ParserTables
      #define LEXER         CICS_Lexer
      #define ACTIONS       CICS_Actions
      #define TERM_ACTIONS  CICS_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING

      typedef unsigned int   uint;
      typedef unsigned char  uchar;
      typedef unsigned short ushort;

      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class CICS_ParserTables
      {
         friend class CICS_Parser;
         public:
         static char*  term_symb[   216]; // Terminal symbols of the grammar.
         static char*  head_symb[   369]; // Nonterminal symbols of the grammar.
         static char*  tact_name[     2]; // Terminal action names found in the grammar.
         static ushort head_numb[   821]; // Head symbol number for a production.
         static ushort f_tail   [   822]; // First tail in a production.
         static short  tail     [  1488]; // Tail symbol number.
         static char   arga     [   216]; // Arguments for terminal actions.

         private:
         static uchar  Bm[   310]       ; // Boolean matrix.
         static ushort Br[   668]       ; // Boolean matrix row.
         static uchar  Bc[   216]       ; // Boolean matrix column.
         static uchar  Bf[   216]       ; // Boolean matrix filter/mask.
         static short  Tm[  1304]       ; // Terminal transition matrix.
         static ushort Tr[   668]       ; // Terminal transition matrix row.
         static uchar  Tc[   216]       ; // Terminal transition matrix column.
         static short  Nm[   733]       ; // Nonterminal transition matrix.
         static ushort Nr[   668]       ; // Nonterminal transition matrix row.
         static ushort Nc[   821]       ; // Nonterminal transition matrix column.
         static uchar  Rm[     1]       ; // Reduction matrix.
         static ushort Rr[   668]       ; // Reduction matrix row.
         static uchar  Rc[   216]       ; // Reduction matrix column.
         static char   PL[   821]       ; // Production length minus one.

         static char   tact_numb[   216]; // Terminal action numbers.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

