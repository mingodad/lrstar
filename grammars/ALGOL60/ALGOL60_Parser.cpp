#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "ALGOL60_LexerTables_typedef.h"
#include "ALGOL60_ParserTables_typedef.h"
#include "ALGOL60_Parser.h"

template<>
const int ALGOL60_parser_tables_t::n_term_symb = 57;

template<>
const int ALGOL60_parser_tables_t::n_head_symb = 77;

template<>
const int ALGOL60_parser_tables_t::n_tact_name = 0;

template<>
const int ALGOL60_parser_tables_t::n_node_name = 0;

template<>
const int ALGOL60_parser_tables_t::n_head_numb = 169;

template<>
const int ALGOL60_parser_tables_t::n_f_tail = 170;

template<>
const int ALGOL60_parser_tables_t::n_tail = 317;

template<>
const int ALGOL60_parser_tables_t::n_arga = 0;

template<>
const int ALGOL60_parser_tables_t::n_argx = 0;

template<>
const int ALGOL60_parser_tables_t::n_argy = 0;

template<>
const int ALGOL60_parser_tables_t::n_Bm = 159;

template<>
const int ALGOL60_parser_tables_t::n_Br = 148;

template<>
const int ALGOL60_parser_tables_t::n_Bc = 57;

template<>
const int ALGOL60_parser_tables_t::n_Bf = 57;

template<>
const int ALGOL60_parser_tables_t::n_Tm = 601;

template<>
const int ALGOL60_parser_tables_t::n_Tr = 148;

template<>
const int ALGOL60_parser_tables_t::n_Tc = 57;

template<>
const int ALGOL60_parser_tables_t::n_Nm = 531;

template<>
const int ALGOL60_parser_tables_t::n_Nr = 148;

template<>
const int ALGOL60_parser_tables_t::n_Nc = 169;

template<>
const int ALGOL60_parser_tables_t::n_Rm = 36;

template<>
const int ALGOL60_parser_tables_t::n_Rr = 148;

template<>
const int ALGOL60_parser_tables_t::n_Rc = 57;

template<>
const int ALGOL60_parser_tables_t::n_PL = 169;

template<>
const int ALGOL60_parser_tables_t::n_nd_fterm = 0;

template<>
const int ALGOL60_parser_tables_t::n_nd_term = 0;

template<>
const int ALGOL60_parser_tables_t::n_nd_faction = 0;

template<>
const int ALGOL60_parser_tables_t::n_nd_action = 0;

template<>
const int ALGOL60_parser_tables_t::n_tact_numb = 0;

template<>
const int ALGOL60_parser_tables_t::n_node_numb = 0;

template<>
const int ALGOL60_parser_tables_t::n_nact_numb = 0;

template<>
const int ALGOL60_parser_tables_t::n_reverse = 0;

template<>
const int ALGOL60_parser_tables_t::n_terms = 57; // Number of terminals.

template<>
const int ALGOL60_parser_tables_t::n_heads = 77; // Number of nonterminals.

template<>
const int ALGOL60_parser_tables_t::n_prods = 169; // Number of productions.

template<>
const int ALGOL60_parser_tables_t::n_states = 148; // Number of states.

template<>
const int ALGOL60_parser_tables_t::accept_state = 147; // Accept state.

template<>
const int ALGOL60_parser_tables_t::n_termactns = 0; // Number of terminal actions.

template<>
const int ALGOL60_parser_tables_t::n_nodenames = 0; // Number of node names.

template<>
const int ALGOL60_parser_tables_t::n_nodeactns = 0; // Number of node actions.

