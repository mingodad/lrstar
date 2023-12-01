/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#include "CM_Global.h"
#include "LG_Global.h"
#include "LG_CreateTables.h"

enum {
   ts_TermNumb,
   ts_Tm,
   ts_Tr,
   ts_Tc,
   ts_N_ELEMENTS
} type_sizes;

struct data_types_t {           /* Tm, Tr, Tc, term_numb */
   const char *type;            /* C type, string form. */
   int         n_elem;          /* Number of elements in array. */
};
static data_types_t data_types[ts_N_ELEMENTS];


static const char *
get_typestr(int *x, int n)
{
   int i, max = 0, min = 0;
   for (i = 0; i < n; i++)
   {
      if (x[i] > max) max = x[i];
      else if (x[i] < min) min = x[i];
   }
   if (min >= 0)
   {
      if      (max <=        127) return ("uint8"  ); // 1 byte
      else if (max <=        255) return ("uint8"  ); // 1 byte
      else if (max <=      32767) return ("uint16" ); // 2 bytes
      else if (max <=      65535) return ("uint16" ); // 2 bytes
      else if (max <= 2147483647) return ("uint32" ); // 4 bytes
      else                        return ("uint32" ); // 4 bytes
   }
   else if (max > -min)
   {
      if      (max <=        127) return ("int8"   ); // 1 byte
      else if (max <=      32767) return ("int16"  ); // 2 bytes
      else                        return ("int32"  ); // 4 bytes
   }
   else
   {
      if      (min >=       -127) return ("int8"   ); // 1 byte
      else if (min >=     -32767) return ("int16"  ); // 2 bytes
      else                        return ("int32"  ); // 4 bytes
   }
   return (""); // never gets here, avoid compiler error.
}



static size_t
filename_remaining(char       *s,
                   size_t      s_len) /* Elements in s. */
{
   // Returns number of bytes left in 's' for character storage.
   // Leaves 1 byte of space at the end for '\0'.

   size_t len = strlen(s);
   if (len < s_len) {
      return s_len - len - 1;
   } else {
      return 0;
   }
}


static void
create_filename(char       *dst,
                size_t      dst_len, /* Elements in dst. */
                const char *dname,   /* Directory. */
                const char *fname,   /* Filename base. */
                const char *cname,   /* Parser name. */
                const char *suffix,  /* Optional filename suffix. */
                const char *ext)     /* Extension. */
{
   strncpy(dst, dname, dst_len - 1);
   strncat(dst, fname, filename_remaining(dst, dst_len));
   strncat(dst, cname, filename_remaining(dst, dst_len));
   strncat(dst, suffix, filename_remaining(dst, dst_len));
   strncat(dst, ext, filename_remaining(dst, dst_len));
   dst[dst_len - 1] = '\0';
}


static const char *
template_decl(void)
{
   static const char *decl = ("template<"
                              "bool C_debug, "
                              "typename T_term_numb, "
                              "typename T_Tm, "
                              "typename T_Tr, "
                              "typename T_Tc>");
   return decl;
}


static const char *
lexer_decl(void)
{
   static const char *inst = ("templ_lrstar_lexer<C_debug, T_term_numb, "
                              "T_Tm, T_Tr, T_Tc>");
   return inst;
}


static void
lexer_inst(char *buf, size_t buf_len)
{
   static const char *b[] = { "false", "true" };
   snprintf(buf, buf_len,
            "templ_lrstar_lexer<%s, %s, %s, %s, %s>",
            b[!!optn[LG_DEBUG]],
            data_types[ts_TermNumb].type,
            data_types[ts_Tm].type,
            data_types[ts_Tr].type,
            data_types[ts_Tc].type);
}



static void open_guard(FILE *fp,
                       const char *fname,
                       const char *cname,
                       const char *ident)
{
   fprintf(fp, "// Generated by %s %s\n// DO NOT EDIT.\n\n", program, version);
   fprintf(fp,
           ("#if !defined(__%s_%s_%s)\n"
            "#define __%s_%s_%s\n\n"),
           fname, cname, ident,
           fname, cname, ident);
}

static void close_guard(FILE *fp)
{
   fprintf(fp, "\n#endif\n");
}


