
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    YACC_ParserTables.hpp (generated by LRSTAR 24.0.017)

      #include "lrstar_basic_defs.h"
      #include "lrstar_parser_tables.h"
      #include "YACC_ParserTables.h"
      #include "YACC_Actions.h"

      static int n_terms      =   27; // Number of terminals.
      static int n_heads      =   17; // Number of nonterminals.
      static int n_prods      =   59; // Number of productions.
      static int n_states     =   43; // Number of states.
      static int accept_state =   42; // Accept state.
      static int n_termactns  =    0; // Number of terminal actions.
      static int n_nodenames  =    0; // Number of node names.
      static int n_nodeactns  =    0; // Number of node actions.
      static int eof_symb     =    1; // <eof> symbol number.
      static int err_used     =    0; // <error> used in grammar?

   // Terminal symbols of the grammar ...
      const char* lrstar_parser_tables::term_symb[27] = 
      {
         "<error>",
         "<eof>",
         "\'pp\'",
         "\'error\'",
         "\'pstart\'",
         "\'id\'",
         "\'lcurl\'",
         "\'rcurl\'",
         "\'ptoken\'",
         "\'pleft\'",
         "\'pright\'",
         "\'pnonassoc\'",
         "\'ptype\'",
         "\'langle\'",
         "\'rangle\'",
         "\'comma\'",
         "\'literal\'",
         "\'litid\'",
         "\'number\'",
         "\'c_id\'",
         "\'colon\'",
         "\'bar\'",
         "\'lbrace\'",
         "\'rbrace\'",
         "\'eq\'",
         "\'pprec\'",
         "\'semicolon\'"
      };

   // Nonterminal symbols of the grammar ...
      const char *lrstar_parser_tables::head_symb[17] = 
      {
         "start",
         "grammar",
         "aux_procs",
         "defs",
         "def",
         "tag",
         "token_list",
         "token_num",
         "nonterm_list",
         "nonterm",
         "rules",
         "rule1",
         "rule",
         "body",
         "action",
         "prec",
         "opt_action"
      };

   // Head symbol numbers for the productions ...
      const uint8 lrstar_parser_tables::head_numb[59] = 
      {
          0,    1,    2,    2,    3,    3,    3,    4,    4,    4,    4,    4,    4,    4,    4,    4,    5,    5,    6,    6,
          6,    6,    6,    6,    7,    7,    7,    7,    7,    8,    8,    8,    8,    8,    8,    9,   10,   10,   10,   10,
         10,   11,   12,   12,   13,   13,   13,   13,   13,   13,   14,   14,   15,   15,   15,   15,   15,   16,   16
      };

   // First tail symbol index into the tail list ...
      const uint8 lrstar_parser_tables::f_tail[60] = 
      {
          0,    2,    6,    6,    7,    7,    9,   11,   13,   15,   17,   20,   23,   26,   29,   32,   34,   34,   37,   38,
         40,   43,   44,   46,   49,   50,   51,   52,   54,   56,   57,   59,   62,   63,   65,   68,   69,   69,   72,   74,
         75,   77,   81,   82,   85,   85,   87,   89,   91,   93,   95,   97,   98,   98,  101,  104,  107,  109,  109,  110
      };

   // Tail symbol numbers ...
      const int8 lrstar_parser_tables::tail[110] = 
      {
         -1,    1,   -3,    2,  -10,   -2,    2,   -3,   -4,   -3,    3,    4,    5,    4,    3,    6,    7,    8,   -5,   -6,
          9,   -5,   -6,   10,   -5,   -6,   11,   -5,   -6,   12,   -5,   -8,   12,   -5,   13,    5,   14,   -7,   -6,   -7,
         -6,   15,   -7,    3,   -6,    3,   -6,   15,    3,   16,   17,    5,   17,   18,    5,   18,   -9,   -8,   -9,   -8,
         15,   -9,    3,   -8,    3,   -8,   15,    3,    5,    6,    7,  -11,  -10,  -12,    3,  -10,    3,   19,   20,  -13,
        -15,  -11,   21,  -13,  -15,  -13,   16,  -13,   17,  -13,    5,  -13,  -14,  -13,    3,   22,   23,   24,   25,   16,
        -16,   25,   17,  -16,   25,    5,  -16,  -15,   26,  -14
      };

   // Boolean matrix ...
      const uint8 lrstar_parser_tables::Bm[44] = 
      {
          0,    0,    0,    2,    0,    0,   92,    0,    0,   72,    0,    0,   40,    0,  128,    0,    0,    1,    0,   12,
        160,    0,   40,    8,   32,    0,   64,    0,   32,    0,   40,   12,    0,   16,    0,   40,    4,    0,   40,    8,
          5,   32,    8,    0
      };

   // Boolean matrix row (for state)...
      const uint8 lrstar_parser_tables::Br[43] = 
      {
          0,    3,    6,    9,   12,   14,   16,   16,   16,   16,   16,   19,   14,   22,   24,   22,   22,   22,   12,   25,
          0,   27,   30,   32,   32,    2,   30,   30,   30,   35,    0,   38,   22,   12,   38,    7,   41,    1,    7,   15,
         15,   15,    0
      };

   // Boolean matrix column (displacement) ...
      const uint8 lrstar_parser_tables::Bc[27] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,
          1,    1,    2,    2,    2,    2,    2
      };

   // Boolean matrix filter/mask value ...
      const uint8 lrstar_parser_tables::Bf[27] = 
      {
          1,    2,    4,    8,   16,   32,   64,  128,   16,   16,   16,   16,   16,    1,    2,    4,    8,    8,   16,   32,
         64,  128,    1,    2,    1,    4,    8
      };

   // Terminal transition matrix ...
      const int8 lrstar_parser_tables::Tm[86] = 
      {
         -8,  -32,  -34,  -33,    0,    0,    0,    0,    0,  -40,  -21,    0,   33,    0,    0,   -7,  -35,  -35,  -35,   -3,
        -24,   23,   19,  -23,   20,   24,  -22,    0,    0,    0,    0,    0,    0,  -24,   23,   32,  -24,   23,   24,  -39,
         21,   24,    0,    0,    0,  -49,    0,    0,    0,   39,   40,  -28,    0,    0,   41,  -45,  -46,    0,   12,    0,
        -47,   37,    0,  -51,   36,   -6,   -9,    6,    7,    8,    9,   10,   14,  -17,   42,    3,    4,  -27,   19,   30,
         25,   37,  -50,  -51,    5,  -56
      };

   // Terminal transition matrix row ...
      const uint8 lrstar_parser_tables::Tr[43] = 
      {
         65,   65,   65,   39,    0,   65,   65,   65,   65,   65,   65,    9,   39,   10,   65,   10,   10,   10,    1,   65,
         65,   65,   26,   65,   39,   65,   26,   26,   26,    3,   65,   45,   23,    2,   45,   65,   39,   65,   65,   65,
         65,   65,   65
      };

   // Terminal transition matrix column ...
      const uint8 lrstar_parser_tables::Tc[27] = 
      {
          9,    9,   10,    0,   11,   15,   19,    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
         14,   15,   16,   17,   18,   19,   20
      };

   // Nonterminal transition matrix ...
      const int8 lrstar_parser_tables::Nm[48] = 
      {
          0,    0,    0,    0,   18,  -20,  -19,   17,   28,  -18,   16,   27,  -18,  -58,  -31,  -55,  -58,    0,  -54,  -58,
          0,  -53,   15,   26,  -18,    0,  -30,    0,  -37,    0,   34,  -48,   38,   -1,    2,   -5,   13,   22,  -18,   29,
        -29,   11,  -42,  -38,   31,  -48,   35,    1
      };

   // Nonterminal transition matrix row ...
      const uint8 lrstar_parser_tables::Nr[43] = 
      {
         33,   33,   33,   33,   33,   33,   33,   19,    7,    4,    1,   33,   33,   33,   33,   19,    7,    4,   33,   33,
         33,   19,    1,   33,   33,   33,    1,    1,    1,   19,   19,   33,    0,    7,   19,   33,   33,   33,   33,    7,
          4,    1,   33
      };

   // Nonterminal transition matrix column ...
      const uint8 lrstar_parser_tables::Nc[59] = 
      {
         14,   14,    0,    0,    1,    1,    1,    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,    3,    4,    4,
          4,    4,    4,    4,    5,    5,    5,    5,    5,    6,    6,    6,    6,    6,    6,    7,    8,    8,    8,    8,
          8,    9,   10,   10,   11,   11,   11,   11,   11,   11,   12,   12,   13,   13,   13,   13,   13,   14,   14
      };

   // Reduction matrix ...
      const uint8 lrstar_parser_tables::Rm[1] = 
      {
          0
      };

   // Reduction matrix row ...
      const uint8 lrstar_parser_tables::Rr[43] = 
      {
          4,    0,    0,   36,    0,    0,   16,   16,   16,   16,   16,    2,    0,    0,    0,    0,    0,    0,   15,    0,
         44,    0,   10,   25,   26,    0,   11,   12,   13,   14,   44,   52,    0,    0,   52,   43,    0,    0,   41,   57,
         57,   57,    0
      };

   // Reduction matrix column ...
      const uint8 lrstar_parser_tables::Rc[27] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0
      };

   // Production lengths (minus one) ...
      const int8 lrstar_parser_tables::PL[59] = 
      {
          1,    3,   -1,    0,   -1,    1,    1,    1,    1,    1,    2,    2,    2,    2,    2,    1,   -1,    2,    0,    1,
          2,    0,    1,    2,    0,    0,    0,    1,    1,    0,    1,    2,    0,    1,    2,    0,   -1,    2,    1,    0,
          1,    3,    0,    2,   -1,    1,    1,    1,    1,    1,    1,    0,   -1,    2,    2,    2,    1,   -1,    0
      };

//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "YACC_ParserTables_instantiate.h"
