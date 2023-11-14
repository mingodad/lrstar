
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    LRK_ParserTables.hpp (generated by LRSTAR 24.0.017)

      #include "lrstar_basic_defs.h"
      #include "lrstar_parser_tables.h"
      #include "LRK_ParserTables.h"
      #include "LRK_Actions.h"

      static int n_terms      =   19; // Number of terminals.
      static int n_heads      =   16; // Number of nonterminals.
      static int n_prods      =   31; // Number of productions.
      static int n_states     =   23; // Number of states.
      static int accept_state =   22; // Accept state.
      static int n_termactns  =    2; // Number of terminal actions.
      static int n_nodenames  =    8; // Number of node names.
      static int n_nodeactns  =    8; // Number of node actions.
      static int eof_symb     =    1; // <eof> symbol number.
      static int err_used     =    0; // <error> used in grammar?

   // Terminal symbols of the grammar ...
      const char* lrstar_parser_tables::term_symb[19] = 
      {
         "<error>",
         "<eof>",
         "<identifier>",
         "\'typedef\'",
         "\';\'",
         "{typename}",
         "\'(\'",
         "\',\'",
         "\')\'",
         "\'{\'",
         "\'}\'",
         "\'int\'",
         "\'char\'",
         "\'long\'",
         "\'short\'",
         "\'unsigned\'",
         "\'*\'",
         "{function_name}",
         "\'...\'"
      };

   // Nonterminal symbols of the grammar ...
      const char *lrstar_parser_tables::head_symb[16] = 
      {
         "Goal",
         "TypedefDecl",
         "TypeIdent",
         "FunctionDecl",
         "FunctionDef",
         "TypeSpec",
         "FuncDecl",
         "FuncDef",
         "Arg",
         "ArgName",
         "FunctionName",
         "FuncBody",
         "(FunctionDecl | FunctionDef | TypedefDecl)",
         "(FunctionDecl | FunctionDef | TypedefDecl)+",
         "TypeSpec+",
         "Arg/','*"
      };

   // Terninal action names found in the grammar ...
      const char *lrstar_parser_tables::tact_name[2] = 
      {
         "error",
         "lookup"
      };

   // Node names found in the grammar ...
      const char * lrstar_parser_tables::node_name[8] = 
      {
         "goal_",
         "function_decl_",
         "function_def_",
         "type_spec_",
         "function_",
         "arg_",
         "arg_name_",
         "function_body_"
      };

   // Head symbol numbers for the productions ...
      const uint8 lrstar_parser_tables::head_numb[31] = 
      {
          0,    1,    2,    3,    4,    5,    5,    5,    5,    5,    5,    5,    6,    6,    7,    7,    8,    9,   10,   11,
         11,   12,   12,   12,   13,   13,   14,   14,   15,   15,   15
      };

   // First tail symbol index into the tail list ...
      const uint8 lrstar_parser_tables::f_tail[32] = 
      {
          0,    2,    6,    7,   13,   21,   22,   23,   24,   25,   26,   27,   29,   30,   31,   32,   33,   35,   36,   37,
         37,   38,   39,   40,   41,   42,   44,   45,   47,   47,   48,   51
      };

   // Tail symbol numbers ...
      const int8 lrstar_parser_tables::tail[51] = 
      {
        -13,    1,    3,  -14,   -2,    4,    2,   -5,   -6,    6,  -15,    8,    4,   -5,   -7,    6,  -15,    8,    9,  -11,
         10,   11,   12,   13,   14,   15,    5,   -5,   16,  -10,   17,  -10,   17,   -5,   -9,    2,    2,   18,   -3,   -4,
         -1,  -12,  -13,  -12,   -5,  -14,   -5,   -8,  -15,    7,   -8
      };

   // Arguments for token actions ...
      const int8 lrstar_parser_tables::arga[19] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // First arguments for productions ...
      int8 lrstar_parser_tables::argx[31] = 
      {
         -1,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // Second arguments for productions ...
      int8 lrstar_parser_tables::argy[31] = 
      {
         -1,   -1,    5,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   17,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // Boolean matrix ...
      const uint8 lrstar_parser_tables::Bm[22] = 
      {
          0,    0,   40,    0,   42,    0,    4,   12,   32,   64,    0,   36,    0,   16,  128,    0,    4,    4,    0,    1,
          0,    2
      };

   // Boolean matrix row (for state)...
      const uint8 lrstar_parser_tables::Br[23] = 
      {
          2,    4,    6,    8,    9,    0,    9,    0,   11,    5,    8,    8,   13,    5,   14,   16,   14,   13,    8,   18,
         12,   20,    0
      };

   // Boolean matrix column (displacement) ...
      const uint8 lrstar_parser_tables::Bc[19] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1
      };

   // Boolean matrix filter/mask value ...
      const uint8 lrstar_parser_tables::Bf[19] = 
      {
          1,    2,    4,    8,   16,   32,   64,  128,  128,    1,    2,   32,   32,   32,   32,   32,    4,    8,   16
      };

   // Terminal transition matrix ...
      const int8 lrstar_parser_tables::Tm[39] = 
      {
          0,  -17,    0,    0,    0,    0,    0,   -2,    0,   -3,  -10,   11,   18,   19,    0,  -11,   -5,   -6,   -7,   -8,
         -9,   22,  -18,    3,   -1,  -10,   10,   18,   17,   20,   -4,   -5,   -6,   -7,   -8,   -9,  -11,    7,  -20
      };

   // Terminal transition matrix row ...
      const uint8 lrstar_parser_tables::Tr[23] = 
      {
         21,   21,   21,   21,   21,   21,    6,   21,    6,   21,   21,   21,   21,   21,   21,    0,    6,    6,   21,   21,
         21,   21,   21
      };

   // Terminal transition matrix column ...
      const uint8 lrstar_parser_tables::Tc[19] = 
      {
          0,    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,   17
      };

   // Nonterminal transition matrix ...
      const int8 lrstar_parser_tables::Nm[33] = 
      {
          9,   13,   15,   15,   12,  -30,  -29,   15,    0,    8,  -29,    2,    0,   14,  -23,    0,    0,   16,  -25,    0,
        -21,  -22,    2,    4,    6,  -23,  -16,    5,   21,  -24,    1,  -21,  -22
      };

   // Nonterminal transition matrix row ...
      const uint8 lrstar_parser_tables::Nr[23] = 
      {
         22,   11,   22,    0,   22,   22,   22,   22,    1,   22,    3,    7,   22,   22,   22,   22,   22,   22,    2,   22,
         22,   22,   22
      };

   // Nonterminal transition matrix column ...
      const uint8 lrstar_parser_tables::Nc[31] = 
      {
          3,    3,    3,    9,   10,    0,    0,    0,    0,    0,    0,    0,    1,    1,    2,    2,    3,    4,    5,    6,
          6,    7,    7,    7,    8,    8,    9,    9,   10,   10,   10
      };

   // Reduction matrix ...
      const uint8 lrstar_parser_tables::Rm[1] = 
      {
          0
      };

   // Reduction matrix row ...
      const uint8 lrstar_parser_tables::Rr[23] = 
      {
          0,    0,    0,    0,    0,   12,    0,   13,    0,   26,   28,   28,    0,   27,    0,    0,    0,    0,    0,    0,
         19,    0,    0
      };

   // Reduction matrix column ...
      const uint8 lrstar_parser_tables::Rc[19] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
      };

   // Production lengths (minus one) ...
      const int8 lrstar_parser_tables::PL[31] = 
      {
          1,    3,    0,    5,    7,    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    1,    0,    0,   -1,
          0,    0,    0,    0,    0,    1,    0,    1,   -1,    0,    2
      };

   // Terminal action number ...
      const int8 lrstar_parser_tables::tact_numb[19] = 
      {
          0,   -1,    1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // Node number for each production ...
      const int8 lrstar_parser_tables::node_numb[31] = 
      {
          0,   -1,   -1,    1,    2,    3,    3,    3,    3,    3,    3,    3,    4,    4,    4,    4,    5,    6,   -1,   -1,
          7,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // Node action numbers ...
      const int8 lrstar_parser_tables::nact_numb[31] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "LRK_ParserTables_instantiate.h"
