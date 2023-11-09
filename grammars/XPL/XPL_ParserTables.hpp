
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    XPL_ParserTables.hpp (generated by LRSTAR 24.0.017)

      #include "lrstar_basic_defs.h"
      #include "XPL_ParserTables.h"
      #include "XPL_Actions.h"

      static int n_terms      =   49; // Number of terminals.
      static int n_heads      =   49; // Number of nonterminals.
      static int n_prods      =  109; // Number of productions.
      static int n_states     =   97; // Number of states.
      static int accept_state =   96; // Accept state.
      static int n_termactns  =    2; // Number of terminal actions.
      static int n_nodenames  =    0; // Number of node names.
      static int n_nodeactns  =    0; // Number of node actions.
      static int eof_symb     =    1; // <eof> symbol number.
      static int err_used     =    0; // <error> used in grammar?

   // Terminal symbols of the grammar ...
      const char* lrstar_parser_tables::term_symb[49] = 
      {
         "<error>",
         "<eof>",
         "<identifier>",
         "<string>",
         "<constant>",
         "\';\'",
         "\'IF\'",
         "\'THEN\'",
         "\'ELSE\'",
         "\'DO\'",
         "\'TO\'",
         "\'BY\'",
         "\'WHILE\'",
         "\'CASE\'",
         "\'PROCEDURE\'",
         "\')\'",
         "\'(\'",
         "\',\'",
         "\'END\'",
         "\':\'",
         "\'RETURN\'",
         "\'CALL\'",
         "\'GO\'",
         "\'GOTO\'",
         "\'DECLARE\'",
         "\'LITERALLY\'",
         "\'number\'",
         "\'FIXED\'",
         "\'CHARACTER\'",
         "\'LABEL\'",
         "\'BIT\'",
         "\'INITIAL\'",
         "\'=\'",
         "\'|\'",
         "\'&\'",
         "\'~\'",
         "\'<\'",
         "\'>\'",
         "\'~=\'",
         "\'~<\'",
         "\'~>\'",
         "\'<=\'",
         "\'>=\'",
         "\'||\'",
         "\'+\'",
         "\'-\'",
         "\'*\'",
         "\'/\'",
         "\'MOD\'"
      };

   // Nonterminal symbols of the grammar ...
      const char *lrstar_parser_tables::head_symb[49] = 
      {
         "program",
         "statement_list",
         "statement",
         "basic_statement",
         "if_statement",
         "if_clause",
         "true_part",
         "group",
         "group_head",
         "step_definition",
         "iteration_control",
         "while_clause",
         "case_selector",
         "procedure_definition",
         "procedure_head",
         "procedure_name",
         "parameter_list",
         "parameter_head",
         "ending",
         "label_definition",
         "return_statement",
         "call_statement",
         "go_to_statement",
         "go_to",
         "declaration_statement",
         "declaration_element",
         "type_declaration",
         "type",
         "bit_head",
         "bound_head",
         "identifier_specification",
         "identifier_list",
         "initial_list",
         "initial_head",
         "assignment",
         "replace",
         "left_part",
         "expression",
         "logical_factor",
         "logical_secondary",
         "logical_primary",
         "relation",
         "string_expression",
         "arithmetic_expression",
         "term",
         "primary",
         "constant",
         "variable",
         "subscript_head"
      };

   // Terninal action names found in the grammar ...
      const char *lrstar_parser_tables::tact_name[2] = 
      {
         "error",
         "lookup"
      };

   // Head symbol numbers for the productions ...
      const uint8 lrstar_parser_tables::head_numb[109] = 
      {
          0,    1,    1,    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,    4,    4,    4,    5,    6,    7,
          8,    8,    8,    8,    8,    9,   10,   10,   11,   12,   13,   14,   14,   14,   14,   15,   16,   17,   17,   18,
         18,   18,   19,   20,   20,   21,   22,   23,   23,   24,   24,   25,   25,   26,   26,   26,   27,   27,   27,   27,
         28,   29,   30,   30,   31,   31,   32,   33,   33,   34,   34,   35,   36,   37,   37,   38,   38,   39,   39,   40,
         40,   41,   41,   41,   41,   41,   41,   41,   41,   42,   42,   43,   43,   43,   43,   43,   44,   44,   44,   44,
         45,   45,   45,   46,   46,   47,   47,   48,   48
      };

   // First tail symbol index into the tail list ...
      const uint8 lrstar_parser_tables::f_tail[110] = 
      {
          0,    2,    3,    5,    6,    7,    9,   11,   13,   15,   17,   19,   21,   22,   24,   26,   29,   31,   34,   36,
         38,   40,   43,   46,   49,   51,   55,   57,   61,   63,   65,   68,   70,   73,   76,   80,   82,   85,   86,   89,
         90,   92,   94,   96,   97,   99,  101,  103,  105,  106,  108,  111,  112,  115,  117,  121,  123,  124,  125,  126,
        129,  131,  133,  134,  137,  138,  141,  144,  146,  149,  152,  154,  155,  157,  158,  161,  162,  165,  166,  168,
        169,  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,  184,  185,  188,  191,  193,  195,  196,  199,  202,
        205,  206,  207,  210,  211,  212,  213,  216,  218,  221
      };

   // Tail symbol numbers ...
      const int8 lrstar_parser_tables::tail[221] = 
      {
         -1,    1,   -2,   -1,   -2,   -3,   -4,  -34,    5,   -7,    5,  -13,    5,  -20,    5,  -21,    5,  -22,    5,  -24,
          5,    5,  -19,   -3,   -5,   -2,   -5,   -6,   -2,  -19,   -4,    6,  -37,    7,   -3,    8,   -8,  -18,    9,    5,
          9,   -9,    5,    9,  -11,    5,    9,  -12,    5,   -8,   -2,  -47,  -35,  -37,  -10,   10,  -37,   10,  -37,   11,
        -37,   12,  -37,   13,  -37,  -14,   -1,  -18,  -15,    5,  -15,  -27,    5,  -15,  -16,    5,  -15,  -16,  -27,    5,
        -19,   14,  -17,    2,   15,   16,  -17,    2,   17,   18,   18,    2,  -19,  -18,    2,   19,   20,   20,  -37,   21,
        -47,  -23,    2,   22,   10,   23,   24,  -25,  -24,   17,  -25,  -26,    2,   25,    3,  -30,  -27,  -29,   26,   15,
        -27,  -26,  -32,   27,   28,   29,  -28,   26,   15,   30,   16,  -30,   16,    2,  -31,    2,   15,   16,  -31,    2,
         17,  -33,  -46,   15,   31,   16,  -33,  -46,   17,  -47,  -35,  -37,  -36,  -34,   32,  -47,   17,  -38,  -37,   33,
        -38,  -39,  -38,   34,  -39,  -40,   35,  -40,  -42,  -42,  -41,  -42,   32,   36,   37,   38,   39,   40,   41,   42,
        -43,  -42,   43,  -43,  -44,  -43,   44,  -44,  -43,   45,  -44,   44,  -44,   45,  -44,  -45,  -44,   46,  -45,  -44,
         47,  -45,  -44,   48,  -45,  -46,  -47,   16,  -37,   15,    3,    4,    2,  -48,  -37,   15,    2,   16,  -48,  -37,
         17
      };

   // Arguments for token actions ...
      const int8 lrstar_parser_tables::arga[49] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // Boolean matrix ...
      const uint8 lrstar_parser_tables::Bm[118] = 
      {
          0,    0,    0,    0,  100,    0,    0,    0,  102,    0,    0,    0,   32,    0,    0,  128,   64,    0,   28,   64,
          0,   18,    4,    0,    0,    0,  100,    0,    1,    0,   32,   64,   16,    0,  100,   16,    0,    0,   32,  128,
          0,   64,    2,    0,   36,    8,    0,    0,    2,    0,    0,    4,   64,    0,    0,  160,  128,    0,    0,    0,
          1,    0,    0,   64,   12,    0,    0,    0,   16,    0,   64,    0,    0,   28,   64,    0,    0,   28,   64,    0,
         16,  100,   16,    1,    0,    0,    8,    0,   32,    0,   16,    0,    0,   64,    0,   64,   16,  128,    0,  128,
          0,  160,    0,    0,   24,    0,    0,    0,    8,    0,    0,    0,    2,  128,    0,    4,  128,    0
      };

   // Boolean matrix row (for state)...
      const uint8 lrstar_parser_tables::Br[97] = 
      {
          4,    8,   12,   14,   18,   22,   12,   26,   12,    4,   30,   34,   12,   12,   12,   22,   38,    4,   40,   44,
         18,   22,   47,   51,   18,   18,   54,   57,   61,   65,    9,   69,   18,   73,   73,   77,   81,   22,   26,   12,
         84,   88,   22,   69,   51,   59,    4,   12,   91,   12,   12,   18,   18,   13,   10,   94,   22,   84,   49,   97,
         13,   18,   18,   77,   77,   73,   73,   73,   73,   73,   37,    9,    9,   11,   12,  100,   18,   13,   13,  104,
         69,  100,   11,  108,   57,  105,   65,    9,    9,  111,  100,   66,   18,  114,   18,   13,    0
      };

   // Boolean matrix column (displacement) ...
      const uint8 lrstar_parser_tables::Bc[49] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,
          0,    0,    0,    0,    0,    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,    3,    3,    3,    3,    3,
          3,    3,    3,    3,    3,    3,    3,    3,    3
      };

   // Boolean matrix filter/mask value ...
      const uint8 lrstar_parser_tables::Bf[49] = 
      {
          1,    2,    4,    8,   16,   32,   64,  128,    1,   64,    2,    4,    8,    8,   16,   32,   64,  128,    1,    2,
         64,   64,   64,   64,   64,    4,    8,   16,   16,   16,   16,   32,   64,  128,    1,    2,    4,    4,    4,    4,
          4,    4,    4,    8,   16,   16,   32,   32,   32
      };

   // Terminal transition matrix ...
      const int8 lrstar_parser_tables::Tm[144] = 
      {
          0,    0,  -10,  -32,  -21,  -22,  -23,  -34,  -11,    0,   31,    0,  -20,   44,   52,  -46,    0,   -6,    0,  -52,
        -59,  -60,   58,    0,   -7,    0,  -33,  -36,  -64,  -38,   81,    0,   -9,    0,    0,  -66,  -67,  -68,    0,   51,
        -56,  -57,  -58,   43,   75,    0,   -8,    0,    0,   91,  -61,  -40,    0,  -31,    0,    0,  -63,  -37,  -65,    0,
        -56,  -57,  -58,   43,    0,    0,    0,  -56,  -57,  -58,   43,   31, -104,   -5,   92, -103, -106,   32, -108,    0,
          0,    0,    0,    0,    0,    0,   82,    0,    0,    0,    0,    0,  -81,   61,    0,   35,  -82,  -83,  -84,  -85,
        -86,  -87,  -88,   64,   33,   34,   18, -104,  -12,  -47, -103, -102, -107,  -72,  -42,   20,   21,   22,  -48,   23,
         83,   73,  -56,  -57,  -58,   43,   80,  -71,   61,   62,   24,  -17,  -18,   19,   94,   96,  -35,   37,   64,   65,
         66,   67,   68,   69
      };

   // Terminal transition matrix row ...
      const uint8 lrstar_parser_tables::Tr[97] = 
      {
        106,  106,   71,  106,   71,   71,   15,  106,   22,  106,   51,  106,   44,   30,    0,   15,    6,  106,  106,   10,
         71,   71,  106,   22,   71,   71,   71,  106,   71,  106,  106,  106,   71,   71,   71,   71,  106,   51,  106,    1,
        106,   24,   44,   15,   22,  106,  106,    2,  106,    3,    4,   71,   71,  106,  106,   44,   30,   71,  106,  106,
        106,   71,   71,   71,   71,   71,   71,   71,   71,   71,  106,  106,  106,   15,    5,   22,   71,  106,  106,  106,
         30,   51,   44,   15,  106,  106,  106,  106,  106,   71,   30,  106,   71,  106,   71,  106,  106
      };

   // Terminal transition matrix column ...
      const uint8 lrstar_parser_tables::Tc[49] = 
      {
         29,   29,    0,    4,    1,    2,   24,   25,   26,   27,    3,   28,   29,    4,   30,    5,    6,    7,   31,    8,
          9,   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
         29,   30,   31,   32,   33,   34,   35,   36,   37
      };

   // Nonterminal transition matrix ...
      const int8 lrstar_parser_tables::Nm[580] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  -45,    4,  -97, -100, -101,    4,  -98,
       -100, -101,    4,  -99, -100, -101,    4,   47,    0,    0,   49,   50,    0,    0,   48,    4,   71,  -96, -100, -101,
          4,   72,  -96, -100, -101,    4,   87,  -96, -100, -101,    4,   88,  -96, -100, -101,    4,  -54,   40,    0,    0,
          0,    0,    0,  -70,    0,    5,   86,   30,  -96, -100, -101,    4,    0,    0,    0,    0,    3,    4,   85,   29,
         30,  -96, -100, -101,    4,  -78,    0,   28,   29,   30,  -96, -100, -101,    4,  -76,  -77,    0,   28,   29,   30,
        -96, -100, -101,    4,   84,  -75,  -77,    0,   28,   29,   30,  -96, -100, -101,    4,   53,   27,  -75,  -77,    0,
         28,   29,   30,  -96, -100, -101,    4,   59,   27,  -75,  -77,    0,   28,   29,   30,  -96, -100, -101,    4,   60,
         27,  -75,  -77,    0,   28,   29,   30,  -96, -100, -101,    4,   70,   27,  -75,  -77,    0,   28,   29,   30,  -96,
       -100, -101,    4,   77,   27,  -75,  -77,    0,   28,   29,   30,  -96, -100, -101,    4,   78,   27,  -75,  -77,    0,
         28,   29,   30,  -96, -100, -101,    4,   89,   27,  -75,  -77,    0,   28,   29,   30,  -96, -100, -101,    4,   93,
         27,  -75,  -77,    0,   28,   29,   30,  -96, -100, -101,    4,   95,   27,  -75,  -77,    0,   28,   29,   30,  -96,
       -100, -101,    4,  -53,   40,    0,    0,    0,    0,    0,    0,    0,    0,   26,   27,  -75,  -77,    0,   28,   29,
         30,  -96, -100, -101,    4,    9,   10,    0,    0,    0,   11,   12,   13,   14,   15,   16,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    2,    0,    5,   17,    6,    7,    0,    0,    0,  -13,  -16,    8,    0,    3,    4,
          9,   10,    0,    0,  -41,   36,   12,   13,   14,   15,   16,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          2,    0,    5,   17,    6,    7,    0,    0,    0,  -13,  -16,    8,    0,    3,    4,    9,   10,    0,    0,    0,
         11,   12,   13,   14,   15,   16,    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,    5,   17,    6,
          7,  -15,    0,    0,   -3,   -4,    8,    0,    3,    4,    9,   10,    0,    0,  -19,   36,   12,   13,   14,   15,
         16,    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,    5,   17,    6,    7,  -24,    0,    0,   -3,
         -4,    8,    0,    3,    4,    9,   10,    0,    0,   38,   11,   12,   13,   14,   15,   16,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    2,    0,    5,   17,    6,    7,   -1,    0,    0,   -3,   -4,    8,    0,    3,    4,
          9,   10,    0,    0,   46,   11,   12,   13,   14,   15,   16,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          2,    0,    5,   17,    6,    7,  -14,    0,    0,   45,   -4,    8,    0,    3,    4,    9,   10,    0,    0,  -30,
         36,   12,   13,   14,   15,   16,    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,    5,   17,    6,
          7,   -2,    0,    0,   -3,   -4,    8,    0,    3,    4,    9,   10,    0,    0,    0,   11,   12,   13,   14,   15,
         16,  -50,   54,   74,   40,   57,   55,   56,    0,    0,    2,   76,    5,   17,    6,    7,   -2,    0,    0,   -3,
         -4,    8,    0,    3,    4,    9,   10,   41,   42,    1,   11,   12,   13,   14,   15,   16,  -49,   54,   39,   40,
         57,   55,   56,  -55,   79,    2,   25,    5,   17,    6,    7,   -1,   63,  -25,   -3,   -4,    8,   90,    3,    4
      };

   // Nonterminal transition matrix row ...
      const uint16 lrstar_parser_tables::Nr[97] = 
      {
        545,  510,  545,  545,  230,   63,  545,  370,  545,  405,  545,  265,  545,  545,  545,  545,  545,  440,  545,   21,
        112,    0,  545,  545,  124,  136,  545,  545,  545,  545,  545,  545,  148,   26,   31,   79,  300,  545,  475,  545,
        545,  510,  545,  545,  510,  545,  335,  545,  510,  545,  545,  160,  172,  545,  545,  230,  545,  545,  545,  545,
        545,  100,   89,   70,   57,   36,   41,    4,    8,   12,  545,  545,  545,  545,  545,  545,  184,  545,  545,  545,
        545,  545,  545,  545,  545,  545,  545,  545,  545,  545,  545,   63,  196,  545,  208,  545,  545
      };

   // Nonterminal transition matrix column ...
      const uint8 lrstar_parser_tables::Nc[109] = 
      {
          4,    4,    4,   26,   26,   29,   29,   29,   29,   29,   29,   29,   29,   29,   30,   30,   30,   23,    4,   24,
         25,   25,   25,   25,   25,   26,   28,   28,   29,   30,   31,    0,    0,    0,    0,    1,    2,    3,    3,    4,
          4,    4,    5,    6,    6,    7,    8,    9,    9,   10,   10,   11,   11,   12,   12,   12,   13,   13,   13,   13,
         14,   15,   16,   16,   17,   17,   18,   19,   19,   20,   20,   21,   22,   23,   23,   24,   24,   25,   25,   26,
         26,   27,   27,   27,   27,   27,   27,   27,   27,   28,   28,   29,   29,   29,   29,   29,   30,   30,   30,   30,
         31,   31,   31,   32,   32,   33,   33,   34,   34
      };

   // Reduction matrix ...
      const uint8 lrstar_parser_tables::Rm[1] = 
      {
          0
      };

   // Reduction matrix row ...
      const uint8 lrstar_parser_tables::Rr[97] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  105,    0,
         43,    0,    0,    0,    0,    0,    0,   73,   79,   89,   91,  105,    0,    0,    0,    0,    0,   39,    0,    0,
          0,    0,    0,    0,    0,    3,    0,    0,    0,    0,    0,    0,    0,   44,   51,    0,    0,    0,   62,    0,
         69,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   94,   95,    0,    0,    0,    0,   28,   29,    0,
          0,    0,    0,    0,   74,   80,   90,   92,   93,    0,    0,    0,    0,   26,    0,   27,    0
      };

   // Reduction matrix column ...
      const uint8 lrstar_parser_tables::Rc[49] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0
      };

   // Production lengths (minus one) ...
      const uint8 lrstar_parser_tables::PL[109] = 
      {
          1,    0,    1,    0,    0,    1,    1,    1,    1,    1,    1,    1,    0,    1,    1,    2,    1,    2,    1,    1,
          1,    2,    2,    2,    1,    3,    1,    3,    1,    1,    2,    1,    2,    2,    3,    1,    2,    0,    2,    0,
          1,    1,    1,    0,    1,    1,    1,    1,    0,    1,    2,    0,    2,    1,    3,    1,    0,    0,    0,    2,
          1,    1,    0,    2,    0,    2,    2,    1,    2,    2,    1,    0,    1,    0,    2,    0,    2,    0,    1,    0,
          2,    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,    2,    2,    1,    1,    0,    2,    2,    2,
          0,    0,    2,    0,    0,    0,    2,    1,    2
      };

   // Terminal action number ...
      const int8 lrstar_parser_tables::tact_numb[49] = 
      {
          0,   -1,    1,    1,    1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
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

//
////////////////////////////////////////////////////////////////////////////////////////////////////

