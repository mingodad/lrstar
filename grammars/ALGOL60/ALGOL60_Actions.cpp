
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "ALGOL60_LexerTables_typedef.h"
#include "ALGOL60_Actions.h"
#include "lrstar_main.h"


void ALGOL60_init_actions(lrstar_parser *parser)
{
      /* Initialization code goes here */
}

void  ALGOL60_term_actions(lrstar_parser *parser)
{
      /* Termination code goes here */
}


#ifdef TERM_ACTIONS

int ALGOL60_error(lrstar_parser *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int ALGOL60_lookup(lrstar_parser *parser, int &t)             // Lookup in symbol table.
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

