// Generated by DFA 24.0.016
// DO NOT EDIT.

#if !defined(__JSON__LexerTables_TYPEDEF)
#define __JSON__LexerTables_TYPEDEF

#include "lrstar_lexer.h"

namespace JSON {
    extern const int8 lgr_term_numb[33];
    extern const uint8 lgr_Tm[616];
    extern const uint16 lgr_Tr[33];
    extern const uint8 lgr_Tc[256];

    template<bool C_debug, typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
    class lexer_ : public lrstar_lexer<C_debug, T_term_numb, T_Tm, T_Tr, T_Tc>
    {
    public:
        lexer_(char *input_start) :
            lrstar_lexer<C_debug, T_term_numb, T_Tm, T_Tr, T_Tc>(&lgr_term_numb[0], &lgr_Tm[0], &lgr_Tr[0], &lgr_Tc[0], input_start)
        {
        }
    };

    typedef lexer_<false, int8, uint8, uint16, uint8> lexer_t;

};   /* namespace JSON */

#endif