template<>
const int ALGOL60_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int ALGOL60_parser_tables_t::err_used = 0; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[57] = {
   "<error>",
   "<eof>",
   "\'+\'",
   "\'-\'",
   "\'*\'",
   "\'/\'",
   "\'TTRUE\'",
   "\'TFALSE\'",
   "\'NAME\'",
   "\'STRING\'",
   "\'[\'",
   "\']\'",
   "\',\'",
   "\'(\'",
   "\')\'",
   "\'TELSE\'",
   "\'TPOW\'",
   "\'TDIV\'",
   "\'TEQUIV\'",
   "\'TIMPL\'",
   "\'TOR\'",
   "\'TAND\'",
   "\'TNOT\'",
   "\'TLESS\'",
   "\'TNOTGREATER\'",
   "\'TEQUAL\'",
   "\'TNOTLESS\'",
   "\'TGREATER\'",
   "\'TNOTEQUAL\'",
   "\'INUM\'",
   "\';\'",
   "\'TBEGIN\'",
   "\'error\'",
   "\'TEND\'",
   "\'TASSIGN\'",
   "\'TGOTO\'",
   "\'TIF\'",
   "\'TTHEN\'",
   "\'TFOR\'",
   "\'TDO\'",
   "\'TSTEP\'",
   "\'TUNTIL\'",
   "\'TWHILE\'",
   "\':\'",
   "\'TOWN\'",
   "\'TINTEGER\'",
   "\'TREAL\'",
   "\'TBOOL\'",
   "\'TARRAY\'",
   "\'TSWITCH\'",
   "\'TCODE\'",
   "\'TPROC\'",
   "\'TSTRING\'",
   "\'TLABEL\'",
   "\'TVALUE\'",
   "\'RNUM\'",
   "\'TTEN\'",
};

template<>
const char * const *ALGOL60_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[77] = {
   "start",
   "a60program",
   "logical_val",
   "identifier",
   "string",
   "variable",
   "subscr_list",
   "subscr_expr",
   "func_desig",
   "arith_expr",
   "simple_expr",
   "mix_expr",
   "relation",
   "mix_prim",
   "bool_expr",
   "design_expr",
   "simp_dexpr",
   "switch_des",
   "program",
   "block",
   "comp_stmt",
   "unlab_block",
   "unlab_comp",
   "block_head",
   "comp_tail",
   "stmt",
   "uncond_stmt",
   "basic_stmt",
   "unlab_basic_stmt",
   "assign_stmt",
   "right_part",
   "left_part_list",
   "left_part",
   "goto_stmt",
   "dummy_stmt",
   "cond_stmt",
   "if_stmt",
   "if_clause",
   "for_stmt",
   "for_clause",
   "for_list",
   "for_lelm",
   "proc_stmt",
   "act_parmpart",
   "act_parmlist",
   "parm_delim",
   "letter_string",
   "act_parm",
   "decl",
   "type_decl",
   "loc_or_own",
   "type_list",
   "type",
   "array_decl",
   "array_list",
   "array_seg",
   "bound_pair_list",
   "bound_pair",
   "switch_decl",
   "switch_list",
   "proc_decl",
   "pd_proc_type",
   "pd_proc_body",
   "pd_proc_hhead",
   "pd_proc_head",
   "pd_spec_part",
   "pd_spec_idlist",
   "pd_spec",
   "pd_val_part",
   "pd_ident_list",
   "pd_form_parmpart",
   "pd_form_parmlist",
   "pd_form_parm",
   "tlabel",
   "label",
   "signed_inum",
   "real_value",
};

template<>
const char * const *ALGOL60_parser_tables_t::head_symb = &head_symb_[0];

template<>
const char * const *ALGOL60_parser_tables_t::tact_name = 0;

template<>
const char * const *ALGOL60_parser_tables_t::node_name = 0;

// Head symbol numbers for the productions.
static const uint8 head_numb_[169] = {
       0,     1,     1,     2,     2,     3,     4,     5,     5,     6, 
       6,     7,     8,     9,     9,    10,    10,    11,    11,    11, 
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11, 
      11,    12,    12,    12,    12,    12,    12,    13,    13,    13, 
      13,    13,    13,    14,    15,    15,    16,    16,    16,    17, 
      18,    18,    19,    19,    20,    20,    21,    22,    23,    23, 
      23,    24,    24,    25,    25,    25,    26,    26,    26,    27, 
      27,    28,    28,    28,    28,    28,    29,    30,    31,    31, 
      32,    33,    34,    35,    35,    35,    35,    36,    37,    38, 
      38,    39,    40,    40,    41,    41,    41,    42,    43,    43, 
      44,    44,    45,    45,    46,    47,    47,    48,    48,    48, 
      48,    49,    50,    50,    51,    51,    52,    52,    52,    53, 
      53,    54,    54,    55,    55,    56,    56,    57,    58,    59, 
      59,    60,    61,    61,    62,    62,    63,    64,    65,    65, 
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67, 
      68,    68,    69,    69,    70,    70,    71,    71,    72,    73, 
      74,    74,    75,    75,    75,    76,    76,    76,    76, 
};

