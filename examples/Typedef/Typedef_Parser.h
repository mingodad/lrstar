// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__Typedef_Parser_H)
#define __Typedef_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

enum nodecon {
   N_hello_ = 0,
};

#include "Typedef_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char Typedef_grammar_name[];

typedef lrstar_parser</* grammar           */   Typedef_grammar_name,
                      /* actions           */   true,
                      /* debug_parser      */   false,
                      /* debug_trace       */   false,
                      /* expecting         */   true,
                      /* insensitive       */   false,
                      /* lookaheads        */   1,
                      /* make_ast          */   true,
                      /* nd_parsing        */   false,
                      /* nd_threads        */   0,
                      /* node_actions      */   true,
                      /* reversable        */   false,
                      /* semantics         */   true,
                      /* stksize           */   100,
                      /* term_actions      */   true,
                      /* lexer table type  */   Typedef_lexer_t,
                      /* parser table type */   Typedef_parser_tables_t> Typedef_parser_t;

#endif
