// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__NCSA__ParserTables_TYPEDEF)
#define __NCSA__ParserTables_TYPEDEF

#include "lrstar_parser_tables.h"

namespace NCSA {
extern const char *grm_head_symb[25];
extern const char *grm_tact_name[2];
extern const char *grm_node_name[11];
extern const uint8 grm_head_numb[62];
extern const uint8 grm_f_tail[63];
extern const int8 grm_tail[114];
extern const char *grm_term_symb[24];
extern const int8 grm_arga[24];
extern const uint8 grm_Bm[57];
extern const uint8 grm_Br[38];
extern const uint8 grm_Bc[24];
extern const uint8 grm_Bf[24];
extern const int8 grm_Tm[99];
extern const uint8 grm_Tr[38];
extern const uint8 grm_Tc[24];
extern const int8 grm_Nm[72];
extern const uint8 grm_Nr[38];
extern const uint8 grm_Nc[62];
extern const uint8 grm_Rm[6];
extern const int8 grm_Rr[38];
extern const uint8 grm_Rc[24];
extern const uint8 grm_PL[62];
extern const int8 grm_tact_numb[24];
extern const int8 grm_argx[62];
extern const int8 grm_argy[62];
extern const int8 grm_node_numb[62];
extern const int8 grm_nact_numb[62];


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

      parser_tables_() : lrstar_parser_tables<T_term_symb, T_head_symb, T_tact_name, T_node_name, T_head_numb, T_f_tail, T_tail, T_arga, T_argx, T_argy, T_Bm, T_Br, T_Bc, T_Bf, T_Tm, T_Tr, T_Tc, T_Nm, T_Nr, T_Nc, T_Rm, T_Rr, T_Rc, T_PL, T_nd_fterm, T_nd_term, T_nd_faction, T_nd_action, T_tact_numb, T_node_numb, T_nact_numb, T_reverse>(24, 25, 62, 38, 37, 2, 11, 11, 1, true, &grm_term_symb[0], &grm_head_symb[0], &grm_tact_name[0], &grm_node_name[0], &grm_head_numb[0], &grm_f_tail[0], &grm_tail[0], &grm_arga[0], &grm_argx[0], &grm_argy[0], &grm_Bm[0], &grm_Br[0], &grm_Bc[0], &grm_Bf[0], &grm_Tm[0], &grm_Tr[0], &grm_Tc[0], &grm_Nm[0], &grm_Nr[0], &grm_Nc[0], &grm_Rm[0], &grm_Rr[0], &grm_Rc[0], &grm_PL[0], 0, 0, 0, 0, &grm_tact_numb[0], &grm_node_numb[0], &grm_nact_numb[0], 0)
      {
      }
   };

typedef parser_tables_<const char * const, const char * const, const char * const, const char * const, uint8, uint8, int8, int8, int8, int8, uint8, uint8, uint8, uint8, int8, uint8, uint8, int8, uint8, uint8, uint8, int8, uint8, uint8, int32, int32, int32, int32, int8, int8, int8, int32> parser_tables_t;


};   /* namespace NCSA */

#endif
