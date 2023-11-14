
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_Actions.h"
#include "lrstar_main.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef ACTIONS

void LRK_init_actions(lrstar_parser *parser)
{
      /* Initialization code goes here */
}

void  LRK_term_actions(lrstar_parser *parser)
{
      /* Termination code goes here */
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef TERM_ACTIONS

int LRK_error(lrstar_parser *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int LRK_lookup(lrstar_parser *parser, int &t)             // Lookup in symbol table.
{
      int sti;
      #ifdef ND_PARSING
      if (parser->lt.lookahead.start > 0)             // In lookahead mode?
      {
         sti = parser->add_symbol(t, parser->lt.lookahead.start, parser->lt.lookahead.end);
      }
      else                                 // Regular mode of parsing.
      #endif
      {
         sti = parser->add_symbol(t, parser->lt.token.start, parser->lt.token.end);
      }
      #ifdef SEMANTICS
      t = parser->symbol[sti].term;                // Redefine terminal number?
      #endif
    return sti;
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef NODE_ACTIONS



#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

