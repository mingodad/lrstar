
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "SQL_LexerTables_typedef.h"
#include "SQL_Parser.h"
#include "lrstar_main.h"


void SQL_init_actions(SQL_parser_t *parser)
{
      /* Initialization code goes here */
}

void  SQL_term_actions(SQL_parser_t *parser)
{
      /* Termination code goes here */
}


int SQL_error(SQL_parser_t *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int SQL_lookup(SQL_parser_t *parser, int &t)              // Lookup in symbol table.
{
      int sti;
      if (parser->opt_nd_parsing() && parser->lt.lookahead.start != 0)             // In lookahead mode?
      {
         sti = parser->add_symbol(t, parser->lt.lookahead.start, parser->lt.lookahead.end);
      } else {                             // Regular mode of parsing.
         sti = parser->add_symbol(t, parser->lt.token.start, parser->lt.token.end);
      }
      if (parser->opt_semantics()) {
         t = parser->symbol[sti].term;        // Redefine terminal number?
      }
    return sti;
}