template<>
const uint8 *ALGOL60_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint16 f_tail_[170] = {
       0,     2,     2,     3,     4,     5,     6,     7,     8,    12, 
      13,    16,    17,    21,    22,    26,    28,    29,    32,    35, 
      38,    41,    44,    47,    50,    53,    56,    59,    61,    62, 
      63,    65,    68,    71,    74,    77,    80,    83,    84,    85, 
      86,    87,    88,    91,    92,    93,    97,    98,    99,   102, 
     106,   107,   108,   109,   111,   112,   114,   117,   119,   121, 
     124,   125,   127,   130,   131,   132,   133,   134,   135,   136, 
     137,   139,   140,   141,   142,   143,   144,   146,   147,   148, 
     150,   152,   154,   154,   155,   158,   160,   162,   164,   167, 
     169,   171,   176,   177,   180,   181,   186,   189,   191,   191, 
     194,   195,   198,   199,   203,   204,   205,   206,   207,   208, 
     209,   210,   212,   213,   215,   216,   219,   220,   221,   222, 
     224,   227,   228,   231,   235,   238,   239,   242,   245,   249, 
     250,   253,   255,   255,   256,   257,   258,   261,   266,   266, 
     267,   270,   274,   275,   276,   277,   279,   280,   281,   282, 
     284,   284,   287,   288,   291,   291,   294,   295,   298,   299, 
     301,   302,   303,   304,   306,   308,   309,   312,   315,   317, 
};

template<>
const uint16 *ALGOL60_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int8 tail_[317] = {
      -1,     1,   -18,     6,     7,     8,     9,    -3,    -3,    10, 
      -6,    11,    -7,    -6,    12,    -7,    -9,    -3,    13,   -44, 
      14,   -10,   -37,   -10,    15,    -9,     2,   -11,   -11,   -11, 
       4,   -11,   -11,     5,   -11,   -11,     2,   -11,   -11,     3, 
     -11,   -11,    16,   -11,   -11,    17,   -11,   -11,    18,   -11, 
     -11,    19,   -11,   -11,    20,   -11,   -11,    21,   -11,    22, 
     -11,   -12,   -13,     3,   -13,   -11,    23,   -11,   -11,    24, 
     -11,   -11,    25,   -11,   -11,    26,   -11,   -11,    27,   -11, 
     -11,    28,   -11,    29,   -76,    -8,    -5,    -2,    13,   -10, 
      14,    -9,   -16,   -37,   -16,    15,   -15,   -74,   -17,    13, 
     -15,    14,    -3,    10,    -7,    11,   -19,   -20,   -21,   -73, 
     -19,   -22,   -73,   -20,   -23,    30,   -24,    31,   -24,    31, 
     -48,   -23,    30,   -48,    32,   -25,    33,   -25,    30,   -24, 
     -26,   -35,   -38,   -27,   -20,   -19,   -28,   -73,   -27,   -29, 
     -33,   -34,   -42,    32,   -31,   -30,    -9,   -32,   -31,   -32, 
      -5,    34,    35,   -15,   -36,   -36,    15,   -25,   -37,   -38, 
     -73,   -35,   -37,   -26,    36,   -14,    37,   -39,   -25,   -73, 
     -38,    38,    -5,    34,   -40,    39,   -41,   -40,    12,   -41, 
      -9,    -9,    40,    -9,    41,    -9,    -9,    42,   -14,    -3, 
     -43,    13,   -44,    14,   -47,   -44,   -45,   -47,    12,    14, 
     -46,    43,    13,     8,    -4,    -9,   -49,   -53,   -58,   -60, 
     -50,   -51,   -52,    44,   -52,    -3,   -51,    12,    -3,    45, 
      46,    47,    48,   -54,   -50,    48,   -54,   -55,   -54,    12, 
     -55,    -3,    10,   -56,    11,    -3,    12,   -55,   -57,   -56, 
      12,   -57,    -9,    43,    -9,    49,    -3,    34,   -59,   -15, 
     -59,    12,   -15,   -64,   -62,   -52,   -25,    50,   -61,    51, 
      -3,   -63,   -70,    30,   -68,   -65,   -66,   -67,   -69,    30, 
     -66,   -67,   -69,    30,    52,   -52,    48,   -52,    48,    53, 
      49,    51,   -52,    51,    54,   -69,    30,    -3,   -69,    12, 
      -3,    13,   -71,    14,   -72,   -71,   -45,   -72,    -3,   -74, 
      43,    -3,    29,    29,     2,    29,     3,    29,    55,    55, 
      56,   -75,    29,    56,   -75,    56,   -75, 
};

