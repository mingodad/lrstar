#pragma once

#include "CICS_Parser.h"

class lrstar_parser;


void CICS_init_actions(lrstar_parser *parser);
void CICS_term_actions(lrstar_parser *parser);


int CICS_error(lrstar_parser *parser, int &t);
int CICS_lookup(lrstar_parser *parser, int &t);
