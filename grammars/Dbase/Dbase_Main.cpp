#include "lrstar_basic_defs.h"
#include "Dbase_LexerTables_typedef.h"
#include "Dbase_Parser.h"

void Dbase_init_actions(lrstar_parser *parser); /* User-supplied */
void Dbase_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t Dbase_init_funcs_[2] = {
   Dbase_init_actions,
   Dbase_term_actions
};

int Dbase_error(lrstar_parser *parser, int &t);
int Dbase_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t Dbase_tact_funcs_[2] = {
   Dbase_error,
   Dbase_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "Dbase",
                               /* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* expecting    */   true,
                               /* insensitive  */   false,
                               /* lookaheads   */   1,
                               /* make_ast     */   false,
                               /* nd_parsing   */   false,
                               /* nd_threads   */   0,
                               /* node_actions */   false,
                               /* reversable   */   false,
                               /* semantics    */   false,
                               /* stksize      */   100,
                               /* term_actions */   true,
                               /* init_func    */   &Dbase_init_funcs_[0],
                               /* tact_func    */   &Dbase_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