template<>
const int8 *ALGOL60_parser_tables_t::tail = &tail_[0];

template<>
const int32 *ALGOL60_parser_tables_t::arga = 0;

template<>
const int32 *ALGOL60_parser_tables_t::argx = 0;

template<>
const int32 *ALGOL60_parser_tables_t::argy = 0;

// Boolean matrix ...
static const uint8 Bm_[159] = {
       0,     0,     0,     0,    64,     0,     5,     0,     0,     2, 
       0,     0,     0,     0,     8,    64,     0,   101,   240,     0, 
       0,    10,     0,     0,   108,   136,    65,     0,    16,     0, 
       0,    16,     0,     0,     9,     0,     0,    64,     0,   101, 
       0,    32,     0,     0,    64,     0,    37,     0,    64,     0, 
       0,    64,     0,   101,     0,     1,     0,     8,     0,     0, 
       0,     0,     2,    64,     8,    65,     0,    64,     0,     0, 
       0,    32,     0,    28,    64,     0,     0,     0,   108,   136, 
       1,     0,    16,   104,   136,     1,     0,    16,     0,     0, 
       0,     0,    16,    12,     0,     1,     0,    96,     8,     1, 
       0,    16,   236,   136,    65,     0,    16,     0,     4,     0, 
       0,     0,     1,     0,     0,    64,     8,     1,     0,     0, 
     128,     0,     0,     5,     0,     0,     0,     6,     0,     0, 
       0,    20,     0,     0,     0,    16,    64,     0,     0,     0, 
     224,     6,     0,     4,     0,     1,     0,     0,     0,    64, 
       2,     0,     4,     2,     0,     0,     0,     4,     0, 
};

template<>
const uint8 *ALGOL60_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint8 Br_[148] = {
       4,     9,     7,     4,    11,    15,    15,    19,    24,    29, 
      33,    37,    40,    44,    37,    48,     0,    51,    56,    58, 
      63,     0,    24,    67,    68,    67,    67,    37,    73,    33, 
      29,    78,    83,    83,    88,    88,    93,    78,    97,    24, 
     102,    37,    44,   107,    67,     7,    67,    67,   111,   115, 
      63,   118,    29,   111,   107,   122,    29,    83,    83,    83, 
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83, 
      83,    83,    83,   102,    40,    73,    73,    93,    93,   110, 
     110,    86,   126,   130,    67,   107,    10,   130,    24,    40, 
      86,    24,    67,    24,    67,    63,    47,    47,   135,   135, 
      47,    47,    47,    47,    47,    47,    73,    73,    73,    73, 
      73,    73,   130,    24,    24,   102,    67,   137,    67,    67, 
      67,     8,    63,   142,    59,   126,    11,   107,    67,    11, 
     137,    67,   146,   151,    24,    24,    24,    24,    24,    63, 
      56,    67,   151,    67,   154,   151,    24,     0, 
      };

template<>
const uint8 *ALGOL60_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[57] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2, 
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3, 
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3, 
       4,     4,     4,     4,     4,     0,     4, 
      };

template<>
const uint8 *ALGOL60_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[57] = {
       1,     2,     4,     8,    16,    16,    32,    32,    64,   128, 
       1,     2,     4,     8,    16,    32,    64,    64,    64,    64, 
      64,    64,   128,    64,    64,    64,    64,    64,    64,     1, 
       2,     4,     4,     8,    16,    32,    64,   128,    32,     1, 
       2,     4,     2,     8,    16,    32,    32,    32,    64,   128, 
       1,     2,     4,     4,     8,    32,    16, 
};

