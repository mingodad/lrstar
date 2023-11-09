
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Calc_ParserTables.hpp (generated by LRSTAR 24.0.017)

      #include "lrstar_basic_defs.h"
      #include "Calc_ParserTables.h"
      #include "Calc_Actions.h"

      static int n_terms      =   22; // Number of terminals.
      static int n_heads      =   13; // Number of nonterminals.
      static int n_prods      =   26; // Number of productions.
      static int n_states     =   36; // Number of states.
      static int accept_state =   35; // Accept state.
      static int n_termactns  =    2; // Number of terminal actions.
      static int n_nodenames  =   17; // Number of node names.
      static int n_nodeactns  =   17; // Number of node actions.
      static int eof_symb     =    1; // <eof> symbol number.
      static int err_used     =    0; // <error> used in grammar?

   // Terminal symbols of the grammar ...
      const char* lrstar_parser_tables::term_symb[22] = 
      {
         "<error>",
         "<eof>",
         "<identifier>",
         "<integer>",
         "\'==\'",
         "\'!=\'",
         "\'+\'",
         "\'-\'",
         "\'*\'",
         "\'/\'",
         "\'^\'",
         "\'program\'",
         "\'{\'",
         "\'}\'",
         "\'=\'",
         "\';\'",
         "\'if\'",
         "\'endif\'",
         "\'(\'",
         "\')\'",
         "\'then\'",
         "\'else\'"
      };

   // Nonterminal symbols of the grammar ...
      const char *lrstar_parser_tables::head_symb[13] = 
      {
         "Goal",
         "Program",
         "Stmt",
         "Target",
         "RelExp",
         "Exp",
         "Primary",
         "Then",
         "Then2",
         "Else2",
         "Program*",
         "Stmt*",
         "Stmt+"
      };

   // Terninal action names found in the grammar ...
      const char *lrstar_parser_tables::tact_name[2] = 
      {
         "error",
         "lookup"
      };

   // Node names found in the grammar ...
      const char * lrstar_parser_tables::node_name[17] = 
      {
         "goal_",
         "program_",
         "store_",
         "if_",
         "target_",
         "eq_",
         "ne_",
         "add_",
         "sub_",
         "mul_",
         "div_",
         "pwr_",
         "int_",
         "ident_",
         "then_",
         "then2_",
         "else2_"
      };

   // Head symbol numbers for the productions ...
      const uint8 lrstar_parser_tables::head_numb[26] = 
      {
          0,    1,    2,    2,    2,    3,    4,    4,    5,    5,    5,    5,    5,    5,    6,    6,    6,    7,    8,    9,
         10,   10,   11,   11,   12,   12
      };

   // First tail symbol index into the tail list ...
      const uint8 lrstar_parser_tables::f_tail[27] = 
      {
          0,    2,    7,   11,   15,   20,   21,   24,   27,   28,   31,   34,   37,   40,   43,   44,   45,   48,   50,   52,
         54,   54,   56,   56,   58,   59,   61
      };

   // Tail symbol numbers ...
      const int8 lrstar_parser_tables::tail[61] = 
      {
        -10,    1,   11,    2,   12,  -11,   13,   -3,   14,   -5,   15,   16,   -4,   -7,   17,   16,   -4,   -8,   -9,   17,
          2,   -5,    4,   -5,   -5,    5,   -5,   -6,   -5,    6,   -5,   -5,    7,   -5,   -5,    8,   -5,   -5,    9,   -5,
         -5,   10,   -5,    3,    2,   18,   -5,   19,   20,  -12,   20,  -12,   21,  -12,  -10,   -1,  -11,   -2,   -2,  -12,
         -2
      };

   // Arguments for token actions ...
      const int8 lrstar_parser_tables::arga[22] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1
      };

   // First arguments for productions ...
      int8 lrstar_parser_tables::argx[26] = 
      {
         -1,    1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,    0,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1
      };

   // Boolean matrix ...
      const uint8 lrstar_parser_tables::Bm[30] = 
      {
          0,    0,    2,    0,    4,    0,    0,    1,    4,   18,   12,    0,  128,  240,    0,  224,    8,    0,   32,    4,
         16,  224,   64,  224,    0,  192,    0,  128,    0,    0
      };

   // Boolean matrix row (for state)...
      const uint8 lrstar_parser_tables::Br[36] = 
      {
          0,    2,    4,    6,    0,    8,    3,   10,   10,   11,   13,   10,   15,   17,    5,   19,   10,   10,   10,   10,
         10,   10,   10,   21,   17,   19,   19,   23,   23,   25,   25,   27,   27,   27,   19,    0
      };

   // Boolean matrix column (displacement) ...
      const uint8 lrstar_parser_tables::Bc[22] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,    0,    1,
          1,    2
      };

   // Boolean matrix filter/mask value ...
      const uint8 lrstar_parser_tables::Bf[22] = 
      {
          1,    2,    4,    8,   16,   16,   32,   32,   64,   64,  128,    2,    1,    2,    4,    8,   16,   32,    8,   64,
        128,    1
      };

   // Terminal transition matrix ...
      const int8 lrstar_parser_tables::Tm[33] = 
      {
        -15,    0,    0,   -5,    0,    0,    0,    0,  -14,    0,    0,   -1,    0,   11,    7,   -4,    3,   18,   19,   20,
         21,   22,    2,    4,   35,    8,   -2,   16,   -3,   17,  -16,   15,   25
      };

   // Terminal transition matrix row ...
      const uint8 lrstar_parser_tables::Tr[36] = 
      {
         16,   16,   16,   16,   16,    3,   16,    0,    0,   16,   16,    0,   16,   16,   16,    3,    0,    0,    0,    0,
          0,    0,    0,   16,    3,    3,    3,   16,   16,   16,   16,   16,   16,   16,    3,   16
      };

   // Terminal transition matrix column ...
      const uint8 lrstar_parser_tables::Tc[22] = 
      {
          8,    8,    0,    8,   11,   13,    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
         15,   16
      };

   // Nonterminal transition matrix ...
      const int8 lrstar_parser_tables::Nm[47] = 
      {
          0,    0,    0,   28,   -8,   29,   -8,   30,   -8,   31,   -8,   32,   -8,   33,   -8,  -25,    6,    0,   27,   -8,
        -24,    6,    0,   12,   -8,  -24,    6,    0,   23,   -8,   26,    0,    0,    0,    0,   34,  -23,    6,    9,   10,
         -8,   13,   14,   24,    1,    5,  -21
      };

   // Nonterminal transition matrix row ...
      const uint8 lrstar_parser_tables::Nr[36] = 
      {
         36,   36,   36,   36,   36,   36,   36,   36,   20,   36,   36,   25,   36,   36,   36,   20,   15,    0,    2,    4,
          6,    8,   10,   36,   36,   25,   15,   36,   36,   36,   36,   36,   36,   36,   15,   36
      };

   // Nonterminal transition matrix column ...
      const uint8 lrstar_parser_tables::Nc[26] = 
      {
         10,   10,    0,    0,    0,    1,    2,    2,    3,    3,    3,    3,    3,    3,    4,    4,    4,    5,    6,    7,
          8,    8,    9,    9,   10,   10
      };

   // Reduction matrix ...
      const uint8 lrstar_parser_tables::Rm[5] = 
      {
          0,    0,    0,   17,   18
      };

   // Reduction matrix row ...
      const int8 lrstar_parser_tables::Rr[36] = 
      {
         20,    0,    0,    0,   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,   -2,    6,    7,    9,   10,   11,   12,   13,   19,    0
      };

   // Reduction matrix column ...
      const uint8 lrstar_parser_tables::Rc[22] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
          0,    2
      };

   // Production lengths (minus one) ...
      const int8 lrstar_parser_tables::PL[26] = 
      {
          1,    4,    3,    3,    4,    0,    2,    2,    0,    2,    2,    2,    2,    2,    0,    0,    2,    1,    1,    1,
         -1,    1,   -1,    1,    0,    1
      };

   // Terminal action number ...
      const int8 lrstar_parser_tables::tact_numb[22] = 
      {
          0,   -1,    1,    1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1
      };

   // Node number for each production ...
      const int8 lrstar_parser_tables::node_numb[26] = 
      {
          0,    1,    2,    3,    3,    4,    5,    6,   -1,    7,    8,    9,   10,   11,   12,   13,   -1,   14,   15,   16,
         -1,   -1,   -1,   -1,   -1,   -1
      };

   // Node action numbers ...
      const int8 lrstar_parser_tables::nact_numb[26] = 
      {
          0,    1,    2,    3,    3,    4,    5,    6,   -1,    7,    8,    9,   10,   11,   12,   13,   -1,   14,   15,   16,
         -1,   -1,   -1,   -1,   -1,   -1
      };

   // Reverse the order of nodes ...
      const uint8 lrstar_parser_tables::reverse[26] = 
      {
          0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0
      };

   // Init action function pointers ...
      void (*lrstar_parser_tables::init_func[2]) () =
      {
         lrstar_parser_actions::init_actions,
         lrstar_parser_actions::term_actions
      };

   // Terminal action function pointers ...
      int (*lrstar_parser_tables::tact_func[2]) (int& t) =
      {
         lrstar_term_actions::error,
         lrstar_term_actions::lookup
      };

   // Node action function pointers ...
      int (*lrstar_parser_tables::nact_func[17]) (void* v) = 
      {
         lrstar_node_actions::goal_,
         lrstar_node_actions::program_,
         lrstar_node_actions::store_,
         lrstar_node_actions::if_,
         lrstar_node_actions::target_,
         lrstar_node_actions::eq_,
         lrstar_node_actions::ne_,
         lrstar_node_actions::add_,
         lrstar_node_actions::sub_,
         lrstar_node_actions::mul_,
         lrstar_node_actions::div_,
         lrstar_node_actions::pwr_,
         lrstar_node_actions::int_,
         lrstar_node_actions::ident_,
         lrstar_node_actions::then_,
         lrstar_node_actions::then2_,
         lrstar_node_actions::else2_
      };

//
////////////////////////////////////////////////////////////////////////////////////////////////////