void
LG::instantiate_lexer(const char *dname,
                      const char *fname,
                      const char *cname,
                      const char *lexer_instantiation)
{
   FILE *fp;
   char pathname[PATH_MAX];

   create_filename(pathname, PATH_MAX, dname, fname, cname,
                   "", ".cpp");

   fp = fopen(pathname, "w");
   if (fp == NULL) {
      prt_log("Output file '%s' cannot be created.\n", pathname);
      Quit();
   }

   fprintf(fp,
           "#include \"lrstar_basic_defs.h\"\n"
           "#include \"lrstar_lexer.h\"\n"
           "#include \"%s_LexerTables_typedef.h\"\n\n", fname);

   if (optn [LG_DEBUG]) {
      fprintf(fp, "      #define DEBUG_LEXER\n");
   }
   fprintf(fp, "#define MAX    0x80000000\n\n");

   if (n_constants > 0) {
      int i;
      fprintf(fp, "enum terminal {\n");
      for (i = 0; i < n_constants-1; i++) {
         fprintf(fp, "   %s = %d,\n", Defcon_name[i], Defcon_value[i]);
      }
      fprintf(fp, "   %s = %d\n", Defcon_name[i], Defcon_value[i]);
      fprintf(fp, "};\n\n");
   }

   fprintf(fp,
           "template<>\n"
           "const int %s_lexer_t::n_term_numb = %d;\n",
           fname, data_types[ts_TermNumb].n_elem);
   fprintf(fp,
           "template<>\n"
           "const int %s_lexer_t::n_Tm = %d;\n",
           fname, data_types[ts_Tm].n_elem);
   fprintf(fp,
           "template<>\n"
           "const int %s_lexer_t::n_Tr = %d;\n",
           fname, data_types[ts_Tr].n_elem);
   fprintf(fp,
           "template<>\n"
           "const int %s_lexer_t::n_Tc = %d;\n\n",
           fname, data_types[ts_Tc].n_elem);


   fprintf(fp, "// Terminal number ...\n");
   fprintf(fp, "static const %s term_numb_[%d] = { \n",
           data_types[ts_TermNumb].type, N_states);
   for (int i = 0; i < N_states; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", D_red[i]);
      }
      else fprintf(fp, "%5d, ", D_red[i]);
   }
   fprintf(fp, "\n};\n\n");
   fprintf(fp,
           "template<>\n"
           "const %s *%s_lexer_t::term_numb = &term_numb_[0];\n\n",
           data_types[ts_TermNumb].type, fname);


   fprintf(fp, "// Terminal transition matrix ...\n");
   fprintf(fp, "static const %s Tm_[%d] = {\n",
           data_types[ts_Tm].type, T_size);
   for (int i = 0; i < T_size; i++) {
      if (i % 10 == 0) {
         if (T_matrix[i] == INT_MAX) {
            fprintf(fp, "\n   %5s, ", "  MAX");
         } else {
            fprintf(fp, "\n   %5d, ", T_matrix[i]);
         }
      } else {
         if (T_matrix[i] == INT_MAX) {
            fprintf(fp, "%5s, ", "  MAX");
         } else {
            fprintf(fp, "%5d, ", T_matrix[i]);
         }
      }
   }
   fprintf(fp, "\n};\n\n");

   fprintf(fp,
           "template<>\n"
           "const %s *%s_lexer_t::Tm = &Tm_[0];\n\n",
           data_types[ts_Tm].type, fname);

   if (optn[LG_TABL_MEDIUM])
   {
      fprintf(fp, "// Terminal transition matrix row ...\n");
      fprintf(fp, "static const %s Tr_[%d] = { \n",
              data_types[ts_Tr].type, tt_states);
      for (int i = 0; i < tt_states; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", T_row[i]);
         } else {
            fprintf(fp, "%5d, ", T_row[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
      fprintf(fp,
              "template<>\n"
              "const %s *%s_lexer_t::Tr = &Tr_[0];\n\n",
              data_types[ts_Tr].type, fname);
   } else {
      fprintf(fp,
              "template<>\n"
              "const %s *%s_lexer_t::Tr = 0;\n\n",
              data_types[ts_Tr].type, fname);
   }


   if (optn[LG_TABL_MEDIUM])
   {
      fprintf(fp, "// Terminal transition matrix column ...\n");
      fprintf(fp, "static const %s Tc_[%d] = {\n",
              data_types[ts_Tc].type, N_terms);
      for (int i = 0; i < N_terms; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n%5d, ", T_col[i]);
         } else {
            fprintf(fp, "%5d, ", T_col[i]);
         }
      }
      fprintf(fp, "\n};\n\n");

      fprintf(fp,
              "template<>\n"
              "const %s *%s_lexer_t::Tc = &Tc_[0];\n\n",
              data_types[ts_Tc].type, fname);

   } else {
      fprintf(fp,
              "template<>\n"
              "const %s *%s::Tc = 0;\n\n",
              data_types[ts_Tc].type, fname);
   }
   fclose(fp);
}


static void
typedef_lexer(const char *dname,
              const char *fname,
              const char *cname,
              const char *lexer_instantiation)
{
   FILE *fp;
   char pathname[PATH_MAX];

   create_filename(pathname, PATH_MAX, dname, fname, cname,
                   "_typedef", ".h");

   fp = fopen(pathname, "w");
   if (fp == NULL) {
      prt_log("Output file '%s' cannot be created.\n", pathname);
      Quit();
   }

   open_guard(fp, fname, cname, "TYPEDEF");
   fprintf(fp, "#include \"lrstar_lexer.h\"\n");
   fprintf(fp, "typedef %s %s_lexer_t;\n", lexer_instantiation, fname);
   close_guard(fp);
   fclose(fp);
}


void LG::GenerateLexerDefines ()
{
   const char *lexer_class = "_LexerTables";
   char        lexer[128];

   // T_matrix ...

   data_types[ts_Tm].type   = get_typestr (T_matrix, T_size);
   data_types[ts_Tm].n_elem = T_size;

   // T_matrix row ...
   if (optn[LG_TABL_MEDIUM])
   {
      data_types[ts_Tr].type = get_typestr (T_row, tt_states);
      data_types[ts_Tr].n_elem = tt_states;
   }

   // T_matrix column ...
   if (optn[LG_TABL_MEDIUM])
   {
      data_types[ts_Tc].type = get_typestr (T_col, N_terms);
      data_types[ts_Tc].n_elem = N_terms;
   }

   // Terminal Numbers (one for for each state) ...
   if (optn[LG_TABL_MEDIUM])
   {
      data_types[ts_TermNumb].type = get_typestr (D_red, N_states);
      data_types[ts_TermNumb].n_elem = N_states;
   }

   lexer_inst(lexer, 128);
   LG::instantiate_lexer(gdn, gfn, "_Lexer", lexer);
   typedef_lexer(gdn, gfn, lexer_class, lexer);
}

//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
