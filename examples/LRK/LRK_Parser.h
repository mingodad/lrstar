// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__LRK_Parser_H)
#define __LRK_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"
namespace LRK {

namespace LRK {
    enum nodecon {
        N_goal_ = 0,
        N_function_decl_ = 1,
        N_function_def_ = 2,
        N_type_spec_ = 3,
        N_function_ = 4,
        N_arg_ = 5,
        N_arg_name_ = 6,
        N_function_body_ = 7,
    };
}


};   /* namespace LRK */
#include "LRK_ParserTables_typedef.h"
#include "lrstar_parser.h"

namespace LRK {
    extern const char grammar_name[];

    typedef lrstar_parser</* grammar           */   grammar_name,
                          /* AST traversals    */   1,
                          /* actions           */   true,
                          /* debug_parser      */   true,
                          /* debug_trace       */   false,
                          /* expecting         */   true,
                          /* insensitive       */   false,
                          /* lookaheads        */   100,
                          /* make_ast          */   true,
                          /* nd_parsing        */   true,
                          /* nd_threads        */   2,
                          /* node_actions      */   true,
                          /* reversable        */   false,
                          /* semantics         */   true,
                          /* stksize           */   100,
                          /* term_actions      */   true,
                          /* lexer table type  */   lexer_t,
                          /* parser table type */   parser_tables_t> parser_t;

};   /* namespace LRK */

#endif
