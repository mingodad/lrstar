// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__C_Parser_H)
#define __C_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

enum nodecon {
   N_goal_ = 0,
   N_extdef_ = 1,
   N_extdecl_ = 2,
   N_decl_ = 3,
   N_funcdef_ = 4,
   N_funcdecl_ = 5,
   N_funcbody_ = 6,
   N_typespec_ = 7,
   N_storagespec_ = 8,
   N_type_ = 9,
   N_enumspec_ = 10,
   N_structspec_ = 11,
   N_unionspec_ = 12,
   N_storageclass_ = 13,
   N_declarator_ = 14,
   N_declaratorinit_ = 15,
   N_struct_ = 16,
   N_union_ = 17,
   N_structdecl_ = 18,
   N_structdeclarator_ = 19,
   N_enumident_ = 20,
   N_enumequals_ = 21,
   N_directdecl_ = 22,
   N_ident_ = 23,
   N_arraydecl_ = 24,
   N_pointer_ = 25,
   N_argdecl_ = 26,
   N_absargdecl_ = 27,
   N_absarg_ = 28,
   N_absdeclarator_ = 29,
   N_constexp_ = 30,
   N_absarray_ = 31,
   N_absfunc_ = 32,
   N_assign_ = 33,
   N_init_ = 34,
   N_empty_ = 35,
   N_exp_ = 36,
   N_goto_ = 37,
   N_continue_ = 38,
   N_break_ = 39,
   N_return_ = 40,
   N_labeledstmt_ = 41,
   N_block_ = 42,
   N_if_ = 43,
   N_ifelse_ = 44,
   N_switch_ = 45,
   N_while_ = 46,
   N_do_ = 47,
   N_for_ = 48,
   N_case_ = 49,
   N_default_ = 50,
   N_label_ = 51,
   N_condexp_ = 52,
   N_assignment_ = 53,
   N_comma_ = 54,
   N_equals_ = 55,
   N_muleq_ = 56,
   N_diveq_ = 57,
   N_modeq_ = 58,
   N_addeq_ = 59,
   N_subeq_ = 60,
   N_shleq_ = 61,
   N_shreq_ = 62,
   N_andeq_ = 63,
   N_xoreq_ = 64,
   N_oreq_ = 65,
   N_question_ = 66,
   N_or_ = 67,
   N_and_ = 68,
   N_bitor_ = 69,
   N_bitxor_ = 70,
   N_bitand_ = 71,
   N_eq_ = 72,
   N_ne_ = 73,
   N_lt_ = 74,
   N_gt_ = 75,
   N_le_ = 76,
   N_ge_ = 77,
   N_shl_ = 78,
   N_shr_ = 79,
   N_add_ = 80,
   N_sub_ = 81,
   N_mul_ = 82,
   N_div_ = 83,
   N_mod_ = 84,
   N_cast_ = 85,
   N_preinc_ = 86,
   N_predec_ = 87,
   N_complement_ = 88,
   N_addressof_ = 89,
   N_contentsof_ = 90,
   N_positive_ = 91,
   N_negative_ = 92,
   N_not_ = 93,
   N_sizeof_ = 94,
   N_array_ = 95,
   N_member_ = 96,
   N_funccall_ = 97,
   N_ptrto_ = 98,
   N_postinc_ = 99,
   N_postdec_ = 100,
   N_subscript_ = 101,
   N_arguments_ = 102,
   N_string_ = 103,
   N_const_ = 104,
   N_identifier_ = 105,
};

#include "C_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char C_grammar_name[];

typedef lrstar_parser</* grammar           */   C_grammar_name,
                      /* actions           */   true,
                      /* debug_parser      */   false,
                      /* debug_trace       */   false,
                      /* expecting         */   true,
                      /* insensitive       */   false,
                      /* lookaheads        */   1,
                      /* make_ast          */   true,
                      /* nd_parsing        */   false,
                      /* nd_threads        */   0,
                      /* node_actions      */   true,
                      /* reversable        */   false,
                      /* semantics         */   true,
                      /* stksize           */   100,
                      /* term_actions      */   true,
                      /* lexer table type  */   C_lexer_t,
                      /* parser table type */   C_parser_tables_t> C_parser_t;

#endif