template<>
const uint8 *ALGOL60_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int16 Tm_[601] = {
    -115,   129,   133,  -157,   142,   145,  -153,  -136,     0,   143, 
      48,     0,    56,    50,   134,    87,     0,   143,    48,     0, 
    -141,    50,    89,    48,  -163,     0,    50,  -164,  -140,    48, 
      90,     0,    50,    48,   -91,   127,    50,    22,    55,     0, 
     115,   -45,    22,   128,     0,  -130,     0,     0,    22,     0, 
    -166,     0,    22,     0,    79,     0,    80,    43,    39,   114, 
      73,     0,    53,     0,   119,  -103,     0,   120,     0,  -168, 
       0,     0,     0,    79,  -167,    80,    -8,     0,    79,     0, 
      80,     0,     0,     0,     0,    29,    44,   143,    37,     0, 
      29,  -145,     0,    37,  -149,    33,     0,    34,  -151,     0, 
       0,     0,    34,     0,     0,     0,   -30,   -30,    38,     0, 
       0,    96,    96,    29,     0,     0,    37,     0,    33,     0, 
       0,    35,    36,     0,     0,    34,    35,    36,     0,     0, 
       0,    38,     0,    29,    97,    97,    37,     0,    33,     0, 
       0,    29,     0,     0,    37,    34,    33,     0,     0,    35, 
      36,    38,     0,    34,    98,    98,     0,     0,     0,    38, 
       0,    29,    99,    99,    37,     0,    33,     0,     0,    35, 
      36,     0,     0,    34,     0,     0,     0,    35,    36,    38, 
       0,    29,   100,   100,    37,     0,    33,     0,     0,    29, 
       0,     0,    37,    34,    33,     0,     0,    35,    36,    38, 
       0,    34,   101,   101,     0,     0,     0,    38,     0,    29, 
     102,   102,    37,     0,    33,     0,     0,    35,    36,     0, 
       0,    34,     0,     0,     0,    35,    36,    38,     0,    29, 
     103,   103,    37,     0,    33,     0,     0,    29,     0,     0, 
      37,    34,    33,     0,     0,    35,    36,    38,     0,    34, 
     104,   104,     0,     0,     0,    38,     0,    29,   105,   105, 
      37,     0,    33,     0,     0,    35,    36,     0,     0,    34, 
       0,     0,     0,    35,    36,    38,     0,    29,   106,   106, 
      37,     0,    33,     0,     0,    29,     0,     0,    37,    34, 
      33,     0,     0,    35,    36,    38,     0,    34,   107,   107, 
       0,     0,     0,    38,     0,    29,   108,   108,    37,     0, 
      33,     0,     0,    35,    36,     0,     0,    34,     0,     0, 
       0,    35,    36,    38,     0,    29,   109,   109,    37,     0, 
      33,     0,     0,    29,     0,     0,    37,    34,    33,     0, 
       0,    35,    36,    38,     0,    34,   110,   110,     0,     0, 
       0,    38,     0,     0,   111,   111,     0,     0,     0,     0, 
       0,    35,    36,    29,     0,   139,    37,     0,    33,    35, 
      36,    29,     0,   137,    37,    34,    33,     0,     0,     0, 
       0,    38,     0,    34,    76,    76,     0,     0,     0,    38, 
    -123,     0,    75,    75,     0,     0,     0,     0,     0,    35, 
      36,    48,     0,   115,    50,     0,   116,    35,    36,     0, 
       0,     0,     0,   -81,     0,     0,     0,     0,     0,     0, 
      22,     0,     0,     0,     0,     0,     0,     0,     0,   132, 
     141,   141,     0,   141,   141,   141,    29,     0,     0,    37, 
       0,    33,     0,     0,     0,     0,     0,     0,    34,     0, 
       0,     0,    32,     0,    38,    22,     0,    28,    28,    29, 
       0,     0,    37,   112,    33,     0,     0,     0,     0,     0, 
       0,    34,    35,    36,     0,    32,     0,    38,    22,     0, 
      28,    28,     0,     0,     0,     0,  -101,    10,    88,    92, 
      46,   113,   -48,     0,     0,    35,    36,     0,     0,     4, 
      27,     5,    21,   -61,    91,    20,    22,     0,    23,     0, 
       0,     0,     0,   138,    24,    16,    25,    26,  -131,     0, 
       0,     0,     0,     0,    78,    29,    93,    94,    37,   122, 
      33,     0,     0,     0,     0,     0,     0,    34,    86,     0, 
       0,    32,    95,    38,    22,     0,    28,    28,     0,     0, 
       0,   140,    83,   132,   131,   131,     0,   131,   131,   131, 
       0,    35,    36,     4,    39,    84,    40,    41,   -42,    67, 
      68,    69,    70,    71,    72,     4,     6,     5,     2,    59, 
     -80,    60,   -49,   -88,   147,    57,   135,   146,   136,  -159, 
      58,  -113,    61,    62,    63,    47,    64,    65,   118,    66, 
      77, 
};

