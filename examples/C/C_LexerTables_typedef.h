// Generated by DFA 24.0.016
// DO NOT EDIT.

#if !defined(__C__LexerTables_TYPEDEF)
#define __C__LexerTables_TYPEDEF

#include "lrstar_lexer.h"

extern const int8 C_lgr_term_numb[207];
extern const uint8 C_lgr_Tm[7666];
extern const uint16 C_lgr_Tr[207];
extern const uint8 C_lgr_Tc[256];

template<bool C_debug, typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
class C_lexer_ : public lrstar_lexer<C_debug, T_term_numb, T_Tm, T_Tr, T_Tc> {
public:
    C_lexer_(char *input_start) :
      lrstar_lexer<C_debug, T_term_numb, T_Tm, T_Tr, T_Tc>(&C_lgr_term_numb[0], &C_lgr_Tm[0], &C_lgr_Tr[0], &C_lgr_Tc[0], input_start)
    {

    }


};


typedef C_lexer_<false, int8, uint8, uint16, uint8> C_lexer_t;

#endif
