// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__CICS__ParserTables_TYPEDEF)
#define __CICS__ParserTables_TYPEDEF

#include "lrstar_parser_tables.h"

namespace CICS {
extern const char *grm_head_symb[369];
extern const char *grm_tact_name[2];
extern const uint16 grm_head_numb[821];
extern const uint16 grm_f_tail[822];
extern const int16 grm_tail[1488];
extern const char *grm_term_symb[216];
extern const int8 grm_arga[216];
extern const uint8 grm_Bm[310];
extern const uint16 grm_Br[668];
extern const uint8 grm_Bc[216];
extern const uint8 grm_Bf[216];
extern const int16 grm_Tm[1304];
extern const uint16 grm_Tr[668];
extern const uint8 grm_Tc[216];
extern const int16 grm_Nm[733];
extern const uint16 grm_Nr[668];
extern const uint16 grm_Nc[821];
extern const uint8 grm_Rm[1];
extern const uint16 grm_Rr[668];
extern const uint8 grm_Rc[216];
extern const int8 grm_PL[821];
extern const int8 grm_tact_numb[216];


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
   class parser_tables_ : public lrstar_parser_tables<T_term_symb, T_head_symb, T_tact_name, T_node_name, T_head_numb, T_f_tail, T_tail, T_arga, T_argx, T_argy, T_Bm, T_Br, T_Bc, T_Bf, T_Tm, T_Tr, T_Tc, T_Nm, T_Nr, T_Nc, T_Rm, T_Rr, T_Rc, T_PL, T_nd_fterm, T_nd_term, T_nd_faction, T_nd_action, T_tact_numb, T_node_numb, T_nact_numb, T_reverse>   {

public:

      parser_tables_() : lrstar_parser_tables<T_term_symb, T_head_symb, T_tact_name, T_node_name, T_head_numb, T_f_tail, T_tail, T_arga, T_argx, T_argy, T_Bm, T_Br, T_Bc, T_Bf, T_Tm, T_Tr, T_Tc, T_Nm, T_Nr, T_Nc, T_Rm, T_Rr, T_Rc, T_PL, T_nd_fterm, T_nd_term, T_nd_faction, T_nd_action, T_tact_numb, T_node_numb, T_nact_numb, T_reverse>(216, 369, 821, 668, 667, 2, 0, 0, 1, false, &grm_term_symb[0], &grm_head_symb[0], &grm_tact_name[0], 0, &grm_head_numb[0], &grm_f_tail[0], &grm_tail[0], &grm_arga[0], 0, 0, &grm_Bm[0], &grm_Br[0], &grm_Bc[0], &grm_Bf[0], &grm_Tm[0], &grm_Tr[0], &grm_Tc[0], &grm_Nm[0], &grm_Nr[0], &grm_Nc[0], &grm_Rm[0], &grm_Rr[0], &grm_Rc[0], &grm_PL[0], 0, 0, 0, 0, &grm_tact_numb[0], 0, 0, 0)
      {
      }
   };

typedef parser_tables_<const char * const, const char * const, const char * const, const char * const, uint16, uint16, int16, int8, int32, int32, uint8, uint16, uint8, uint8, int16, uint16, uint8, int16, uint16, uint16, uint8, uint16, uint8, int8, int32, int32, int32, int32, int8, int32, int32, int32> parser_tables_t;


};   /* namespace CICS */

#endif