template<>
const int16 *ALGOL60_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint16 Tr_[148] = {
     563,   563,   563,   563,   563,   487,   487,   487,   525,   563, 
     563,   487,   563,   487,   487,    57,   563,   487,   487,   563, 
     401,   563,   525,    62,   563,    38,    12,   487,   563,    57, 
     563,   525,   371,   363,   563,   487,    57,   525,    85,   525, 
     525,   487,   487,   563,    38,   525,    15,     7,   487,    10, 
      18,   563,   487,   563,   487,   525,   525,    90,   113,   133, 
     141,   161,   181,   189,   209,   229,   237,   257,   277,   285, 
     305,   325,   333,   436,   487,   563,   563,    62,    38,    12, 
      15,   563,    57,   401,     0,   487,   563,    62,   525,   525, 
     487,   525,    38,   525,    38,    23,   563,   563,   563,   563, 
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563, 
     563,   563,    38,   525,   525,   459,     1,   525,     2,     3, 
       1,   563,    29,    12,   563,   371,   487,   363,     1,   525, 
     401,     4,    62,    85,   525,   525,   525,   525,   525,    33, 
      62,     5,    15,     6,   563,     7,   525,   563, 
};

template<>
const uint16 *ALGOL60_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[57] = {
      21,    21,    16,    18,    22,    27,    21,    22,     0,    27, 
       1,    19,     2,     3,     5,     4,    29,    30,    31,    33, 
      34,    36,     5,     6,     7,     8,     9,    10,    11,    12, 
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22, 
      23,    24,    25,    26,    27,    28,    28,    28,    29,    30, 
      31,    32,    33,    34,    35,    36,    37, 
};

template<>
const uint8 *ALGOL60_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int16 Nm_[531] = {
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,    43,    56,  -136, 
    -115,  -157,  -153,    53,    87,    87,    55,    55,    54,   133, 
    -122,  -124,   133,   142,   145,    75,   142,   145,    76,     0, 
     -30,    85,     0,    96,    55,     0,    97,     0,    54,    98, 
       0,    29,    99,     0,    29,    75,    29,    55,    76,    29, 
     -30,    85,    29,    96,   100,    29,    97,   101,    29,    98, 
     102,     0,    99,   103,     0,   104,   105,     0,   106,     0, 
      29,   107,     0,    29,   100,     0,    29,   101,   108,    29, 
     102,    29,    29,   103,    29,   104,   105,    29,   106,   109, 
     110,   107,   111,     0,    29,     0,     0,     0,   108,     0, 
      28,    28,     0,     0,     0,    29,    29,     0,    29,   109, 
     110,     0,   111,    74,    81,     0,    29,    29,    28,    89, 
      28,    28,    48,     0,    89,     0,    89,    31,    28,    31, 
      28,    51,     0,    82,    29,     0,    29,    31,    28,    31, 
      28,   121,     0,   -14,    29,     0,    29,    31,    28,    31, 
      28,   -10,     0,   144,    29,     0,    29,    31,    28,    31, 
      28,   -96,  -126,  -127,    29,     0,    29,    31,    28,    31, 
      28,   -95,   -81,   126,    29,     0,    29,     0,    28,     0, 
      28,    49,    28,     0,     0,   -81,     0,    90,    48,     0, 
     -81,    31,   -81,     0,    83,    83,    49,    28,    29,    28, 
      90,     0,    28,    48,     0,    90,    31,    90,    31,   112, 
     112,  -101,  -101,    29,   -45,    29,     0,    28,     0,    28, 
       0,     0,    28,    49,     0,   -93,     0,   -45,  -130,     0, 
      48,    31,   -45,     0,   -45,   124,     0,    49,    29,     0, 
       0,  -130,    28,     0,    48,     0,  -130,    28,  -130,   123, 
     123,     0,    28,   125,   125,     0,    31,     0,     0,     0, 
     124,    31,     0,    29,     0,   126,   127,    28,    29,   127, 
       0,     0,    28,     0,     0,    49,     0,   132,    30,   127, 
       0,   -76,    48,     0,   127,     0,   127,    31,   -79,   141, 
       0,   -76,     0,     0,    29,     0,     9,    14,    28,     2, 
       0,     0,   -87,     0,     0,     0,     8,     0,   -85,   -87, 
       0,     0,    10,    42,     4,     0,   -87,     9,    14,     0, 
       2,     0,     0,   -70,     0,     0,     0,     8,   132,   -90, 
     -55,     0,     2,    10,    42,     4,     0,   -53,  -137,   130, 
     131,     0,   -55,     0,   119,     4,     3,     4,  -167,   -53, 
    -113,     1,     0,     0,     2,     0,     0,     0,     0,     0, 
       0,   -97,   129,   117,     1,    45,   115,     4,     3,     4, 
    -168,     1,     9,    14,     0,     2,     0,     0,   -70,     0, 
       0,    13,     8,    12,   -90,   -55,     0,   -86,    10,    11, 
       4,     0,   -53,     9,    14,     0,     2,     0,     0,   -89, 
       0,     0,    13,     8,    12,   -89,   -89,     0,   -89,    10, 
      11,     4,     0,   -89,     9,    14,     0,     2,     0,     0, 
    -131,     0,     0,    13,     8,    12,  -131,  -131,     0,  -131, 
      10,    11,     4,     0,  -131,     9,    14,     0,     2,     0, 
       0,   -84,     0,     0,    13,     8,    12,   -84,   -84,     0, 
     -84,    10,    11,     4,     0,   -84,     9,    14,   -62,     2, 
       0,     0,     7,     0,     0,    13,     8,    12,     7,     7, 
       0,     7,    10,    11,     4,     0,     7,    16,     9,    14, 
     -56,     2,   -59,    19,     7,    18,    17,    13,     8,    12, 
       7,     7,    15,     7,    10,    11,     4,     0,     7,    16, 
       9,    14,   -57,     2,   -58,    19,     7,    18,    17,    13, 
       8,    12,     7,     7,    15,     7,    10,    11,     4,  -166, 
       7, 
};

