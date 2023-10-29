
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    ANTLR_ParserTables.hpp (generated by LRSTAR 24.0.017)

      #include "lrstar_basic_defs.h"
      #include "ANTLR_ParserTables.h"
      #include "ANTLR_Actions.h"

      static int n_terms      =   43; // Number of terminals.
      static int n_heads      =  126; // Number of nonterminals.
      static int n_prods      =  213; // Number of productions.
      static int n_states     =  148; // Number of states.
      static int accept_state =  147; // Accept state.
      static int n_termactns  =    2; // Number of terminal actions.
      static int n_nodenames  =    0; // Number of node names.
      static int n_nodeactns  =    0; // Number of node actions.
      static int eof_symb     =    1; // <eof> symbol number.
      static int err_used     =    1; // <error> used in grammar?

   // Terminal symbols of the grammar ...
      const char* ANTLR_ParserTables::term_symb[43] = 
      {
         "<error>",
         "<eof>",
         "<integer>",
         "<string_literal>",
         "<lexer_char_set>",
         "<rule_ref>",
         "<token_ref>",
         "\'grammar\'",
         "\'parser\'",
         "\'lexer\'",
         "\'options\'",
         "\'tokens\'",
         "\'channels\'",
         "\'import\'",
         "\'fragment\'",
         "\'returns\'",
         "\'locals\'",
         "\'throws\'",
         "\'catch\'",
         "\'finally\'",
         "\'mode\'",
         "\';\'",
         "\':\'",
         "\'::\'",
         "\',\'",
         "\'(\'",
         "\')\'",
         "\'->\'",
         "\'<\'",
         "\'>\'",
         "\'=\'",
         "\'?\'",
         "\'*\'",
         "\'+=\'",
         "\'+\'",
         "\'|\'",
         "\'..\'",
         "\'.\'",
         "\'@\'",
         "\'#\'",
         "\'~\'",
         "\'{\'",
         "\'}\'"
      };

   // Nonterminal symbols of the grammar ...
      const char *ANTLR_ParserTables::head_symb[126] = 
      {
         "Goal",
         "grammarSpec",
         "grammarType",
         "prequelConstruct",
         "optionsSpec",
         "option",
         "optionValue",
         "delegateGrammars",
         "delegateGrammar",
         "tokensSpec",
         "channelsSpec",
         "idList",
         "action",
         "actionScopeName",
         "actionBlock",
         "argActionBlock",
         "modeSpec",
         "rules",
         "ruleSpec",
         "parserRuleSpec",
         "exceptionGroup",
         "exceptionHandler",
         "finallyClause",
         "rulePrequel",
         "ruleReturns",
         "throwsSpec",
         "localsSpec",
         "ruleAction",
         "ruleBlock",
         "ruleAltList",
         "labeledAlt",
         "lexerRule",
         "lexerRuleBlock",
         "lexerAltList",
         "lexerAlt",
         "lexerElements",
         "lexerElement",
         "labeledLexerElement",
         "lexerBlock",
         "lexerCommands",
         "lexerCommand",
         "lexerCommandName",
         "lexerCommandExpr",
         "altList",
         "alternative",
         "element",
         "actionElement",
         "argActionElement",
         "labeledElement",
         "ebnf",
         "blockSuffix",
         "ebnfSuffix",
         "lexerAtom",
         "atom",
         "notSet",
         "blockSet",
         "setElement",
         "block",
         "ruleref",
         "range",
         "terminal",
         "elementOptions",
         "elementOption",
         "identifier",
         "qid",
         "ACTION_CONTENT",
         "ARGUMENT_CONTENT",
         "prequelConstruct*",
         "modeSpec*",
         "('lexer' 'grammar' | 'parser' 'grammar' | 'grammar')",
         "(option ';')",
         "(option ';')*",
         "('.' identifier)",
         "('.' identifier)*",
         "(',' delegateGrammar)",
         "(',' delegateGrammar)*",
         "idList?",
         "(',' identifier)",
         "(',' identifier)*",
         "','?",
         "(actionScopeName '::')",
         "(actionScopeName '::')?",
         "ACTION_CONTENT*",
         "ARGUMENT_CONTENT*",
         "lexerRule*",
         "ruleSpec*",
         "argActionBlock?",
         "ruleReturns?",
         "throwsSpec?",
         "localsSpec?",
         "rulePrequel*",
         "exceptionHandler*",
         "finallyClause?",
         "(',' qid)",
         "(',' qid)*",
         "('|' labeledAlt)",
         "('|' labeledAlt)*",
         "('#' identifier)",
         "('#' identifier)?",
         "'fragment'?",
         "optionsSpec?",
         "('|' lexerAlt)",
         "('|' lexerAlt)*",
         "lexerCommands?",
         "lexerElement+",
         "ebnfSuffix?",
         "('=' | '+=')",
         "(lexerAtom | lexerBlock)",
         "(optionsSpec ':')",
         "(optionsSpec ':')?",
         "(',' lexerCommand)",
         "(',' lexerCommand)*",
         "('|' alternative)",
         "('|' alternative)*",
         "elementOptions?",
         "element+",
         "'?'?",
         "(atom | block)",
         "blockSuffix?",
         "('|' setElement)",
         "('|' setElement)*",
         "ruleAction*",
         "(optionsSpec? ruleAction* ':')",
         "(optionsSpec? ruleAction* ':')?",
         "(',' elementOption)",
         "(',' elementOption)*"
      };

   // Terninal action names found in the grammar ...
      const char *ANTLR_ParserTables::tact_name[2] = 
      {
         "error",
         "lookup"
      };

   // Head symbol numbers for the productions ...
      uchar ANTLR_ParserTables::head_numb[213] = 
      {
          0,    1,    2,    3,    3,    3,    3,    3,    4,    5,    6,    6,    6,    6,    7,    8,    8,    9,   10,   11,
         12,   13,   13,   13,   14,   15,   16,   17,   18,   18,   19,   20,   21,   22,   23,   23,   24,   25,   26,   27,
         28,   29,   30,   31,   32,   33,   34,   34,   35,   36,   36,   36,   36,   37,   38,   39,   40,   40,   41,   41,
         42,   42,   43,   44,   44,   45,   45,   45,   45,   45,   46,   47,   48,   49,   50,   51,   51,   51,   52,   52,
         52,   52,   52,   52,   53,   53,   53,   53,   53,   54,   54,   55,   56,   56,   56,   56,   57,   58,   59,   60,
         60,   61,   62,   62,   63,   63,   64,   65,   66,   67,   67,   68,   68,   69,   69,   69,   70,   71,   71,   72,
         73,   73,   74,   75,   75,   76,   76,   77,   78,   78,   79,   79,   80,   81,   81,   82,   82,   83,   83,   84,
         84,   85,   85,   86,   86,   87,   87,   88,   88,   89,   89,   90,   90,   91,   91,   92,   92,   93,   94,   94,
         95,   96,   96,   97,   98,   98,   99,   99,  100,  100,  101,  102,  102,  103,  103,  104,  104,  105,  105,  106,
        106,  107,  107,  108,  109,  109,  110,  111,  111,  112,  113,  113,  114,  114,  115,  115,  116,  116,  117,  117,
        118,  118,  119,  120,  120,  121,  121,  122,  123,  123,  124,  125,  125
      };

   // First tail symbol index into the tail list ...
      ushort ANTLR_ParserTables::f_tail[214] = 
      {
          0,    2,    8,    9,   10,   11,   12,   13,   14,   18,   21,   23,   24,   25,   26,   30,   33,   34,   38,   42,
         45,   49,   50,   51,   52,   55,   58,   62,   63,   64,   65,   75,   77,   80,   82,   83,   84,   86,   89,   91,
         94,   95,   97,   99,  105,  106,  108,  110,  110,  111,  113,  115,  117,  118,  121,  125,  128,  132,  133,  134,
        135,  136,  137,  139,  141,  141,  143,  145,  146,  147,  148,  151,  154,  157,  159,  160,  162,  164,  166,  167,
        168,  169,  170,  171,  173,  174,  175,  176,  177,  179,  181,  183,  187,  189,  191,  192,  193,  197,  200,  203,
        205,  207,  211,  212,  215,  216,  217,  219,  220,  221,  221,  223,  223,  225,  227,  229,  230,  232,  232,  234,
        236,  236,  238,  240,  240,  242,  242,  243,  245,  245,  247,  247,  248,  250,  250,  251,  251,  253,  253,  255,
        255,  257,  257,  259,  259,  260,  260,  261,  261,  262,  262,  263,  263,  265,  265,  267,  267,  268,  270,  270,
        272,  274,  274,  276,  278,  278,  279,  279,  280,  280,  281,  283,  283,  285,  285,  286,  287,  289,  289,  290,
        291,  292,  293,  294,  296,  296,  297,  299,  299,  301,  303,  303,  305,  305,  306,  307,  309,  309,  310,  311,
        312,  312,  313,  315,  315,  317,  317,  319,  322,  322,  323,  325,  325,  327
      };

   // Tail symbol numbers ...
      char ANTLR_ParserTables::tail[327] = 
      {
         -1,    1,   -2,  -63,   21,  -67,  -17,  -68,  -69,   -4,   -7,   -9,  -10,  -12,   10,   41,  -71,   42,  -63,   30,
         -6,  -63,  -73,    3,  -14,    2,   13,   -8,  -75,   21,  -63,   30,  -63,  -63,   11,   41,  -76,   42,   12,   41,
        -76,   42,  -63,  -78,  -79,   38,  -81,  -63,  -14,  -63,    9,    8,   41,  -82,   42,   41,  -83,   42,   20,  -63,
         21,  -84,  -85,  -19,  -31,    5,  -86,  -87,  -88,  -89,  -90,   22,  -28,   21,  -20,  -91,  -92,   18,  -15,  -14,
         19,  -14,   -4,  -27,   15,  -15,   17,  -64,  -94,   16,  -15,   38,  -63,  -14,  -29,  -30,  -96,  -44,  -98,  -99,
          6, -100,   22,  -32,   21,  -33,  -34, -102,  -35, -103, -104,  -37, -105,  -52, -105,  -38, -105,  -46,  -63, -106,
       -107,   25, -109,  -33,   26,   27,  -40, -111,  -41,   25,  -42,   26,  -41,  -63,   20,  -63,    2,  -44, -113, -114,
       -115,  -48, -105,  -53, -105,  -49,  -46,  -47,  -14, -116, -114,  -15, -116, -114,  -63, -106, -117,  -57, -118,  -51,
         31, -116,   32, -116,   34, -116,  -59,  -60,    5,  -54,    4,   37, -114,  -59,  -60,  -58,  -54,   37, -114,   40,
        -56,   40,  -55,   25,  -56, -120,   26,    6, -114,    3, -114,  -59,    4,   25, -123,  -43,   26,    5,  -86, -114,
          3,   36,    3,    6, -114,    3, -114,   28,  -62, -125,   29,  -64,  -63,   30,   -6,    5,    6,  -63,  -73,    0,
          0,  -67,   -3,  -68,  -16,    9,    7,    8,    7,    7,   -5,   21,  -71,  -70,   37,  -63,  -73,  -72,   24,   -8,
        -75,  -74,  -11,   24,  -63,  -78,  -77,   24,  -13,   23,  -80,  -82,  -65,  -83,  -66,  -84,  -31,  -85,  -18,  -15,
        -24,  -25,  -26,  -90,  -23,  -91,  -21,  -22,   24,  -64,  -94,  -93,   35,  -30,  -96,  -95,   39,  -63,  -97,   14,
         -4,   35,  -34, -102, -101,  -39,  -36, -104,  -36,  -51,   30,   33,  -52,  -38,   -4,   22, -108,   24,  -40, -111,
       -110,   35,  -44, -113, -112,  -61,  -45, -115,  -45,   31,  -53,  -57,  -50,   35,  -56, -120, -119, -121,  -27, -100,
       -121,   22, -122,   24,  -62, -125, -124
      };

   // Arguments for token actions ...
      char ANTLR_ParserTables::arga[43] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1
      };

   // Boolean matrix ...
      uchar ANTLR_ParserTables::Bm[169] = 
      {
          0,    0,    0,    0,  128,    1,    0,    0,    0,    2,    0,    0,    0,    0,   96,    0,    0,    0,  128,    0,
          0,    0,    0,    6,    0,    0,    2,   32,    8,    0,    0,    0,    0,   16,   96,    1,    0,    0,    0,    1,
          0,   64,    0,    0,    0,    0,    4,    0,    0,    8,    0,    0,   16,    0,    0,    0,   96,    0,    0,    0,
         32,    0,    0,   18,    0,    0,    1,    0,    0,    0,   32,  120,    0,   32,    0,   25,    0,   32,    0,    0,
          0,  108,    0,    0,    0,   16,    0,    8,    0,    0,    0,   24,    0,    0,    0,   36,    0,    0,    0,    8,
          0,    0,    0,  129,    0,   88,    0,   32,    0,    0,    0,   64,    0,   96,    0,    1,    0,    0,  120,    0,
         32,    0,    9,   88,    0,    0,    0,    0,    2,    4,    0,    2,    0,    0,    0,    0,    1,    0,    0,   64,
          0,    0,  100,    0,    0,    0,    0,   16,    2,    0,    0,   64,   64,    0,  104,    0,   32,    0,   25,  104,
          0,   32,    0,    9,    0,    0,    4,    0,    2
      };

   // Booeal matrix row (for state)...
      uchar ANTLR_ParserTables::Br[148] = 
      {
          4,    9,   14,   18,   18,    7,    0,   22,    0,   27,   29,   14,   29,   29,   34,   37,   41,   29,    0,    0,
         43,   14,   14,   14,   47,   14,    8,   51,    0,   56,   61,   14,   10,    0,   10,   29,    7,   44,   40,   29,
         66,    7,   43,   14,   50,    0,    0,   71,   76,   14,   81,   14,   66,   86,    7,    0,   16,   71,   88,   92,
         88,   88,   96,    0,   36,  100,  105,   36,    8,    0,   29,    0,    0,    0,  108,  113,   96,   96,   96,  118,
         36,   14,   28,   36,  100,  123,   71,   44,  127,   50,  132,  132,   71,    0,   58,   36,    0,   43,    0,  137,
         36,   14,   14,   14,   50,  142,  145,   81,  149,    7,    0,   42,  154,   29,  113,  137,   14,  123,    0,  108,
         14,  154,   88,   92,   88,   88,   96,   29,   36,    8,    0,   17,   36,  159,   36,   36,   36,    0,   29,   29,
         29,  137,    0,  164,   29,  108,   36,    0
      };

   // Booolean matrix column (displacement) ...
      uchar ANTLR_ParserTables::Bc[43] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
          2,    2,    2,    2,    2,    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,    4,    4,    4,
          4,    4,    4
      };

   // Boolean matrix filter/mask value ...
      uchar ANTLR_ParserTables::Bf[43] = 
      {
          1,    2,    4,    8,   16,   32,   64,  128,    1,    1,    2,    4,    4,    4,    8,   16,   32,   64,  128,  128,
          1,    2,    4,    8,   16,   32,   64,  128,    1,    2,    4,    8,   16,   32,   16,   64,  128,    1,    2,    4,
          8,   16,   32
      };

   // Terminal transition matrix ...
      short ANTLR_ParserTables::Tm[201] = 
      {
        -11,  -13, -104, -105,    0,   65,    0,  140,   95,   65,  -82,  -80,   95,    0,    0,   65,  118,  127,   64,    0,
          0,    0,    0,    0,    0,  129,    0,    0,    0,   68,    0,    0,    0,    0,    0,  129,   45,  128,   17,   26,
         66,   67,    0,    0,   66, -167,    0,  128,    0,    0,   66,  130,  -14, -183,    0,   43,    0,  -91,    0,    0,
       -113,   50, -197,    0,    0,    0,  117,   65,  -82,   63,   64,    0,   21,  -17,    0,    0,    0,    0,    0,    0,
          0,    0,    0,  -43,    0,    0,  116,   68,    0,   84,  -95, -101,   83,    0,    0, -107,    0,    0,    0,   67,
          0,    0,   66,   45,  -24, -116, -207,    0,  114,   85,  -96,    0,    0,    0,  107,    0,    0, -108,    0,  146,
          0,    0,  101,    0,    0,   28,  -25, -104, -105,  -22,   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        -59,   46,  100,    0,  102,    0,  -56,    0,    0, -114, -179,    0,    0, -180,    0,  132,    0,    0,  101,    0,
        -23,   22,  -18,  -98,  -61, -104, -105,    3,   10,   12,   13,   11, -167,   39,   70,   49,  139,  138,   25,    6,
         47, -132,   51,  105,  -54,   75,   81, -115,   31,   76,   77,  147,   78,   92,   82,  103,   14,  120,    4,   18,
         -8
      };

   // Terminal transition matrix row ...
      uchar ANTLR_ParserTables::Tr[148] = 
      {
        163,  163,  163,   36,  125,  163,  163,  163,  163,   36,  163,  163,   36,  125,  125,  163,   36,   89,  163,  163,
        163,  163,  163,  163,  163,  163,  163,  163,  163,  163,   36,  163,   36,  163,  125,   67,  125,  163,  163,   89,
         89,   89,   36,  163,  163,  163,  163,   67,  163,  163,    0,  163,   67,  163,   67,  163,  163,   67,  163,  125,
        163,  163,   36,  163,  163,  163,   89,  163,  163,  163,   89,  163,  163,  163,  163,  125,   36,   36,   36,    9,
        163,  163,  163,  163,  163,   89,   67,   36,  125,  125,  163,  163,   67,  163,  163,  163,  163,   89,  163,  163,
        163,  163,  163,  163,   89,  163,   67,    0,   36,    0,  163,  163,   15,   67,  125,  125,  163,   89,  163,  125,
        163,   15,  163,  125,  163,  163,   36,   89,  163,  163,  163,  163,  163,    5,  163,  163,  163,  163,   67,   89,
         89,   89,  163,   89,   67,   89,  163,  163
      };

   // Terminal transition matrix column ...
      uchar ANTLR_ParserTables::Tc[43] = 
      {
         28,   28,    1,    0,    1,    2,    3,   24,   35,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
         15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,
         35,   36,   37
      };

   // Nonterminal transition matrix ...
      short ANTLR_ParserTables::Nm[519] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, -127,  113, -119, -163,   72, -157,  -60,
         94,   73,    0,  -58,   96,   97, -102,   94, -122,    0,  -58, -210,   97, -102, -103,  -74, -193, -193,   20,   42,
         41, -160,    0,    0,    0, -193, -118,   35,    0,    0, -193, -193,  -15,   72,   71, -193,  115,   73,  110,  -40,
          0,    0,    0,    0,    0,    0,    0, -193,  109,   36,   -9,    0,    0,    0,    0,  -12,    0,   93,    0,    0,
          0,    0,    0,    0, -186,    0,    0,    0,    0,  -71,  -88,    0,    0,    0,  141,    0,  111,  142,  -93, -201,
          0, -189,  -73,  112,  112,    0,    0,   60,  112,  -81,    0,  -12,    0,  111,  -78,  -79,    0,    0,   59,   60,
        112,  -81,    0,    0,    0,    0,  -78,  -79,    0,    0,   59,    0,    0,    0,    0,   58,   61, -170,   60,    0,
        -81,    0,    0,   56,    0,  -78,  -79,   58,   61,   59,   99,    0,    0,    0,    0,    0,   55,    0,    0,    0,
          0,    0,   56,    0,  -52,    0,   58,   61,    0,    0,    0,   57,   62, -176,    0,    0,  -52,    0,    0,  -67,
          0,    0,  124,  -87,   62, -175,  125,  -86,  -84,  -85,   57,    0,  123,    0,    0,  -52,    0,    0,  -67,    0,
          0,  124,  -87,   62, -175,  125,  -86,  -84,  -85,    0, -178,  123,    0,    0,    0,   98,    0,    0,  -94,    0,
       -193,   87,  -21,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,    0, -195,  -68, -134,
         23,    0,    0,    0,    0,    0,   62,  126,    0,    0,    0,  -69,  122,    0,    0,    0, -194,  -68,    0,    0,
          0,    0,    0,  121,  -51,   62,  126, -185,   86,    0,  -69,  122,    0,  -83, -178,  -76,  -33,  -38,    0, -202,
          0,    0,  -94,    0, -193,  -34,   33, -126,    0,    0,    0,    0,    0,    0,   60,    0,  -81,    0,    0,   32,
         54,  -78,  -79, -193,    0,   59,  -44,    0,    0,  135,    0,    0,   55,    0,    0,    0,    0,    0,   56,    0,
          0,    0,   58,   61,    0,    0,    0,    0,  -65,    0,    0,    0, -152,    0,    0,    0,    0,  -70,  -35,  -77,
        -32, -144,    0,    0,    0,    0,   57,    0,    0,    0,    0,  -52,    0,    0,    0, -178,  -97, -198,  -87,   62,
       -175, -199,  -86,  -84,  -85, -193, -169,   33, -126,    0,    0,    0,    0,    0,    0, -178, -181,   19,  -81,    0,
         34, -140,    0,  -78,  -79, -193, -169,   20,    0,    0,    0,    0,    0,    0,    0,    0,    0,   91,    0,    0,
          0,    0,    0,    0,  137, -182,    0,    0,    0,  -66,    0,    0,    0,    0,    0,    0,    0,    0,  -92,    0,
        134,  -72,  144,   16,   37,    0, -209,  136,    0,  -50,  133,  -53,    0,    0,    0,    0,    0,    0, -100,    0,
        -75,  -39,  -36, -150, -178,   -5, -110, -174,  -90,  -89,  -29,   -6,  -94, -142, -193,   -3,    5,    1, -136, -138,
          7,   15,   -2,   -7,   29, -121,   90, -124,   30,    2, -129,   44,  -19, -112,    8,   52,   40,   53,    9,   27,
         38,   48,   69,   88,  131,  -31, -159,   89, -162,  119, -165,  -42,   16,  -28, -172,   74,  -46,  -30,  -49,   79,
       -154, -156,   -4, -188,  104, -191,  145,  -99, -206,   80,  -20, -144, -204,  108,  143, -146, -148, -212,  106
      };

   // Nonterminal transition matrix row ...
      ushort ANTLR_ParserTables::Nr[148] = 
      {
        443,  443,  443,  443,  443,  443,  443,  443,  443,  443,  443,  374,  443,  443,  209,  443,  443,  443,  443,  443,
        443,  273,  354,   34,  443,   56,  374,  443,  443,   26,  443,   39,  443,  443,  443,  443,  443,  443,  443,  374,
        443,  443,  443,   25,  443,  443,  443,  292,  443,   40,   44,    0,  443,  374,  443,  443,  443,  105,  443,  443,
        374,  209,  443,  443,  443,  374,  443,  209,  209,  443,  209,  443,  443,  374,  443,   10,  374,  209,  273,  374,
        273,   12,  443,  354,   34,  209,  136,  443,  273,  443,  443,  443,  117,  443,  443,  443,  443,  443,  443,  443,
         56,    1,    4,    2,  443,    6,  443,    8,  443,  443,  443,  443,  198,  374,   17,  443,   19,  273,  443,  443,
          3,  179,  273,  374,  354,   34,  354,  273,   26,  354,  443,  443,   39,  354,   25,  292,   40,  443,  209,  354,
        273,  443,  443,  443,  273,  443,   44,  443
      };

   // Nonterminal transition matrix column ...
      uchar ANTLR_ParserTables::Nc[213] = 
      {
         14,   14,   26,    3,    3,    3,    3,    3,   12,   14,   26,   26,   26,   26,   59,    3,    3,    2,    8,   14,
         20,   26,   26,   26,   67,   68,   30,   31,   10,   10,   50,   54,   57,   58,   59,   59,   72,   73,    0,   65,
         12,    3,    2,    7,    8,   14,   20,   20,   26,   68,   68,   68,   68,   30,   31,    4,   67,   67,   10,   10,
         50,   50,   54,   57,   57,   58,   58,   58,   58,   58,   59,   72,   73,    0,   65,    1,    1,    1,    2,    2,
          2,    2,    2,    2,    3,    3,    3,    3,    3,    4,    4,    5,    6,    6,    6,    6,    7,    8,    9,   10,
         10,   11,   12,   12,   13,   13,   14,   15,   16,   17,   17,   18,   18,   19,   19,   19,   20,   21,   21,   22,
         23,   23,   24,   25,   25,   26,   26,   27,   28,   28,   29,   29,   30,   31,   31,   32,   32,   33,   33,   34,
         34,   35,   35,   36,   36,   37,   37,   38,   38,   39,   39,   40,   40,   41,   41,   42,   42,   43,   44,   44,
         45,   46,   46,   47,   48,   48,   49,   49,   50,   50,   51,   52,   52,   53,   53,   54,   54,   55,   55,   56,
         56,   57,   57,   58,   59,   59,   60,   61,   61,   62,   63,   63,   64,   64,   65,   65,   66,   66,   67,   67,
         68,   68,   69,   70,   70,   71,   71,   72,   73,   73,   74,   75,   75
      };

   // Reduction matrix ...
      uchar ANTLR_ParserTables::Rm[121] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   27,    0,    0,  166,    0,    0,
          0,    0,    0,    0,    0,    0,    0,   26,    0,    0,  166,    0,    0,    0,    0,    0,    0,    0,    0,    0,
         80,   80,   80,   80,    0,   80,    0,  104,   80,   80,    0,   80,    0,    0,  192,  192,  192,  192,    0,  192,
          0,  105,  192,  192,  192,  192,    0,    0,  192,    0,  192,   64,    0,    0,    0,    0,    0,   64,   64,  192,
          0,    0,  143,    0,  143,  143,    0,  143,  143,  104,  143,  143,  143,    0,    0,  208,    0,  208,    0,  168,
        208,  208,    0,    0,  208,    0,  208,    0,    0,  192,    0,  192,    0,    0,   64,    0,    0,    0,   64,    0,
        192
      };

   // Reduction matrix row ...
      short ANTLR_ParserTables::Rr[148] = 
      {
          0,    0,    0,    0,    0,    0,  109,  141,  111,  -13,    0,    0,    0,    0,    0,    1,    0,  143,  117,  123,
         16,  125,  125,    0,    0,    0,  168,  145,  137,    0,    0,    0,    0,  128,    0,    0,    0,    0,  147,    0,
          0,    0,    0,    0,  130,  135,  139,   47,  149,    0,    0,  131,    0,  -26,    0,  171,  173,   48,  177,    0,
        177,  177,  196,  -38,  -52,  192,    0,  192,  184,  151,    0,  158,  120,  120,   45,    0,  196,  196,  196,    0,
        192,    0,    0,  192,  192,    0,   47,    0,    0,   37,  106,   10,   47,  187,   57,  192,  211,  120,  203,    0,
        -66,    0,    0,    0,   55,    0,    0,    0,    0,    0,  161,  164,    0,    0,    0,    0,    0,    0,  153,   41,
          0,   63,  177,    0,  177,  200,  196,  -80,  192,  -93,  135,  155,  -66,    0,  192,  192, -107,  205,    0,    0,
        143,    0,  190,    0,    0,   62, -107,    0
      };

   // Reduction matrix column ...
      uchar ANTLR_ParserTables::Rc[43] = 
      {
          0,    1,    0,    2,    3,    2,    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          1,    5,    6,    0,    0,    2,    7,    3,    8,    0,    9,   10,   10,    9,   10,   11,    0,    2,    6,   12,
          2,   13,    0
      };

   // Production lengths (minus one) ...
      char ANTLR_ParserTables::PL[213] = 
      {
          1,    5,    0,    0,    0,    0,    0,    0,    3,    2,    1,    0,    0,    0,    3,    2,    0,    3,    3,    2,
          3,    0,    0,    0,    2,    2,    3,    0,    0,    0,    9,    1,    2,    1,    0,    0,    1,    2,    1,    2,
          0,    1,    1,    5,    0,    1,    1,   -1,    0,    1,    1,    1,    0,    2,    3,    2,    3,    0,    0,    0,
          0,    0,    1,    1,   -1,    1,    1,    0,    0,    0,    2,    2,    2,    1,    0,    1,    1,    1,    0,    0,
          0,    0,    0,    1,    0,    0,    0,    0,    1,    1,    1,    3,    1,    1,    0,    0,    3,    2,    2,    1,
          1,    3,    0,    2,    0,    0,    1,    0,    0,   -1,    1,   -1,    1,    1,    1,    0,    1,   -1,    1,    1,
         -1,    1,    1,   -1,    1,   -1,    0,    1,   -1,    1,   -1,    0,    1,   -1,    0,   -1,    1,   -1,    1,   -1,
          1,   -1,    1,   -1,    0,   -1,    0,   -1,    0,   -1,    0,   -1,    1,   -1,    1,   -1,    0,    1,   -1,    1,
          1,   -1,    1,    1,   -1,    0,   -1,    0,   -1,    0,    1,   -1,    1,   -1,    0,    0,    1,   -1,    0,    0,
          0,    0,    0,    1,   -1,    0,    1,   -1,    1,    1,   -1,    1,   -1,    0,    0,    1,   -1,    0,    0,    0,
         -1,    0,    1,   -1,    1,   -1,    1,    2,   -1,    0,    1,   -1,    1
      };

   // Terminal action number ...
      char ANTLR_ParserTables::tact_numb[43] = 
      {
          0,   -1,    1,    1,    1,    1,    1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1
      };

   // Init action function pointers ...
      void (*ANTLR_ParserTables::init_func[2]) () =
      {
         ANTLR_Actions::init_actions,
         ANTLR_Actions::term_actions
      };

   // Terminal action function pointers ...
      int (*ANTLR_ParserTables::tact_func[2]) (int& t) =
      {
         ANTLR_TermActions::error,
         ANTLR_TermActions::lookup
      };

//
////////////////////////////////////////////////////////////////////////////////////////////////////

