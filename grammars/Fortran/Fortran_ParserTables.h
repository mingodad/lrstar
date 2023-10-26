
////////////////////////////////////////////////////////////////////////////////
//
//    Fortran_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "Fortran"
      #define PARSER        Fortran_Parser
      #define PARSER_TABLES Fortran_ParserTables
      #define LEXER         Fortran_Lexer
      #define ACTIONS       Fortran_Actions
      #define TERM_ACTIONS  Fortran_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING


      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class Fortran_ParserTables
      {
         friend class Fortran_Parser;
         public:
         static const char *term_symb[   268]; // Terminal symbols of the grammar.
         static const char *head_symb[   572]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static ushort head_numb[  1133]; // Head symbol number for a production.
         static ushort f_tail   [  1134]; // First tail in a production.
         static short  tail     [  1911]; // Tail symbol number.
         static char   arga     [   268]; // Arguments for terminal actions.

         private:
         static uchar  Bm[   762]       ; // Boolean matrix.
         static ushort Br[   724]       ; // Boolean matrix row.
         static uchar  Bc[   268]       ; // Boolean matrix column.
         static uchar  Bf[   268]       ; // Boolean matrix filter/mask.
         static short  Tm[  1750]       ; // Terminal transition matrix.
         static ushort Tr[   724]       ; // Terminal transition matrix row.
         static uchar  Tc[   268]       ; // Terminal transition matrix column.
         static short  Nm[  3405]       ; // Nonterminal transition matrix.
         static ushort Nr[   724]       ; // Nonterminal transition matrix row.
         static ushort Nc[  1133]       ; // Nonterminal transition matrix column.
         static ushort Rm[   298]       ; // Reduction matrix.
         static short  Rr[   724]       ; // Reduction matrix row.
         static uchar  Rc[   268]       ; // Reduction matrix column.
         static char   PL[  1133]       ; // Production length minus one.

         static char   tact_numb[   268]; // Terminal action numbers.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