template<>
const int16 *ALGOL60_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint16 Nr_[148] = {
  360,   360,   360,   338,   360,   509,   487,   360,   287,   360, 
  360,   381,   360,   305,   402,     0,   360,   423,   360,   360, 
  181,   360,   127,     6,   360,    27,     1,   465,   360,   360, 
  360,   109,    34,    37,   360,   360,   360,   110,    39,   129, 
  191,   444,   326,   360,    40,   360,     8,     2,   360,   115, 
  196,   360,   360,   360,   360,   360,   360,    42,    45,    48, 
   51,    63,    66,    69,    72,    74,    75,    77,    80,    87, 
   98,    99,   101,   206,   360,   360,   360,   338,   509,   360, 
  360,   360,   360,   360,     3,   360,   360,   338,   137,   360, 
  360,   256,     9,   261,    10,   275,   360,   360,   360,   360, 
  360,   360,   360,   360,   360,   360,   360,   360,   360,   360, 
  360,   360,   360,   139,   147,   208,   360,   338,    15,     4, 
  360,   360,   223,   360,   360,   360,   360,   360,   360,   360, 
  287,    19,   360,   360,   231,   149,   157,   169,   159,   237, 
  360,    20,   360,     5,   360,   360,   167,   360, 
};

template<>
const uint16 *ALGOL60_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[169] = {
   21,    21,    21,    21,    21,    17,    14,     1,     1,    14, 
   14,    14,    21,    14,    14,    14,    14,    21,    21,    21, 
   21,    21,    21,    21,    21,    21,    21,    21,    21,    21, 
   21,    21,    21,    21,    21,    21,    21,    21,    21,    21, 
   21,    21,    21,    14,     1,     1,    21,    21,    21,    14, 
    1,     1,    21,    21,    14,    14,    21,    14,     4,     4, 
    4,     3,     3,    21,    21,    21,    14,    14,    14,     7, 
    7,     7,     7,     7,     7,     7,     7,     4,    11,    11, 
   11,     7,     7,    16,    16,    16,    16,    12,    10,    13, 
   13,     2,     3,     3,     4,     4,     4,     7,    11,    11, 
   14,    14,    16,    16,    12,    13,    13,     5,     5,     5, 
    5,     5,    15,    15,    17,    17,     0,     0,     0,     5, 
    5,     1,     1,    21,    21,     2,     2,     3,     5,     4, 
    4,     5,     6,     6,     7,     7,     8,     9,    10,    10, 
   11,    11,    12,    12,    12,    12,    12,    12,    12,    12, 
   13,    13,    14,    14,    15,    15,    16,    16,    17,    18, 
   19,    19,    20,    20,    20,    21,    21,    21,    21, 
};

