// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__Fortran_Parser_H)
#define __Fortran_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

#include "Fortran_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char Fortran_grammar_name[];

typedef lrstar_parser</* grammar           */   Fortran_grammar_name,
                      /* actions           */   true,
                      /* debug_parser      */   false,
                      /* debug_trace       */   false,
                      /* expecting         */   true,
                      /* insensitive       */   false,
                      /* lookaheads        */   1,
                      /* make_ast          */   false,
                      /* nd_parsing        */   false,
                      /* nd_threads        */   0,
                      /* node_actions      */   false,
                      /* reversable        */   false,
                      /* semantics         */   false,
                      /* stksize           */   100,
                      /* term_actions      */   true,
                      /* lexer table type  */   Fortran_lexer_t,
                      /* parser table type */   Fortran_parser_tables_t> Fortran_parser_t;

#endif
