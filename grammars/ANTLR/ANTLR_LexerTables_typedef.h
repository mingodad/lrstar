// Generated by DFA 24.0.016
// DO NOT EDIT.

#if !defined(__ANTLR__LexerTables_TYPEDEF)
#define __ANTLR__LexerTables_TYPEDEF

#include "lrstar_lexer.h"

extern const int8 ANTLR_lgr_term_numb[136];
extern const uint8 ANTLR_lgr_Tm[6441];
extern const uint16 ANTLR_lgr_Tr[136];
extern const uint8 ANTLR_lgr_Tc[256];

template<bool C_debug, typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
class ANTLR_lexer_ : public lrstar_lexer<C_debug, T_term_numb, T_Tm, T_Tr, T_Tc> {
public:
    ANTLR_lexer_(char *input_start) :
      lrstar_lexer<C_debug, T_term_numb, T_Tm, T_Tr, T_Tc>(&ANTLR_lgr_term_numb[0], &ANTLR_lgr_Tm[0], &ANTLR_lgr_Tr[0], &ANTLR_lgr_Tc[0], input_start)
    {

    }


};


typedef ANTLR_lexer_<false, int8, uint8, uint16, uint8> ANTLR_lexer_t;

#endif
