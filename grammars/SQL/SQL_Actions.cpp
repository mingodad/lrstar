#include "lrstar_basic_defs.h"
#include "SQL_LexerTables_typedef.h"
#include "SQL_Actions.h"
#include "lrstar_main.h"


void SQL_init_actions(lrstar_parser *parser)
{
      /* Initialization code goes here */
}

void  SQL_term_actions(lrstar_parser *parser)
{
      /* Termination code goes here */
}


int SQL_error(lrstar_parser *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int SQL_lookup(lrstar_parser *parser, int &t)             // Lookup in symbol table.
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
      if (parser->opt_semantics) {
          t = parser->symbol[sti].term;        // Redefine terminal number?
      }
    return sti;
}
o
