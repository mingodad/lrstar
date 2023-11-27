// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__Pascal_Parser_H)
#define __Pascal_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

enum nodecon {
   N_Comp_Unit = 0,
   N_Unit_Tree = 1,
   N_Prog_Tree = 2,
   N_Prog_ID = 3,
   N_Use_List = 4,
   N_Unit_Head = 5,
   N_Iface_Part = 6,
   N_Con_Def = 7,
   N_Type_Def = 8,
   N_Var_Decl = 9,
   N_Proc_Func_Heading = 10,
   N_Proc_Head = 11,
   N_Func_Head = 12,
   N_Unit_Impl = 13,
   N_Block = 14,
   N_Lable_Part = 15,
   N_ConDef_Part = 16,
   N_TypeDef_Part = 17,
   N_VarDecl_Part = 18,
   N_ProcFunc_Part = 19,
   N_ConDef_Decl = 20,
   N_Type_Const = 21,
   N_Type_Array = 22,
   N_Type_Record = 23,
   N_Array_Const = 24,
   N_Rec_Const = 25,
   N_Set_Const = 26,
   N_Simple_Type = 27,
   N_Struc_Type = 28,
   N_Pointer_Type = 29,
   N_String_Type = 30,
   N_Proced_Type = 31,
   N_Type_Ident = 32,
   N_Object_Type = 33,
   N_Simp_Ty = 34,
   N_Real_Ty = 35,
   N_Sing_Ty = 36,
   N_Doub_Ty = 37,
   N_Exten_Ty = 38,
   N_Comp_Ty = 39,
   N_Ord_Ty = 40,
   N_SHORTINT = 41,
   N_INTEGER = 42,
   N_BYTE = 43,
   N_LONG = 44,
   N_WORD = 45,
   N_BOOL = 46,
   N_CHAR = 47,
   N_Subrng_Ty = 48,
   N_Enum_Ty = 49,
   N_Str_Ty = 50,
   N_StrucTy = 51,
   N_Array_Ty = 52,
   N_Rec_Ty = 53,
   N_Field_Lst = 54,
   N_Variant_Pt = 55,
   N_Varnt = 56,
   N_TagFld = 57,
   N_Set_Ty = 58,
   N_File_Ty = 59,
   N_Ptr_Ty = 60,
   N_Proc_Type = 61,
   N_Var_Id = 62,
   N_Type_Cst = 63,
   N_Ptr_Deref = 64,
   N_Idx = 65,
   N_Fid = 66,
   N_Ptr = 67,
   N_Typcst = 68,
   N_SimpExp = 69,
   N_LTGTOP = 70,
   N_LTEOP = 71,
   N_GTEOP = 72,
   N_EQOP = 73,
   N_NEQOP = 74,
   N_INOP = 75,
   N_TOP = 76,
   N_Addop = 77,
   N_OROP = 78,
   N_XOROP = 79,
   N_Factor = 80,
   N_MulOp = 81,
   N_DIVOp = 82,
   N_DIVOP = 83,
   N_ModOp = 84,
   N_AndOp = 85,
   N_SHLOP = 86,
   N_SHROP = 87,
   N_Ref = 88,
   N_AtRef = 89,
   N_UsCnst = 90,
   N_Expr = 91,
   N_Negat = 92,
   N_Unary = 93,
   N_FuncCall = 94,
   N_SetCnst = 95,
   N_ValCst = 96,
   N_Predif = 97,
   N_OrdFunc = 98,
   N_OddFunc = 99,
   N_LoFunc = 100,
   N_LenFunc = 101,
   N_HiFunc = 102,
   N_ChrFunc = 103,
   N_AbsFunc = 104,
   N_PredFunc = 105,
   N_PtrFunc = 106,
   N_RndFunc = 107,
   N_SizeFunc = 108,
   N_SuccFunc = 109,
   N_SwapFunc = 110,
   N_TruncFunc = 111,
   N_CNum = 112,
   N_CString = 113,
   N_CId = 114,
   N_CNil = 115,
   N_FCall = 116,
   N_Set = 117,
   N_SetList = 118,
   N_ValTpCst = 119,
   N_Stmt_Pt = 120,
   N_Stmt = 121,
   N_Simp_Stmt = 122,
   N_Asg_Stmt = 123,
   N_Prc_Stmt = 124,
   N_Goto_Stmt = 125,
   N_CmpdS = 126,
   N_Cond = 127,
   N_Rept = 128,
   N_With = 129,
   N_Cond_Stmt = 130,
   N_If_Stmt = 131,
   N_Case_Stmt = 132,
   N_Case_Part = 133,
   N_Else_Pt = 134,
   N_RptSmt = 135,
   N_Repeat_Stmt = 136,
   N_While_Stmt = 137,
   N_For_Stmt = 138,
   N_WithStmt = 139,
   N_Proc_Decl = 140,
   N_Func_Decl = 141,
   N_Proc_Def = 142,
   N_Func_Def = 143,
   N_Func_Code = 144,
   N_Func_For = 145,
   N_Func_Ext = 146,
   N_Func_Asm = 147,
   N_Parm_El = 148,
   N_Proc_Code = 149,
   N_Proc_For = 150,
   N_Proc_Ext = 151,
   N_Proc_Asm = 152,
   N_Inline_Dir = 153,
   N_Inline_Element = 154,
   N_OBJ_Ty = 155,
   N_Heritg = 156,
   N_Method_list = 157,
   N_Proc_Meth = 158,
   N_Func_Meth = 159,
   N_Cnst_Meth = 160,
   N_Dest_Meth = 161,
   N_O_Field = 162,
   N_No_Init = 163,
   N_Init_Stmts = 164,
   N_Con = 165,
   N_Obj_Id = 166,
   N_Qual_Id = 167,
   N_Id = 168,
   N_LID = 169,
   N_TID = 170,
   N_VID = 171,
   N_PID = 172,
   N_FID = 173,
   N_FiId = 174,
   N_ORDId = 175,
   N_Int = 176,
   N_Numb = 177,
   N_Str = 178,
   N_SiP = 179,
   N_SiM = 180,
   N_Up = 181,
   N_Down = 182,
   N_LTH = 183,
   N_GTH = 184,
};

#include "Pascal_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char Pascal_grammar_name[];

typedef lrstar_parser</* grammar           */   Pascal_grammar_name,
                      /* actions           */   true,
                      /* debug_parser      */   false,
                      /* debug_trace       */   false,
                      /* expecting         */   true,
                      /* insensitive       */   true,
                      /* lookaheads        */   1,
                      /* make_ast          */   true,
                      /* nd_parsing        */   false,
                      /* nd_threads        */   0,
                      /* node_actions      */   true,
                      /* reversable        */   false,
                      /* semantics         */   true,
                      /* stksize           */   100,
                      /* term_actions      */   true,
                      /* lexer table type  */   Pascal_lexer_t,
                      /* parser table type */   Pascal_parser_tables_t> Pascal_parser_t;

#endif
