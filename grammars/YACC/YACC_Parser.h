// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__YACC_Parser_H)
#define __YACC_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"
namespace YACC {


};   /* namespace YACC */
#include "YACC_ParserTables_typedef.h"
#include "lrstar_parser.h"

namespace YACC {
extern const char grammar_name[];

typedef lrstar_parser</* grammar           */   grammar_name,
                      /* AST traversals    */   1,
                      /* actions           */   false,
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
                      /* term_actions      */   false,
                      /* lexer table type  */   lexer_t,
                      /* parser table type */   parser_tables_t> parser_t;

};   /* namespace YACC */

#endif
