
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "CICS_LexerTables_typedef.h"
#include "CICS_Actions.h"
#include "lrstar_main.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef ACTIONS

void CICS_init_actions(lrstar_parser *parser)
{
      /* Initialization code goes here */
}

void  CICS_term_actions(lrstar_parser *parser)
{
      /* Termination code goes here */
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef TERM_ACTIONS

int CICS_error(lrstar_parser *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int CICS_lookup(lrstar_parser *parser, int &t)             // Lookup in symbol table.
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
      t = parser->symbol[sti].term;        // Redefine terminal number?
      #endif
    return sti;
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef NODE_ACTIONS



#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

