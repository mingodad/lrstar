
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Modula2_LexerTables_typedef.h"
#include "Modula2_Parser.h"

lrstar_parser generated_parser(/* user data   */   NULL,
                               /* actions      */   true,
                               /* insensitive  */   false,
                               /* make_ast     */   false,
                               /* node_actions */   false,
                               /* term_actions */   true);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