template<>
const uint8 *ALGOL60_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint8 Rm_[36] = {
       0,     0,     0,     0,     0,     0,     0,     0,    82,    82, 
       0,     0,   132,     0,     0,    98,    98,    98,     7,   160, 
       0,   112,     0,     0,     0,     0,     0,   133,     0,     0, 
      75,    60,    75,     0,     0,     0, 
};

template<>
const uint8 *ALGOL60_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const int16 Rr_[148] = {
       1,     0,     0,     0,     0,    -5,    -5,     0,     0,     0, 
     -13,    82,    83,    82,    82,     0,   -20,    82,   154,     0, 
       0,   -28,     0,     0,     0,     0,     0,    82,    16,     7, 
      40,     0,     0,     0,    37,   165,     0,     0,     0,     0, 
       0,    82,    82,   111,     0,     0,     0,     0,   160,     0, 
       0,     0,     0,     7,   119,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,    15,    27,     0,     0,     0, 
       0,     0,     0,     0,     0,   120,   150,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20, 
      21,    22,    23,    24,    25,    26,    31,    32,    33,    34, 
      35,    36,     0,     0,     0,     0,    99,   138,     0,     0, 
     155,     0,     0,     0,    94,     0,     0,   128,    12,     0, 
     139,     0,   143,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0, 
};

template<>
const int16 *ALGOL60_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[57] = {
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0, 
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       3,     0,     0,     4,     5,     0,     0,     0,     0,     0, 
       0,     0,     0,     6,     0,     0,     0,     0,     1,     0, 
       0,     7,     0,     0,     0,     0,     0, 
};

template<>
const uint8 *ALGOL60_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const int8 PL_[169] = {
       1,    -1,     0,     0,     0,     0,     0,     0,     3,     0, 
       2,     0,     3,     0,     3,     1,     0,     2,     2,     2, 
       2,     2,     2,     2,     2,     2,     2,     1,     0,     0, 
       1,     2,     2,     2,     2,     2,     2,     0,     0,     0, 
       0,     0,     2,     0,     0,     3,     0,     0,     2,     3, 
       0,     0,     0,     1,     0,     1,     2,     1,     1,     2, 
       0,     1,     2,     0,     0,     0,     0,     0,     0,     0, 
       1,     0,     0,     0,     0,     0,     1,     0,     0,     1, 
       1,     1,    -1,     0,     2,     1,     1,     1,     2,     1, 
       1,     4,     0,     2,     0,     4,     2,     1,    -1,     2, 
       0,     2,     0,     3,     0,     0,     0,     0,     0,     0, 
       0,     1,     0,     1,     0,     2,     0,     0,     0,     1, 
       2,     0,     2,     3,     2,     0,     2,     2,     3,     0, 
       2,     1,    -1,     0,     0,     0,     2,     4,    -1,     0, 
       2,     3,     0,     0,     0,     1,     0,     0,     0,     1, 
      -1,     2,     0,     2,    -1,     2,     0,     2,     0,     1, 
       0,     0,     0,     1,     1,     0,     2,     2,     1, 
};

template<>
const int8 *ALGOL60_parser_tables_t::PL = &PL_[0];

template<>
const int32 *ALGOL60_parser_tables_t::nd_fterm = 0;

template<>
const int32 *ALGOL60_parser_tables_t::nd_term = 0;

template<>
const int32 *ALGOL60_parser_tables_t::nd_faction = 0;

template<>
const int32 *ALGOL60_parser_tables_t::nd_action = 0;

template<>
const int32 *ALGOL60_parser_tables_t::tact_numb = 0;

template<>
const int32 *ALGOL60_parser_tables_t::node_numb = 0;

template<>
const int32 *ALGOL60_parser_tables_t::nact_numb = 0;

template<>
const int32 *ALGOL60_parser_tables_t::reverse = 0;

