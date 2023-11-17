#pragma once

#include "COBOL_Parser.h"

class lrstar_parser;


void COBOL_init_actions(lrstar_parser *parser);
void COBOL_term_actions(lrstar_parser *parser);


int COBOL_error(lrstar_parser *parser, int &t);
int COBOL_lookup(lrstar_parser *parser, int &t);
