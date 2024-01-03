// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__C11__ParserTables_TYPEDEF)
#define __C11__ParserTables_TYPEDEF

#include "lrstar_parser_tables.h"

extern const char *C11_grm_head_symb[78];
extern const char *C11_grm_tact_name[2];
extern const uint8 C11_grm_head_numb[275];
extern const uint16 C11_grm_f_tail[276];
extern const int8 C11_grm_tail[647];
extern const char *C11_grm_term_symb[99];
extern const int8 C11_grm_arga[99];
extern const uint8 C11_grm_Bm[276];
extern const uint16 C11_grm_Br[256];
extern const uint8 C11_grm_Bc[99];
extern const uint8 C11_grm_Bf[99];
extern const int16 C11_grm_Tm[1352];
extern const uint16 C11_grm_Tr[256];
extern const uint8 C11_grm_Tc[99];
extern const int16 C11_grm_Nm[3182];
extern const uint16 C11_grm_Nr[256];
extern const uint8 C11_grm_Nc[275];
extern const uint8 C11_grm_Rm[10];
extern const int16 C11_grm_Rr[256];
extern const uint8 C11_grm_Rc[99];
extern const uint8 C11_grm_PL[275];
extern const int8 C11_grm_tact_numb[99];
extern const uint8 C11_grm_nd_fterm[257];
extern const uint8 C11_grm_nd_term[2];
extern const uint8 C11_grm_nd_faction[3];
extern const int16 C11_grm_nd_action[4];


template<typename T_term_symb,
         typename T_head_symb,
         typename T_tact_name,
         typename T_node_name,
         typename T_head_numb,
         typename T_f_tail,
         typename T_tail,
         typename T_arga,
         typename T_argx,
         typename T_argy,
         typename T_Bm,
         typename T_Br,
         typename T_Bc,
         typename T_Bf,
         typename T_Tm,
         typename T_Tr,
         typename T_Tc,
         typename T_Nm,
         typename T_Nr,
         typename T_Nc,
         typename T_Rm,
         typename T_Rr,
         typename T_Rc,
         typename T_PL,
         typename T_nd_fterm,
         typename T_nd_term,
         typename T_nd_faction,
         typename T_nd_action,
         typename T_tact_numb,
         typename T_node_numb,
         typename T_nact_numb,
         typename T_reverse>
   class C11_parser_tables_ : public lrstar_parser_tables<T_term_symb, T_head_symb, T_tact_name, T_node_name, T_head_numb, T_f_tail, T_tail, T_arga, T_argx, T_argy, T_Bm, T_Br, T_Bc, T_Bf, T_Tm, T_Tr, T_Tc, T_Nm, T_Nr, T_Nc, T_Rm, T_Rr, T_Rc, T_PL, T_nd_fterm, T_nd_term, T_nd_faction, T_nd_action, T_tact_numb, T_node_numb, T_nact_numb, T_reverse>   {

public:

      C11_parser_tables_() : lrstar_parser_tables<T_term_symb, T_head_symb, T_tact_name, T_node_name, T_head_numb, T_f_tail, T_tail, T_arga, T_argx, T_argy, T_Bm, T_Br, T_Bc, T_Bf, T_Tm, T_Tr, T_Tc, T_Nm, T_Nr, T_Nc, T_Rm, T_Rr, T_Rc, T_PL, T_nd_fterm, T_nd_term, T_nd_faction, T_nd_action, T_tact_numb, T_node_numb, T_nact_numb, T_reverse>(99, 78, 275, 256, 255, 2, 0, 0, 1, false, &C11_grm_term_symb[0], &C11_grm_head_symb[0], &C11_grm_tact_name[0], 0, &C11_grm_head_numb[0], &C11_grm_f_tail[0], &C11_grm_tail[0], &C11_grm_arga[0], 0, 0, &C11_grm_Bm[0], &C11_grm_Br[0], &C11_grm_Bc[0], &C11_grm_Bf[0], &C11_grm_Tm[0], &C11_grm_Tr[0], &C11_grm_Tc[0], &C11_grm_Nm[0], &C11_grm_Nr[0], &C11_grm_Nc[0], &C11_grm_Rm[0], &C11_grm_Rr[0], &C11_grm_Rc[0], &C11_grm_PL[0], &C11_grm_nd_fterm[0], &C11_grm_nd_term[0], &C11_grm_nd_faction[0], &C11_grm_nd_action[0], &C11_grm_tact_numb[0], 0, 0, 0)
      {
      }
   };

typedef C11_parser_tables_<const char * const, const char * const, const char * const, const char * const, uint8, uint16, int8, int8, int32, int32, uint8, uint16, uint8, uint8, int16, uint16, uint8, int16, uint16, uint8, uint8, int16, uint8, uint8, uint8, uint8, uint8, int16, int8, int32, int32, int32> C11_parser_tables_t;


#endif
