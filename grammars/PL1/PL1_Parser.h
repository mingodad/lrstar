// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__PL1_Parser_H)
#define __PL1_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"
      #undef  GRAMMAR
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
      #define ACTIONS       PL1_Actions
      #define TERM_ACTIONS  PL1_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING

#include "PL1_ParserTables_typedef.h"
#include "lrstar_parser.h"

#endif
