
////////////////////////////////////////////////////////////////////////////////
//
//    NCSA_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "NCSA"
      #define PARSER        NCSA_Parser
      #define PARSER_TABLES NCSA_ParserTables
      #define LEXER         NCSA_Lexer
      #define ACTIONS       NCSA_Actions
      #define TERM_ACTIONS  NCSA_TermActions
      #define NODE_ACTIONS  NCSA_NodeActions
      #define LOOKAHEADS    1
      #define MAKE_AST
      #define EXPECTING
      #define SEMANTICS

      enum nodecon
      {
         N_Report = 0,
         N_Day = 1,
         N_Client = 2,
         N_FullName = 3,
         N_Name = 4,
         N_Time = 5,
         N_File = 6,
         N_Code = 7,
         N_Size = 8,
         N_Source = 9,
         N_Query = 10
      };


      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class NCSA_ParserTables
      {
         friend class NCSA_Parser;
         public:
         static const char *term_symb[    24]; // Terminal symbols of the grammar.
         static const char *head_symb[    25]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const char *node_name[    11]; // Node names found in the grammar.
         static uchar  head_numb[    62]; // Head symbol number for a production.
         static uchar  f_tail   [    63]; // First tail in a production.
         static char   tail     [   114]; // Tail symbol number.
         static char   arga     [    24]; // Arguments for terminal actions.
         static char   argx     [    62]; // First arguments for productions.
         static char   argy     [    62]; // Second arguments for productions.

         private:
         static uchar  Bm[    57]       ; // Boolean matrix.
         static uchar  Br[    38]       ; // Boolean matrix row.
         static uchar  Bc[    24]       ; // Boolean matrix column.
         static uchar  Bf[    24]       ; // Boolean matrix filter/mask.
         static char   Tm[    99]       ; // Terminal transition matrix.
         static uchar  Tr[    38]       ; // Terminal transition matrix row.
         static uchar  Tc[    24]       ; // Terminal transition matrix column.
         static char   Nm[    72]       ; // Nonterminal transition matrix.
         static uchar  Nr[    38]       ; // Nonterminal transition matrix row.
         static uchar  Nc[    62]       ; // Nonterminal transition matrix column.
         static uchar  Rm[     6]       ; // Reduction matrix.
         static char   Rr[    38]       ; // Reduction matrix row.
         static uchar  Rc[    24]       ; // Reduction matrix column.
         static uchar  PL[    62]       ; // Production length minus one.

         static char   tact_numb[    24]; // Terminal action numbers.
         static char   node_numb[    62]; // Node numbers for the productions.
         static char   nact_numb[    62]; // Node action numbers for the productions.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
         static int    (*nact_func[   11]) (void* v); // Node action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

