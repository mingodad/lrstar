
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Java9_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void Java9_init_actions(lrstar_parser *parser);
void Java9_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int Java9_error(lrstar_parser *parser, int &t);
int Java9_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

