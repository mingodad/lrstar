// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__NCSA_Parser_H)
#define __NCSA_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"
namespace NCSA {

namespace NCSA {
    enum nodecon {
        N_Report = 0,
        N_Day = 1,
        N_Client = 2,
        N_FullName = 3,
        N_Name = 4,
        N_Time = 5,
        N_File = 6,
        N_Code = 7,
        N_Size = 8,
        N_Source = 9,
        N_Query = 10,
    };
}


};   /* namespace NCSA */
#include "NCSA_ParserTables_typedef.h"
#include "lrstar_parser.h"

namespace NCSA {
extern const char grammar_name[];

typedef lrstar_parser</* grammar           */   grammar_name,
                      /* AST traversals    */   1,
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
                      /* lexer table type  */   NCSA_lexer_t,
                      /* parser table type */   parser_tables_t> parser_t;

};   /* namespace NCSA */

#endif
