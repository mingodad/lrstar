
////////////////////////////////////////////////////////////////////////////////
//
//    Vba_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"

      enum nodecon
      {
         N_label = 0,
         N_RemStmt = 1,
         N_DimStmt = 2,
         N_OptionStmt = 3,
         N_ConstStmt = 4,
         N_DeclareStmt = 5,
         N_VarStmt = 6,
         N_TypeStmt = 7,
         N_SubDef = 8,
         N_FuncDef = 9,
         N_BeginDlgStmt = 10,
         N_DoStmt = 11,
         N_ForStmt = 12,
         N_ForEachStmt = 13,
         N_IfStmtComplex = 14,
         N_SelectStmt = 15,
         N_WhileStmt = 16,
         N_WithStmt = 17,
         N_CloseStmt = 18,
         N_DialogStmt = 19,
         N_ExitStmt = 20,
         N_GotoStmt = 21,
         N_GoSubStmt = 22,
         N_IfStmtSimple = 23,
         N_LetStmt = 24,
         N_LineInputStmt = 25,
         N_NameStmt = 26,
         N_OnErrorStmt = 27,
         N_OpenStmt = 28,
         N_PrintStmt = 29,
         N_ResumeStmt = 30,
         N_WriteStmt = 31,
         N_ReturnStmt = 32,
         N_SeekStmt = 33,
         N_SetStmt = 34,
         N_StaticStmt = 35,
         N_StopStmt = 36,
         N_CallObj = 37,
         N_CallSub = 38,
         N_param = 39,
         N_array = 40,
         N_paramname = 41,
         N_var = 42,
         N_type = 43,
         N_subscripts = 44,
         N_size = 45,
         N_start = 46,
         N_end = 47,
         N_step = 48,
         N_ident = 49,
         N_next = 50,
         N_endfunc = 51,
         N_goto = 52,
         N_gosub = 53,
         N_endsub = 54,
         N_add = 55,
         N_sub = 56,
         N_mul = 57,
         N_div = 58,
         N_pow = 59,
         N_mod = 60,
         N_concat = 61,
         N_is_eq = 62,
         N_is_ne = 63,
         N_is_lt = 64,
         N_is_gt = 65,
         N_is_le = 66,
         N_is_ge = 67,
         N_and = 68,
         N_or = 69,
         N_object = 70,
         N_name = 71,
         N_member = 72,
         N_constant = 73,
         N_sub_name = 74,
         N_func_name = 75,
         N_const_name = 76,
         N_array_name = 77,
         N_type_name = 78,
         N_object_name = 79,
         N_string = 80
      };


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   139]; // Terminal symbols of the grammar.
         static const char *head_symb[   181]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const char *node_name[    81]; // Node names found in the grammar.
         static const uint8  head_numb[   405]; // Head symbol number for a production.
         static const uint16 f_tail   [   406]; // First tail in a production.
         static const int16  tail     [   830]; // Tail symbol number.
         static const int8   arga     [   139]; // Arguments for terminal actions.
         static int8   argx     [   405]; // First arguments for productions.
         static int16  argy     [   405]; // Second arguments for productions.

         private:
         static const uint8  Bm[   892]       ; // Boolean matrix.
         static const uint16 Br[   453]       ; // Boolean matrix row.
         static const uint8  Bc[   139]       ; // Boolean matrix column.
         static const uint8 Bf[   139]       ; // Boolean matrix filter/mask.
         static const int16  Tm[  1439]       ; // Terminal transition matrix.
         static const uint16 Tr[   453]       ; // Terminal transition matrix row.
         static const uint8  Tc[   139]       ; // Terminal transition matrix column.
         static const int16  Nm[  4121]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   453]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   405]       ; // Nonterminal transition matrix column.
         static const uint16 Rm[   265]       ; // Reduction matrix.
         static const int16  Rr[   453]       ; // Reduction matrix row.
         static const uint8  Rc[   139]       ; // Reduction matrix column.
         static const int8   PL[   405]       ; // Production length minus one.

         static const int8   tact_numb[   139]; // Terminal action numbers.
         static const int8   node_numb[   405]; // Node numbers for the productions.
         static const int8   nact_numb[   405]; // Node action numbers for the productions.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
         static int    (*nact_func[   81]) (void* v); // Node action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

