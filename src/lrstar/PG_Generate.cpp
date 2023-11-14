/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#include <assert.h>
#include <stdio.h>

#include "lrstar_basic_defs.h"
#include "CM_Global.h"
#include "PG_Main.h"
#include "PG_CreateTables.h"

typedef enum field_name_t {
#define PFL(pf_) PF(pf_)
#define PF(pf_) ts_T_##pf_,
   PARSER_FIELDS
#undef PF
#undef PFL
   ts_N_ELEMENTS
} field_name_t;


struct data_types_t {
   const char *type;            /* C type, string form. */
   int         n_elem;          /* Number of elements in array.
                                 * 0 => none.
                                 */
};


typedef void (*file_writer_fn_t)(FILE       *fp,
                                 const char *pathname,
                                 const char *grammar,
                                 const char *fname);


static data_types_t data_types[ts_N_ELEMENTS];


static const char *get_typestr(int *x, int n)
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


static void
print_defines(FILE *fp)
{
   int nl = 1;

   fprintf (fp, "      #undef  GRAMMAR\n");          // In case of multiple parsers.
   fprintf (fp, "      #undef  ACTIONS\n");          // In case of multiple parsers.
   fprintf (fp, "      #undef  TERM_ACTIONS\n");     // In case of multiple parsers.
   fprintf (fp, "      #undef  NODE_ACTIONS\n");     // In case of multiple parsers.
   fprintf (fp, "      #undef  INSENSITIVE\n");      // In case of multiple parsers.
   fprintf (fp, "      #undef  LOOKAHEADS\n");       // In case of multiple parsers.
   fprintf (fp, "      #undef  DEBUG_PARSER\n");     // In case of multiple parsers.
   fprintf (fp, "      #undef  DEBUG_TRACE\n");      // In case of multiple parsers.
   fprintf (fp, "      #undef  MAKE_AST\n");         // In case of multiple parsers.
   fprintf (fp, "      #undef  EXPECTING\n");        // In case of multiple parsers.
//    fprintf (fp, "      #undef  ERRORUSED\n");        // In case of multiple parsers.
   fprintf (fp, "      #undef  REVERSABLE\n");       // In case of multiple parsers.
   fprintf (fp, "      #undef  SEMANTICS\n");        // In case of multiple parsers.
   fprintf (fp, "      #undef  ND_PARSING\n");       // In case of multiple parsers.
   fprintf (fp, "      #undef  ND_THREADS\n");       // In case of multiple parsers.

   if (PG_Main::n_ndstates > 0) nl = optn[PG_LOOKAHEADS];

   fprintf (fp, "\n      #define GRAMMAR      \"%s\"\n",           gfn);
   if (PG_Main::N_tacts > 0 || PG_Main::N_nacts > 0) {
      fprintf (fp, "      #define ACTIONS       %s_Actions\n",      gfn);
   }
   if (PG_Main::N_tacts > 0) {
      fprintf (fp, "      #define TERM_ACTIONS  %s_TermActions\n",  gfn);
   }
   if (PG_Main::N_nacts > 0) {
      fprintf (fp, "      #define NODE_ACTIONS  %s_NodeActions\n",  gfn);
   }
   if (optn[PG_INSENSITIVE])                 fprintf (fp, "      #define INSENSITIVE\n");
   fprintf (fp, "      #define LOOKAHEADS  %3d\n", nl);
   if (optn[PG_DEBUG])                       fprintf (fp, "      #define DEBUG_PARSER\n");
   if (optn[PG_DEBUGTRACE])                  fprintf (fp, "      #define DEBUG_TRACE\n");
   if (optn[PG_ASTCONST] && PG_Main::N_nodes > 0) {
      fprintf (fp, "      #define MAKE_AST\n");
   }
   if (optn[PG_EXPECTING] || PG_Main::error_used > 0) {
      fprintf (fp, "      #define EXPECTING\n");
   }
//    if (error_used > 0)                       fprintf (fp, "      #define ERRORUSED\n");
   if (PG_Main::N_reverses > 0) {
      fprintf (fp, "      #define REVERSABLE\n");
   }
   if (PG_Main::N_semantics > 0) {
      fprintf (fp, "      #define SEMANTICS\n");
   }
   if (PG_Main::n_ndstates > 0)
   {
      fprintf (fp, "      #define ND_PARSING\n");
      fprintf (fp, "      #define ND_THREADS  %3d\n", PG_Main::nd_maxcount);
   }
}


static const char *
template_decl(void)
{
#define PF(pf_) "typename T_" #pf_ ", "
#define PFL(pfl_) "typename T_" #pfl_
   static const char *decl = "template<" PARSER_FIELDS ">";
#undef PF
#undef PFL
   return decl;
}


static const char *
parser_tables_decl(void)
{
#define PF(pf_) "T_" #pf_ ", "
#define PFL(pfl_) "T_" #pfl_
   static const char *inst = "templ_lrstar_parser_tables<" PARSER_FIELDS ">";
#undef PF
#undef PFL
   return inst;
}


static void
parser_tables_inst(char *buf, size_t buf_len)
{

   snprintf(buf, buf_len,
            "templ_lrstar_parser_tables<"
#define PF(pf_) "%s, "
#define PFL(pfl_) "%s"
PARSER_FIELDS
#undef PF
#undef PFL
            ">",
#define PF(pf_)   data_types[ts_T_##pf_].type,
#define PFL(pfl_) data_types[ts_T_##pfl_].type
PARSER_FIELDS
#undef PF
#undef PFL
      );
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




static void
templ_init_functions(FILE *fp, int N_tacts, int N_nacts)
{
   if (N_tacts > 0 || N_nacts > 0) {
      fprintf(fp,
              "void %s_init_actions(lrstar_parser *parser); "
              "/* User-supplied */\n"
              "void %s_term_actions(lrstar_parser *parser); "
              "/* User-supplied */\n"
              "static init_func_t %s_init_funcs_[2] = {\n"
              "   %s_init_actions,\n"
              "   %s_term_actions\n"
              "};\n\n", gfn, gfn, gfn, gfn, gfn);
      fprintf(fp,
              "// Init action function pointers ...\n"
              "%s\n"
              "init_func_t *%s::init_func = &%s_init_funcs_[0];\n\n",
              template_decl(), parser_tables_decl(), gfn);
   } else {
      fprintf(fp,
              "// Init action function pointers ...\n"
              "%s\n"
              "init_func_t *%s::init_func = 0;\n\n",
              template_decl(), parser_tables_decl());
   }
}



static void
templ_tact_functions(FILE *fp, int N_tacts, const char **Tact_start)
{
   if (N_tacts > 0) { // Number of terminal actions.
      // Token Actions ...
      for (int t = 0; t < N_tacts; t++) {
         fprintf (fp, "int %s_%s(lrstar_parser *parser, int &t);\n",
                  gfn, Tact_start[t]);
      }
      fprintf(fp,
              "// Terminal action function pointers ...\n"
              "static tact_func_t %s_tact_funcs_[%d] = {\n",
              gfn, N_tacts);
      for (int t = 0; t < N_tacts; t++) {
         fprintf (fp, "   %s_%s,\n", gfn, Tact_start[t]);
      }
      fprintf (fp, "};\n\n");

      fprintf(fp,
              "// Terminal action function pointers ...\n"
              "%s\n"
              "tact_func_t *%s::tact_func = &%s_tact_funcs_[0];\n\n",
              template_decl(), parser_tables_decl(), gfn);
   } else {
      fprintf(fp,
              "// Terminal action function pointeras ...\n"
              "%s\n"
              "tact_func_t *%s::tact_func = 0;\n\n",
              template_decl(), parser_tables_decl());
   }
}


static void
templ_nact_functions(FILE *fp, int N_nacts, const char **Nact_start)
{
   if (N_nacts > 0) {           // Number of node actions
      for (int n = 0; n < N_nacts; n++) {
         if (strcmp (Nact_start[n], "NULL") != 0) {
            fprintf(fp, "int %s_%s(lrstar_parser *parser, Node *node);\n",
                    gfn, Nact_start[n]);
         }
      }

      fprintf(fp, "// Node action function pointers ...\n");
      fprintf(fp, "static nact_func_t %s_nact_func_[%d] = {\n", gfn, N_nacts);
      for (int n = 0; n < N_nacts; n++) {
         if (strcmp (Nact_start[n], "NULL") == 0) {
            fprintf(fp, "   0,\n");
         } else {
            fprintf(fp, "   %s_%s,\n",  gfn, Nact_start[n]);
         }
      }
      fprintf(fp, "};\n\n");
      fprintf(fp,
              "// Node action function pointers ...\n"
              "%s\n"
              "nact_func_t *%s::nact_func = &%s_nact_func_[0];\n\n",
              template_decl(), parser_tables_decl(), gfn);
   } else {
      fprintf(fp,
              "// Node action function pointers ...\n"
              "%s\n"
              "nact_func_t *%s::nact_func = 0;\n\n",
              template_decl(), parser_tables_decl());
   }
}


static void
instantiate_field_lengths(FILE *fp)
{
   /* Define the lengths of each array field. */
#define PFL(_field) PF(_field)
#define PF(_field)                                       \
   fprintf(fp, ("%s\n"                                   \
                "const int %s::n_" #_field " = %d;\n\n"  \
                ""),                                     \
           template_decl(), parser_tables_decl(),        \
           data_types[ts_T_##_field].n_elem);
   PARSER_FIELDS
#undef PF
#undef PFL
}


void
PG_Main::instantiate_constants(FILE *fp)
{
   // Special constants in the parser.
   fprintf(fp,
           "%s\n"
           "const int %s::n_terms = %d; "
           "// Number of terminals.\n\n",
           template_decl(), parser_tables_decl(), N_terms);

   fprintf(fp,
           "%s\n"
            "const int %s::n_heads      =%5d; "
            "// Number of nonterminals.\n",
           template_decl(), parser_tables_decl(), N_heads);

   fprintf(fp,
           "%s\n"
           "const int %s::n_prods = %d; "
           "// Number of productions.\n",
           template_decl(), parser_tables_decl(), N_prods);

   fprintf(fp,
           "%s\n"
           "const int %s::n_states = %d; "
           "// Number of states.\n",
           template_decl(), parser_tables_decl(), N_states);

   fprintf(fp,
           "%s\n"
           "const int %s::accept_state = %d; "
           "// Accept state.\n",
           template_decl(), parser_tables_decl(), Accept_state);

   fprintf(fp,
           "%s\n"
           "const int %s::n_termactns = %d; "
           "// Number of terminal actions.\n",
           template_decl(), parser_tables_decl(), N_tacts);

   fprintf(fp,
           "%s\n"
           "const int %s::n_nodenames = %d; "
           "// Number of node names.\n",
           template_decl(), parser_tables_decl(), N_nodes);

   fprintf(fp,
           "%s\n"
           "const int %s::n_nodeactns = %d; "
           "// Number of node actions.\n",
           template_decl(), parser_tables_decl(), N_nacts);

   fprintf(fp,
           "%s\n"
           "const int %s::eof_symb = %d; "
           "// <eof> symbol number.\n",
           template_decl(), parser_tables_decl(), eof_term);

   fprintf(fp,
           "%s\n"
           "const int %s::err_used = %d; "
           "// <error> used in grammar?\n\n",
           template_decl(), parser_tables_decl(), error_used);
}

void PG_Main::instantiate_term_symb_data(FILE *fp)
{
   fprintf(fp, "// Terminal symbols of the grammar.\n");
   fprintf(fp, "static const char *term_symb_[%d] = {\n",
           data_types[ts_T_term_symb].n_elem);
   for (int i = 0; i < N_terms; i++) {
      fprintf(fp, "   \"%s\",\n", make_term(term_name[i]));
   }
   fprintf(fp, "};\n\n");
}


void PG_Main::instantiate_head_symb_data(FILE *fp)
{
   fprintf(fp, "// Nonterminal symbols of the grammar.\n");
   fprintf(fp, "static const char *head_symb_[%d] = {\n",
           data_types[ts_T_head_symb].n_elem);
   for (int i = 0; i < N_heads; i++) {
      fprintf(fp, "   \"%s\",\n", head_name[i]);
   }
   fprintf(fp, "};\n\n");
}


void PG_Main::instantiate_tact_name_data(FILE *fp)
{
   fprintf(fp, "// Terninal action names found in the grammar ...\n");
   fprintf(fp, "static const char *tact_name_[%d] = {\n",
           data_types[ts_T_tact_name].n_elem);
   for (int i = 0; i < N_tacts; i++) {
      fprintf (fp, "   \"%s\",\n", Tact_start[i]);
   }
   fprintf (fp, "};\n\n");
}


void PG_Main::instantiate_node_name_data(FILE *fp)
{
   if (N_nodes > 0) {
      fprintf(fp, "// Node names found in the grammar.\n");
      fprintf(fp, "static const char * node_name_[%d] = {\n", N_nodes);
      for (int i = 0; i < N_nodes; i++) {
         fprintf(fp, "   \"%s,\"", Node_start[i]);
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_text_str_data(FILE *fp)
{
   assert(false);               /* XXX this is not used? */
}


void PG_Main::instantiate_head_numb_data(FILE *fp)
{
   fprintf(fp, "// Head symbol numbers for the productions.\n");
   fprintf(fp, "static const %s head_numb_[%d] = {",
           data_types[ts_T_head_numb].type,
           data_types[ts_T_head_numb].n_elem);
   for (int i = 0; i < N_prods; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", head_sym[i]);
      }
      else {
         fprintf(fp, "%5d, ", head_sym[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_f_tail_data(FILE *fp)
{
   fprintf(fp, "// First tail symbol index into the tail list ...\n");
   fprintf(fp, "static const %s f_tail_[%d] = {",
           data_types[ts_T_f_tail].type,
           data_types[ts_T_f_tail].n_elem);
   for (int i = 0; i < N_prods+1; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", F_tail[i]);
      }
      else fprintf(fp, "%5d, ", F_tail[i]);
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_tail_data(FILE *fp)
{
   fprintf(fp, "// Tail symbol numbers ...\n");
   fprintf(fp, "static const %s tail_[%d] = {",
            data_types[ts_T_tail].type,
            data_types[ts_T_tail].n_elem);
   for (int i = 0; i < N_tails; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", Tail[i]);
      }
      else fprintf(fp, "%5d, ", Tail[i]);
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_arga_data(FILE *fp)
{
   if (N_tacts > 0) {
      int *Arga = new int[N_terms];
      for (int i = 0; i < N_terms; i++) {
         if (N_targ[i] > 0) {
            Arga[i] = Arg_numb[F_targ[i]];
         } else {
            Arga[i] = -1;
         }
      }
      fprintf(fp, "// Arguments for token actions ...\n");
      fprintf(fp, "static const %s arga_[%d] = {",
              data_types[ts_T_arga].type,
              data_types[ts_T_arga].n_elem);
      for (int i = 0; i < N_terms; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", Arga[i]);
         }
         else {
            fprintf(fp, "%5d, ", Arga[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
      delete [] Arga;
   }
}


void PG_Main::instantiate_Bm_data(FILE *fp)
{
   if (optn[PG_BOOLMATRIX] > 0) {
      // B_matrix ...
      fprintf(fp, "// Boolean matrix ...\n");
      fprintf(fp, "static const uint8 Bm_[%d] = {", B_size);
      if (optn[PG_BOOLMATRIX] == 1) { // char
         for (int i = 0; i < B_size; i++) {
            int x = static_cast<uint8>(B_matrix[i]);
            if (i % 10 == 0) {
               fprintf(fp, "\n   %d, ", x);
            }
            else {
               fprintf(fp, "%d, ", x);
            }
         }
      } else if (optn[PG_BOOLMATRIX] == 2) { // bits
         for (int i = 0; i < B_size; i++) {
            int x = static_cast<uint8>(B_matrix[i]);
            if (i % 10 == 0) {
               fprintf(fp, "\n   %5d, ", x);
            } else {
               fprintf(fp, "%5d, ", x);
            }
         }
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_Br_data(FILE *fp)
{
   if (optn[PG_BOOLMATRIX] > 0) {
      fprintf(fp, "// Boolean matrix row (for state)...\n");
      fprintf(fp, "static const %s Br_[%d] = {",
              data_types[ts_T_Br].type,
              data_types[ts_T_Br].n_elem);
      for (int i = 0; i < N_states; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", B_row[i]);
         } else {
            fprintf(fp, "%5d, ", B_row[i]);
         }
      }
      fprintf(fp, "\n      };\n\n");
   }
}


void PG_Main::instantiate_Bc_data(FILE *fp)
{
   if (optn[PG_BOOLMATRIX] > 0) {
      fprintf(fp, "// Boolean matrix column (displacement) ...\n");
      fprintf(fp, "static const %s Bc_[%d] = {",
              data_types[ts_T_Bc].type,
              data_types[ts_T_Bc].n_elem);
      for (int i = 0; i < N_terms; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", B_col[i]);
         }
         else {
            fprintf(fp, "%5d, ", B_col[i]);
         }
      }
      fprintf(fp, "\n      };\n\n");
   }
}


void PG_Main::instantiate_Bf_data(FILE *fp)
{
   if (optn[PG_BOOLMATRIX] > 1) {
      // B_matrix mask ...
      fprintf(fp, "// Boolean matrix filter/mask value ...\n");
      fprintf(fp, "static const uint8 Bf_[%d] = {", N_terms);
      for (int i = 0; i < N_terms; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", B_mask[i]);
         }
         else {
            fprintf(fp, "%5d, ", B_mask[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_Tm_data(FILE *fp)
{
   fprintf(fp, "// Terminal transition matrix ...\n");
   fprintf(fp, "static const %s Tm_[%d] = {",
           data_types[ts_T_Tm].type,
           data_types[ts_T_Tm].n_elem);
   for (int i = 0; i < T_size; i++)
   {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", T_matrix[i]);
      } else {
         fprintf(fp, "%5d, ", T_matrix[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_Tr_data(FILE *fp)
{
   fprintf(fp, "// Terminal transition matrix row ...\n");
   fprintf(fp, "static const %s Tr_[%d] = {",
           data_types[ts_T_Tr].type,
           data_types[ts_T_Tr].n_elem);
   for (int i = 0; i < tt_states; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", T_row[i]);
      } else {
         fprintf(fp, "%5d, ", T_row[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_Tc_data(FILE *fp)
{
   fprintf(fp, "// Terminal transition matrix column ...\n");
   fprintf(fp, "static const %s Tc_[%d] = {",
           data_types[ts_T_Tc].type,
           data_types[ts_T_Tc].n_elem);

   for (int i = 0; i < N_terms; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", T_col[i]);
      } else {
         fprintf(fp, "%5d, ", T_col[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_Nm_data(FILE *fp)
{
   fprintf(fp, "// Nonterminal transition matrix ...\n");
   fprintf(fp, "static const %s Nm_[%d] = {",
           data_types[ts_T_Nm].type,
           data_types[ts_T_Nm].n_elem);
   for (int i = 0; i < N_size; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", N_matrix[i]);
      } else {
         fprintf(fp, "%5d, ", N_matrix[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_Nr_data(FILE *fp)
{
   fprintf(fp, "// Nonterminal transition matrix row ...\n");
   fprintf(fp, "static const %s Nr_[%d] = {",
           data_types[ts_T_Nr].type,
           data_types[ts_T_Nr].n_elem);
   for (int i = 0; i < ntt_states; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n%5d, ", N_row[i]);
      } else {
         fprintf(fp, "%5d, ", N_row[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_Nc_data(FILE *fp)
{
   fprintf(fp, "// Nonterminal transition matrix column ...\n");
   fprintf(fp, "static const %s Nc_[%d] = {",
           data_types[ts_T_Nc].type,
           data_types[ts_T_Nc].n_elem);
   for (int i = 0; i < N_prods; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n%5d, ", N_col[i]);
      } else {
         fprintf(fp, "%5d, ", N_col[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_Rm_data(FILE *fp)
{
   fprintf(fp, "// Reduction matrix ...\n");
   fprintf(fp, "static const %s Rm_[%d] = {",
           data_types[ts_T_Rm].type,
           data_types[ts_T_Rm].n_elem);
   for (int i = 0; i < R_size; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", R_matrix[i]);
      } else {
         fprintf(fp, "%5d, ", R_matrix[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_Rr_data(FILE *fp)
{
   fprintf(fp, "// Reduction matrix row ...\n");
   fprintf(fp, "static const %s Rr_[%d] = {",
           data_types[ts_T_Rr].type,
           data_types[ts_T_Rr].n_elem);
   for (int i = 0; i < N_states; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", R_row[i]);
      } else {
         fprintf(fp, "%5d, ", R_row[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_Rc_data(FILE *fp)
{
   fprintf(fp, "// Reduction matrix column ...\n");
   fprintf(fp, "static const %s Rc_[%d] = {",
           data_types[ts_T_Rc].type,
           data_types[ts_T_Rc].n_elem);
   for (int i = 0; i < N_terms; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", R_col[i]);
      } else {
         fprintf(fp, "%5d, ", R_col[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_PL_data(FILE *fp)
{
   fprintf(fp, "// Production lengths (minus one) ...\n");
   fprintf(fp, "static const %s PL_[%d] = {",
           data_types[ts_T_PL].type,
           data_types[ts_T_PL].n_elem);
   for (int i = 0; i < N_prods; i++) {
      if (i % 10 == 0) {
         fprintf(fp, "\n   %5d, ", prod_len[i]);
      } else {
         fprintf(fp, "%5d, ", prod_len[i]);
      }
   }
   fprintf(fp, "\n};\n\n");
}


void PG_Main::instantiate_tact_numb_data(FILE *fp)
{
   if (N_tacts > 0) {           // Number of terminal actions.
      fprintf(fp, "// Terminal action number ...\n");
      fprintf(fp, "static const %s tact_numb_[%d] = {",
              data_types[ts_T_tact_numb].type,
              data_types[ts_T_tact_numb].n_elem);
      for (int i = 0; i < N_terms; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", Tact_numb[i]);
         } else {
            fprintf(fp, "%5d, ", Tact_numb[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_argx_data(FILE *fp)
{
   if (N_nodes > 0 || N_semantics > 0) {
      int* Argx = new int[N_prods];
      for (int i = 0; i < N_prods; i++) {
         if (N_parg[i] > 0) {
            Argx[i] = Arg_numb[F_parg[i]] - 1;
         } else {
            Argx[i] = -1;
         }
      }
      fprintf(fp, "// First arguments for productions ...\n");
      fprintf(fp, "static const %s argx_[%d] = {",
              data_types[ts_T_argx].type,
              data_types[ts_T_argx].n_elem);
      for (int i = 0; i < N_prods; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", Argx[i]);
         } else {
            fprintf(fp, "%5d, ", Argx[i]);
         }
      }
      fprintf(fp, "\n};\n\n");

      delete [] Argx;
   }
}


void PG_Main::instantiate_argy_data(FILE *fp)
{
   if (N_semantics > 0) {
      int *Argy = new int[N_prods];
      for (int i = 0; i < N_prods; i++) {
         if (N_parg[i] > 1) {
            Argy[i] = Arg_numb[F_parg[i]+1];
         } else {
            Argy[i] = -1;
         }
      }

      fprintf(fp, "// Second arguments for productions ...\n");
      fprintf(fp, "static const %s argy_[%d] = {",
               data_types[ts_T_argy].type,
               data_types[ts_T_argy].n_elem);

      for (int i = 0; i < N_prods; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", Argy[i]);
         } else {
            fprintf(fp, "%5d, ", Argy[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
      delete [] Argy;
   }
}


void PG_Main::instantiate_nd_fterm_data(FILE *fp)
{
   if (n_ndstates > 0) {
      // Nondeterministic Items (terminals) in a state ...
      int count = N_states + 1;
      fprintf(fp, "// Nondeterministic first terminal in the list ...\n");
      fprintf(fp, "static const %s nd_fterm_[%d] = {",
              data_types[ts_T_nd_fterm].type,
              data_types[ts_T_nd_fterm].n_elem);
      for (int i = 0; i < count; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", nd_item[i]);
         } else {
            fprintf(fp, "%5d, ", nd_item[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_nd_term_data(FILE *fp)
{
   if (n_ndstates > 0) {
      // Nondeterministic Terminal List ...
      int count = n_ndterms;
      fprintf(fp, "// Nondeterministic terminal list ...\n");
      fprintf(fp, "const %s nd_term_[%d] = {",
              data_types[ts_T_nd_term].type,
              data_types[ts_T_nd_term].n_elem);
      for (int i = 0; i < count; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", nd_term[i]);
         } else {
            fprintf(fp, "%5d, ", nd_term[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_nd_faction_data(FILE *fp)
{
   if (n_ndstates > 0) {
      // Nondeterministic Start of a terminal's actions for state ...
      int count = n_ndterms + 1;
      fprintf(fp, "// Nondeterministic first action in the list ...\n");
      fprintf(fp, "static const %s nd_faction_[%d] = {",
              data_types[ts_T_nd_faction].type,
              data_types[ts_T_nd_faction].n_elem);
      for (int i = 0; i < count; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", nd_start[i]);
         } else {
            fprintf(fp, "%5d, ", nd_start[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_nd_action_data(FILE *fp)
{
   if (n_ndstates > 0) {
      // Nondeterministic Action ...
      int count = n_nditems;
      fprintf(fp, "// Nondeterministic actions list ...\n");
      fprintf(fp, "static const %s nd_action_[%d] = {",
              data_types[ts_T_nd_action].type,
              data_types[ts_T_nd_action].n_elem);
      for (int i = 0; i < count; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", nd_action[i]);
         } else {
            fprintf(fp, "%5d, ", nd_action[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_node_numb_data(FILE *fp)
{
   if (optn[PG_ASTCONST] > 0 && N_nodes > 0) {
      fprintf(fp, "// Node number for each production ...\n");
      fprintf(fp, "static const %s node_numb_[%d] = {",
              data_types[ts_T_node_numb].type,
              data_types[ts_T_node_numb].n_elem);
      for (int i = 0; i < N_prods; i++) {
         if (i % 10 == 0) {
            fprintf(fp, "\n   %5d, ", Node_numb[i]);
         } else {
            fprintf(fp, "%5d, ", Node_numb[i]);
         }
      }
      fprintf(fp, "\n};\n\n");
   }
}


void PG_Main::instantiate_nact_numb_data(FILE *fp)
{
   if (optn[PG_ASTCONST] > 0 && N_nodes > 0) {
      if (N_nacts > 0) {
         fprintf(fp, "// Node action numbers ...\n");
         fprintf(fp, "static const %s nact_numb_[%d] = {",
                 data_types[ts_T_nact_numb].type,
                 data_types[ts_T_nact_numb].n_elem);
         for (int i = 0; i < N_prods; i++) {
            if (i % 10 == 0) {
               fprintf(fp, "\n   %5d, ", Nact_numb[i]);
            } else {
               fprintf(fp, "%5d, ", Nact_numb[i]);
            }
         }
         fprintf(fp, "\n};\n\n");
      }
   }
}


void PG_Main::instantiate_reverse_data(FILE *fp)
{
   if (optn[PG_ASTCONST] > 0 && N_nodes > 0) {
      if (N_reverses > 0) {
         // Reverse the order of nodes (for a production/rule) ...
         fprintf(fp, "// Reverse the order of nodes ...\n");
         fprintf(fp, "static const uint8 reverse_[%d] = {", N_prods);
         for (int i = 0; i < N_prods; i++) {
            if (i % 10 == 0) {
               fprintf(fp, "\n   %5d, ", Reverse[i]);
            } else {
               fprintf(fp, "%5d, ", Reverse[i]);
            }
         }
         fprintf(fp, "\n};\n\n");
      }
   }
}


void
PG_Main::instantiate_fields(FILE *fp)
{
#define PFL(field_) PF(field_)
#define PF(field_)                                                \
      if (data_types[ts_T_##field_].n_elem != 0) {                \
         instantiate_##field_##_data(fp);                         \
         fprintf(fp, ("%s\n"                                      \
                      "const T_%s *%s::" #field_ " = &%s[0];\n\n" \
                      ""),                                        \
                 template_decl(),                                 \
                 #field_,                                         \
                 parser_tables_decl(),                            \
                 #field_ "_");                                    \
         fflush(fp); /* XXX remove this */                        \
      } else {                                                    \
         fprintf(fp, ("%s\n"                                      \
                      "const T_%s *%s::" #field_ " = 0;\n\n"      \
                      ""),                                        \
                 template_decl(),                                 \
                 #field_,                                         \
                 parser_tables_decl());                           \
      }
   PARSER_FIELDS
#undef PF
#undef PFL

   templ_init_functions(fp, N_tacts, N_nacts);
   templ_tact_functions(fp, N_tacts, Tact_start);
   templ_nact_functions(fp, N_nacts, Nact_start);
}


void
PG_Main::instantiate_tables(const char  *dname,
                            const char  *fname,
                            const char  *cname,
                            const char  *parser_instantiation)
{
   FILE *fp;
   char pathname[PATH_MAX];

   create_filename(pathname, PATH_MAX, dname, fname, cname,
                   "_instantiate", ".h");

   fp = fopen(pathname, "w");
   if (fp == NULL) {
      prt_log("Output file '%s' cannot be created.\n", pathname);
      Quit();
   }

   open_guard(fp, fname, cname, "INSTANTIATE");
   fprintf(fp,
           "// Include this file only once in a project.\n"
           "//  It instantiates a parser.\n");

   instantiate_field_lengths(fp);
   instantiate_constants(fp);
   instantiate_fields(fp);
   close_guard(fp);
   fclose(fp);
}


void
PG_Main::typedef_tables(const char *dname,
                        const char *fname,
                        const char *cname,
                        const char *tables_instantiation)
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
   fprintf(fp, "#include \"lrstar_parser_tables.h\"\n");
   fprintf(fp, "typedef %s parser_tables_t;\n", tables_instantiation);
   close_guard(fp);
   fclose(fp);
}


void
PG_Main::generate_tables(const char  *dname,
                         const char  *fname,
                         const char  *cname)
{
   char parser[512];

   parser_tables_inst(parser, sizeof(parser) / sizeof(parser[0]));
   instantiate_tables(dname, fname, cname, parser);
   typedef_tables(dname, fname, cname, parser);
}


static void
set_data_type_void(field_name_t field_name)
{
   data_types[field_name].type   = "void";
   data_types[field_name].n_elem = 0;
}


static bool
init_functions(FILE *header, FILE *tables, bool newline,
               int N_tacts, int N_nacts)
{
   if (N_tacts > 0 || N_nacts > 0) {
   }
   return newline;
}



static bool
tact_functions(FILE *header, FILE *tables, bool newline,
               int N_tacts, const char **Tact_start)
{
#if 0
   if (N_tacts > 0) { // Number of terminal actions.
      if (newline) {
         fprintf(header, "\n");
         newline = false;
      }
      // Token Actions ...
      fprintf (header,
               "         static int    (*tact_func[%5d])(lrstar_parser *parser, int &t); "
               "// Terminal action function pointers.\n", N_tacts);

      fprintf (tables, "   // Terminal action function pointers ...\n");
      fprintf (tables, "      int (*lrstar_parser_tables::tact_func[%d])(lrstar_parser *parser, int &t) =\n", N_tacts);
      fprintf (tables, "      {\n");
      for (int t = 0; t < N_tacts; t++) {
         if (t > 0) {
            fprintf (tables, ",\n");
         }
         fprintf (tables, "         lrstar_term_actions::%s", Tact_start[t]);
      }
      fprintf (tables, "\n      };\n\n");
   }
#endif
   return newline;
}


static bool
nact_functions(FILE *header, FILE *tables, bool newline,
               int N_nacts, const char **Nact_start)
{
   if (N_nacts > 0) {           // Number of node actions
#if 0
      if (newline) {
         fprintf(header, "\n");
         newline = false;
      }
      // Node Actions ...
      fprintf (header,
               "         static int    (*nact_func[%5d])(lrstar_parser *parser, Node *v); "
               "// Node action function pointers.\n", N_nacts);

      fprintf (tables, "   // Node action function pointers ...\n");
      fprintf (tables, "      int (*lrstar_parser_tables::nact_func[%d])(lrstar_parser *parser, Node *v) = \n", N_nacts);
      fprintf (tables, "      {\n");
      for (int n = 0; n < N_nacts; n++) {
         if (n > 0) {
            fprintf (tables, ",\n");
         }
         if (strcmp (Nact_start[n], "NULL") == 0) {
            fprintf (tables, "         0");
         } else {
            fprintf (tables, "         lrstar_node_actions::%s",  Nact_start[n]);
         }
      }
      fprintf (tables, "\n      };\n\n");
#endif
   }
   return newline;
}


void  PG_Main::GenerateParserTables ()
{
   int   i;
   int   count;
   FILE* header;
   FILE* tables;
   const char* name  = "_ParserTables";
   char  filename_h  [PATH_MAX];
   char  filename_hpp[PATH_MAX];

   create_filename(filename_h, PATH_MAX, gdn, gfn, name, "", ".h");
   if (chmod (filename_h, S_IWRITE) == 0) // File can be written ?
   {
      if (unlink (filename_h) != 0) // Delete it?
      {
         if (++n_errors == 1) prt_log ("\n");
         prt_log ("Output file '%s' cannot be written!\n\n", filename_h);
         Quit();
      }
   }
   header = fopen (filename_h, "w");
   if (header == NULL)
   {
      if (++n_errors == 1) prt_log("\n");
      prt_log("Output file '%s' cannot be written!\n\n", filename_h);
      Quit();
   }
   prt_logonly ("Generating: %s\n", filename_h);

   create_filename(filename_hpp, PATH_MAX, gdn, gfn, name, "", ".hpp");
   if (chmod (filename_hpp, S_IWRITE) == 0) // File can be written ?
   {
      if (unlink (filename_hpp) != 0) // Delete it?
      {
         if (++n_errors == 1) prt_log ("\n");
         prt_log ("Output file '%s' cannot be written!\n\n", filename_hpp);
         Quit ();
      }
   }
   tables = fopen (filename_hpp, "w");
   if (tables == NULL)
   {
      if (++n_errors == 1) prt_log ("\n");
      prt_log ("Output file '%s' cannot be written!\n\n", filename_hpp);
      Quit ();
   }

   prt_logonly ("Generating: %s\n\n", filename_hpp);

   if (optn[PG_TERMACTIONS ] == 0) N_tacts = 0;
   if (optn[PG_NODEACTIONS ] == 0) N_nacts = 0;


   fprintf (header, "\n");
   fprintf (header, "//\n");
   fprintf (header, "//    %s (generated by %s %s)\n", filename_h, program, version);
   fprintf (header, "\n");

   fprintf (header, "#pragma once\n\n");
   fprintf (header, "#include \"lrstar_library_defs.h\"\n");

   fprintf (header, "\n");

   if (n_constants > 0) {
      fprintf(header, "enum termcon {\n");
      for (i = 0; i < n_constants; i++) {
         fprintf(header, "   %s = %d,\n", Defcon_name[i], Defcon_value[i]);
      }
      fprintf (header, "};\n\n");
   }

   if (N_nodes > 0 && optn[PG_ASTCONST] > 0) {
      fprintf (header, "enum nodecon {\n");
      for (int i = 0; i < N_nodes; i++) {
         fprintf(header, "   N_%s = %d,\n", Node_start[i], i);
      }
      fprintf (header, "};\n\n");
   }

   data_types[ts_T_term_symb].type   = "const char *";
   data_types[ts_T_term_symb].n_elem = N_terms;

   data_types[ts_T_head_symb].type   = "const char *";
   data_types[ts_T_head_symb].n_elem = N_heads;

   data_types[ts_T_tact_name].type    = "const char *";
   data_types[ts_T_tact_name].n_elem  = N_tacts;

   data_types[ts_T_node_name].type   = "const char *";
   data_types[ts_T_node_name].n_elem = N_nodes;

   data_types[ts_T_text_str].type    = "const char *";
   data_types[ts_T_text_str].n_elem  = N_strings;

   nd_optimize ();

   fprintf (tables, "\n");
   fprintf (tables, "////////////////////////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (tables, "//\n");
   fprintf (tables, "//    %s (generated by %s %s)\n\n", filename_hpp, program, version);

   fprintf (tables, "      #include \"lrstar_basic_defs.h\"\n");
   fprintf (tables, "      #include \"lrstar_parser_tables.h\"\n");
   fprintf (tables, "      #include \"%s_ParserTables.h\"\n", gfn);
   fprintf (tables, "      #include \"%s_Actions.h\"\n\n", gfn);

   // Head numbers for the productions ...
   data_types[ts_T_head_numb].type   = get_typestr (head_sym, N_prods);
   data_types[ts_T_head_numb].n_elem = N_prods;

   // Index to first tail symbol for a production ...
   data_types[ts_T_f_tail].type   = get_typestr (F_tail, N_prods + 1);
   data_types[ts_T_f_tail].n_elem = N_prods + 1;

   // Tail symbol numbers ...
   data_types[ts_T_tail].type   = get_typestr (Tail, N_tails);
   data_types[ts_T_tail].n_elem = N_tails;

   // Arguments for terminal actions ...
   if (N_tacts > 0)
   {
      int* Arga = new int[N_terms];
      for (int i = 0; i < N_terms; i++)
      {
         if (N_targ[i] > 0)
            Arga[i] = Arg_numb[F_targ[i]];
         else
            Arga[i] = -1;
      }
      data_types[ts_T_arga].type   = get_typestr (Arga, N_terms);
      data_types[ts_T_arga].n_elem = N_terms;
   } else {
      set_data_type_void(ts_T_arga);
   }

   // First arguments for productions ...
   if (N_nodes > 0 || N_semantics > 0)
   {
      int* Argx = new int[N_prods];
      for (int i = 0; i < N_prods; i++)
      {
         if (N_parg[i] > 0)
            Argx[i] = Arg_numb[F_parg[i]] - 1;
         else
            Argx[i] = -1;
      }
      data_types[ts_T_argx].type   = get_typestr (Argx, N_prods);
      data_types[ts_T_argx].n_elem = N_prods;
   } else {
      set_data_type_void(ts_T_argx);
   }

   // Second arguments for productions ...
   if (N_semantics > 0)
   {
      int* Argy = new int[N_prods];
      for (int i = 0; i < N_prods; i++)
      {
         if (N_parg[i] > 1)
            Argy[i] = Arg_numb[F_parg[i]+1];
         else
            Argy[i] = -1;
      }

      data_types[ts_T_argy].type   = get_typestr (Argy, N_prods);
      data_types[ts_T_argy].n_elem = N_prods;
   } else {
      set_data_type_void(ts_T_argy);
   }

   if (optn[PG_BOOLMATRIX] > 0)
   {
      // B_matrix ...
      data_types[ts_T_Bm].type   = "uint8";
      data_types[ts_T_Bm].n_elem = B_size;

      // B_matrix row ...
      data_types[ts_T_Br].type   = get_typestr (B_row, N_states);
      data_types[ts_T_Br].n_elem = N_states;

      // B_matrix column ...
      data_types[ts_T_Bc].type   = get_typestr (B_col, N_terms);
      data_types[ts_T_Bc].n_elem = N_terms;

      if (optn[PG_BOOLMATRIX] > 1)
      {
         // B_matrix mask ...
         data_types[ts_T_Bf].type   = "uint8";
         data_types[ts_T_Bf].n_elem = N_terms;
      }
   }

   // T_matrix ...
   data_types[ts_T_Tm].type   = get_typestr (T_matrix, T_size);
   data_types[ts_T_Tm].n_elem = T_size;

   // T_matrix row ...
   data_types[ts_T_Tr].type   = get_typestr (T_row, tt_states);
   data_types[ts_T_Tr].n_elem = tt_states;

   // T_matrix column ...
   data_types[ts_T_Tc].type   = get_typestr (T_col, N_terms);
   data_types[ts_T_Tc].n_elem = N_terms;

   // N_matrix ...
   data_types[ts_T_Nm].type   = get_typestr (N_matrix, N_size);
   data_types[ts_T_Nm].n_elem = N_size;

   // N_matrix row ...
   data_types[ts_T_Nr].type   = get_typestr (N_row, ntt_states);
   data_types[ts_T_Nr].n_elem = ntt_states;

   // N_matrix column ...
   data_types[ts_T_Nc].type   = get_typestr (N_col, N_prods);
   data_types[ts_T_Nc].n_elem = N_prods;

   // R_matrix ...
   data_types[ts_T_Rm].type   = get_typestr (R_matrix, R_size);
   data_types[ts_T_Rm].n_elem = R_size;

   // R_matrix row ...
   data_types[ts_T_Rr].type   = get_typestr (R_row, N_states);
   data_types[ts_T_Rr].n_elem = N_states;

   // R_matrix column ...
   data_types[ts_T_Rc].type   = get_typestr (R_col, N_terms);
   data_types[ts_T_Rc].n_elem = N_terms;

   // Production length - 1 ...
   data_types[ts_T_PL].type   = get_typestr (prod_len, N_prods);
   data_types[ts_T_PL].n_elem = N_prods;

   int newline = 0;
   if (n_ndstates > 0)
   {
      newline = 1;
      // Nondeterministic Items (terminals) in a state ...
      count = N_states + 1;
      data_types[ts_T_nd_fterm].type   = get_typestr (nd_item, count);
      data_types[ts_T_nd_fterm].n_elem = count;

      // Nondeterministic Terminal List ...
      count = n_ndterms;
      data_types[ts_T_nd_term].type   = get_typestr (nd_term, count);
      data_types[ts_T_nd_term].n_elem = count;

      // Nondeterministic Start of a terminal's actions for state ...
      count = n_ndterms + 1;
      data_types[ts_T_nd_faction].type   = get_typestr (nd_start, count);
      data_types[ts_T_nd_faction].n_elem = count;

      // Nondeterministic Action ...
      count = n_nditems;
      data_types[ts_T_nd_action].type   = get_typestr (nd_action, count);
      data_types[ts_T_nd_action].n_elem = count;
   } else {
      set_data_type_void(ts_T_nd_fterm);
      set_data_type_void(ts_T_nd_term);
      set_data_type_void(ts_T_nd_faction);
      set_data_type_void(ts_T_nd_action);
   }

   newline = 0;
   if (N_tacts > 0) // Number of terminal actions.
   {
      newline = 1;
      // Token Action numbers ...
      data_types[ts_T_tact_numb].type   = get_typestr (Tact_numb, N_terms);
      data_types[ts_T_tact_numb].n_elem = N_terms;
   } else {
      set_data_type_void(ts_T_tact_numb);
   }

   if (optn[PG_ASTCONST] > 0 && N_nodes > 0)
   {
      if (newline == 0) {
         newline = 1;
      }
      // Node Number for each production ...
      data_types[ts_T_node_numb].type   = get_typestr (Node_numb, N_prods);
      data_types[ts_T_node_numb].n_elem = N_prods;

      if (N_nacts > 0) // Number of node actions
      {
         // Node Action numbers ...
         data_types[ts_T_nact_numb].type   = get_typestr (Nact_numb, N_prods);
         data_types[ts_T_nact_numb].n_elem = N_prods;
      } else {
         set_data_type_void(ts_T_nact_numb);
      }


      if (N_reverses > 0)
      {
         // Reverse the order of nodes (for a production/rule) ...
         data_types[ts_T_reverse].type   = "uint8";
         data_types[ts_T_reverse].n_elem = N_prods;
      } else {
         set_data_type_void(ts_T_reverse);
      }
   } else {
      set_data_type_void(ts_T_node_numb);
      set_data_type_void(ts_T_nact_numb);
      set_data_type_void(ts_T_reverse);
   }

   fprintf (tables, "\n");

   fprintf(tables, "#include \"%s_ParserTables_instantiate.h\"\n", gfn);
   fclose  (tables);
   chmod   (filename_hpp, S_IREAD); // Make output file read-only.

   fclose  (header);
   chmod   (filename_h, S_IREAD); // Make output file read-only.
   generate_tables(gdn, gfn, name);
};


void actions_header_fn(FILE       *fp,
                       const char *pathname,
                       const char *grammar,
                       const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, "#pragma once\n");
   fprintf (fp, "\n");
   fprintf (fp, "#include \"%s_Parser.h\"\n", grammar);
   fprintf (fp, "\n");
   fprintf (fp, "class lrstar_parser;\n");
   fprintf (fp, "\n");
   fprintf (fp, "#ifdef ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "void %s_init_actions(lrstar_parser *parser);\n", gfn);
   fprintf (fp, "void %s_term_actions(lrstar_parser *parser);\n", gfn);
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "#ifdef TERM_ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "int %s_error(lrstar_parser *parser, int &t);\n", gfn);
   fprintf (fp, "int %s_lookup(lrstar_parser *parser, int &t);\n", gfn);
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "#ifdef NODE_ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "      class lrstar_node_actions : public lrstar_parser\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         public:\n");
   fprintf (fp, "      };\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void parsertables_header_fn(FILE       *fp,
                                   const char *pathname,
                                   const char *grammar,
                                   const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, "#include \"lrstar_basic_defs.h\"\n");
   if (lrstar_linux) {
      fprintf (fp, "#include \"lrstar_lexer.h\"\n");
   }
   print_defines(fp);
   fprintf (fp, "#include \"%s_ParserTables.h\"\n", grammar);
   if (lrstar_linux) {
      fprintf (fp, "#include \"%s_ParserTables_typedef.h\"\n", grammar);
      fprintf (fp, "#include \"lrstar_parser.h\"\n");
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/lexer.h\"\n");
      fprintf (fp, "#include \"../../code/parser.h\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void actions_cpp_fn(FILE       *fp,
                           const char *pathname,
                           const char *grammar,
                           const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, ("#include \"lrstar_basic_defs.h\"\n"
                 "#include \"%s_LexerTables_typedef.h\"\n"
                 "#include \"%s_Actions.h\"\n"), grammar, grammar);
   if (lrstar_linux) {
      fprintf (fp, "#include \"lrstar_main.h\"\n");
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/main.h\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "\n");
   fprintf (fp, "#ifdef ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "void %s_init_actions(lrstar_parser *parser)\n", gfn);
   fprintf (fp, "{\n");
   fprintf (fp, "      /* Initialization code goes here */\n");
   fprintf (fp, "}\n");
   fprintf (fp, "\n");
   fprintf (fp, "void  %s_term_actions(lrstar_parser *parser)\n", gfn);
   fprintf (fp, "{\n");
   fprintf (fp, "      /* Termination code goes here */\n");
   fprintf (fp, "}\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "\n");
   fprintf (fp, "#ifdef TERM_ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "int %s_error(lrstar_parser *parser, int &t)\n", gfn);
   fprintf (fp, "{\n");
   fprintf (fp, "      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         parser->lt.token.end++;\n");
   fprintf (fp, "      }\n");
   fprintf (fp, "      return 0;\n");
   fprintf (fp, "}\n");
   fprintf (fp, "\n");
   fprintf (fp, "int %s_lookup(lrstar_parser *parser, int &t)             // Lookup in symbol table.\n", gfn);
   fprintf (fp, "{\n");
   fprintf (fp, "      int sti;\n");
   fprintf (fp, "      #ifdef ND_PARSING\n");
   fprintf (fp, "      if (parser->lt.lookahead.start > 0)             // In lookahead mode?\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         sti = parser->add_symbol(t, parser->lt.lookahead.start, parser->lt.lookahead.end);\n");
   fprintf (fp, "      }\n");
   fprintf (fp, "      else                                 // Regular mode of parsing.\n");
   fprintf (fp, "      #endif\n");
   fprintf (fp, "      {\n");
   fprintf (fp, "         sti = parser->add_symbol(t, parser->lt.token.start, parser->lt.token.end);\n");
   fprintf (fp, "      }\n");
   fprintf (fp, "      #ifdef SEMANTICS\n");
   fprintf (fp, "      t = parser->symbol[sti].term;        // Redefine terminal number?\n");
   fprintf (fp, "      #endif\n");
   fprintf (fp, "    return sti;\n");                       // Return symbol-table index.\n");
   fprintf (fp, "}\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "\n");
   fprintf (fp, "#ifdef NODE_ACTIONS\n");
   fprintf (fp, "\n");
   fprintf (fp, "\n");
   fprintf (fp, "\n");
   fprintf (fp, "#endif\n");
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "\n");
}


static void lexer_cpp_fn(FILE       *fp,
                         const char *pathname,
                         const char *grammar,
                         const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");

   fprintf (fp, "#include \"lrstar_basic_defs.h\"\n");
   if (lrstar_linux) {
      fprintf (fp, "#include \"lrstar_lexer.h\"\n");
   }
   fprintf (fp, ("#include \"%s_LexerTables.h\"\n"
                 "#include \"%s_LexerTables.hpp\"\n"), grammar, grammar);
   if (lrstar_windows) {
      fprintf (fp, "#include \"../../code/lexer.h\"\n");
      fprintf (fp, "#include \"../../code/lexer.cpp\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void main_cpp_fn(FILE       *fp,
                        const char *pathname,
                        const char *grammar,
                        const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, ("#include \"lrstar_basic_defs.h\"\n"
                 "#include \"%s_LexerTables_typedef.h\"\n"
                 "#include \"%s_Parser.h\"\n"), grammar, grammar);
   if (lrstar_linux) {
      fprintf (fp, "#include \"lrstar_main.cpp\"\n");
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/main.cpp\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void parser_cpp_fn(FILE       *fp,
                          const char *pathname,
                          const char *grammar,
                          const char *fname)
{
   fprintf (fp, "\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "\n");
   fprintf (fp, ("#include \"lrstar_basic_defs.h\"\n"
                 "#include \"%s_LexerTables_typedef.h\"\n"
                 "#include \"%s_Parser.h\"\n"
                 "#include \"%s_ParserTables.hpp\"\n"), grammar, grammar, grammar);
   if (lrstar_linux) {
      fprintf (fp, "#include \"lrstar_parser.cpp\"\n");
   } else {
      assert(lrstar_windows);
      fprintf (fp, "#include \"../../code/parser.cpp\"\n");
   }
   fprintf (fp, "\n");
   fprintf (fp, "//                                                                           //\n");
   fprintf (fp, "///////////////////////////////////////////////////////////////////////////////\n\n");
}


static void make_bat_fn(FILE       *fp,
                        const char *pathname,
                        const char *grammar,
                        const char *fname)
{
   // TODO: need grammar name to be passed, too
   fprintf (fp, "rem  This make.bat must be in the same directory as the Visual Studio project files,\n");
   fprintf (fp, "rem  or else the error messages will not have the correct directory name preceeding\n");
   fprintf (fp, "rem  the file name, and clicking on the error messages will not work.\n");
   fprintf (fp, "\n");
   fprintf (fp, "@echo off\n");
   fprintf (fp, "prompt $g$s\n");
   fprintf (fp, "\n");
   fprintf (fp, "..\\..\\bin\\lrstar %s d dt\n", grammar);
   fprintf (fp, "..\\..\\bin\\dfa    %s d\n\n", grammar);
}


static void makefile_fn(FILE       *fp,
                        const char *pathname,
                        const char *grammar,
                        const char *fname)
{
   static const char *make = ("# Build '%s' parser.\n" /* grammar */
                              "\n\n"
                              "CC	:=\t\t\t\\\n"
                              "\tg++\n"
                              "\n\n"
                              "INCLUDES\t:=\t\t\t\\\n"
                              "\t$(LRSTAR_INSTALL_ROOT)/include\n"
                              "\n\n"
                              "DEFINES\t:=\t\t\t\\\n"
                              "\tLRSTAR_LINUX\n"
                              "\n\n"
                              "ERROR_FORMAT\t:=\t\t\t\\\n"
                              "\t-fdiagnostics-color=never\t\t\t\\\n"
                              "\t-fno-diagnostics-show-caret\t\t\t\\\n"
                              "\n\n"
                              "BUILD_TYPE\t:=\t\\\n"
                              "\t$(if $(LRSTAR_BUILD_TYPE),"
                              "$(if $(filter debug,$(LRSTAR_BUILD_TYPE)),"
                              "DEBUG,RELEASE),RELEASE)\n"
                              "\n\n"
                              "CXXFLAGS\t:=\t\t\t\\\n"
                              "\t$(ERROR_FORMAT)\t\t\t\\\n"
                              "\t$(addprefix -I,$(INCLUDES))\t\t\t\\\n"
                              "\t$(addprefix -D,LRSTAR_$(BUILD_TYPE) $(DEFINES))\t\t\t\\\n"
                              "\n\n"
                              "SOURCE\t:=\t\t\t\\\n"
                              "\t%s_Actions.cpp\t\t\t\\\n" /* grammar */
                              "\t%s_Lexer.cpp\t\t\t\\\n"   /* grammar */
                              "\t%s_Main.cpp\t\t\t\\\n"    /* grammar */
                              "\t%s_Parser.cpp\n"          /* grammar */
                              "\n\n"
                              "OBJS\t:= $\t$(SOURCE:.cpp=.o)\n"
                              "\n\n"
                              "%s:\t$(OBJS)\n"          /* grammar */
                              "\t$(CC) -o $@ $(OBJS);\n"
                              "\n\n"
                              "clean:\n"
                              "\trm $(SOURCE) $(OBJS) %s;"); /* grammar */
   fprintf(fp, make, grammar, grammar, grammar,
           grammar, grammar, grammar, grammar);
}


static void write_file(const char       *gdn,
                       const char       *grammar,
                       const char       *fname,
                       const char       *suffix,
                       bool              overwrite,
                       file_writer_fn_t  fn)
{
   char         pathname[PATH_MAX];
   FILE        *fp;
   int          stat_res;
   struct stat  statbuf;
   bool         exists;

   strcpy(pathname, gdn);

   /* If a filename is provided, it overrides the gammar + suffix in
    * the filename.
    */
   if (fname != NULL) {
      strcat(pathname, fname);
   } else {
      strcat(pathname, grammar);
      strcat(pathname, suffix);
   }

   stat_res = stat(pathname, &statbuf);
   exists   = stat_res != -1;

   if (!exists || overwrite) {
      fp = fopen(pathname, "w");

      if (fp != NULL) {
         prt_logonly ("Generating: %s\n", pathname);

         fn(fp, pathname, grammar, fname);
         fclose(fp);
      } else {
         if (++n_errors == 1) {
            prt_log("\n");
         }
         prt_log("Output file '%s' cannot be written!\n\n", pathname);
         Quit();
      }
   }
}


void  PG_Main::GenerateOtherFiles ()
{
   write_file(gdn, gfn, NULL, "_Actions.h", false, actions_header_fn);
   write_file(gdn, gfn, NULL, "_Parser.h", true, parsertables_header_fn);
   write_file(gdn, gfn, NULL, "_Actions.cpp", false, actions_cpp_fn);
   write_file(gdn, gfn, NULL, "_Lexer.cpp", true, lexer_cpp_fn);
   write_file(gdn, gfn, NULL, "_Main.cpp", true, main_cpp_fn);
   write_file(gdn, gfn, NULL, "_Parser.cpp", true, parser_cpp_fn);
   if (lrstar_linux) {
      write_file(gdn, gfn,  "Makefile", "", true, makefile_fn);
   } else {
      assert(lrstar_windows);
      write_file(gdn, gfn, "make.bat", "", true, make_bat_fn);
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Main::nd_optimize()
{
   int i, j, k, n, sum, lastterm;
   // COUNT NUMBER OF TERMINALS FOR NEW LIST ...
   n = 0;
   for (i = 0; i < N_states; i++)
   {
      lastterm = -1;
      if (nd_state[i] > 1) nd_state[i] = 1;
      for (j = nd_item[i]; j < nd_item[i + 1]; j++)
      {
         if (nd_term[j] != lastterm)
         {
            n++;
            lastterm = nd_term[j];
         }
      }
   }
   nd_start = new int[n + 1];
   n_ndterms = n;

   // CREATE NEW TERMINAL LIST AND START VECTOR ...
   n = 0;
   sum = 0;
   for (i = 0; i < N_states; i++)                  // For all states.
   {
      k = 0;                                       // Reset counter.
      lastterm = -1;                               // Reset to unknown.
      for (j = nd_item[i]; j < nd_item[i + 1]; j++)   // For all items in this state.
      {
         if (nd_term[j] != lastterm)   // Another terminal?
         {
            k++;                       // Count of terminals for this state.
            nd_start[n] = j;           // Start of actions for this terminal.
            lastterm = nd_term[j];  // Last terminal seen.
            nd_term[n++] = nd_term[j]; // Move terminal to new position.
         }
      }
      nd_item[i] = sum; // Change to new terminal start for this state.
      sum += k;
   }
   nd_start[n] = j;     // End of actions for last terminal.
   nd_item[i] = sum;   // End of new terminal list for last state.
}

///////////////////////////////////////////////////////////////////////////////

void  PG_Main::prt_prod (FILE* tables, int p, char* before, char* after)
{
   int t, s;
   fprintf (tables, "%s %s -> ", before, head_name[head_sym[p]]);
   for (t = F_tail[p]; t < F_tail[p+1]; t++)
   {
      s = Tail[t];
      if (s >= 0) fprintf (tables, "%s ", term_name[s]);
      else        fprintf (tables, "%s ", head_name[-s]);
   }
   fprintf (tables, "%s", after);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* PG_Main::make_term (const char* s)
{
   static char string[256];
   if (*s == '\'' || *s == '\"')
   {
      int i =  0;
      char ch = *s;
      string[i++] = '\\';
      string[i++] = ch;
      for (const char* p = s+1; *(p+1) != 0; p++)
      {
         string[i++] = *p;
      }
      string[i++] = '\\';
      string[i++] = ch;
      string[i++] = 0;
   }
   else
   {
      int i =  0;
      for (const char* p = s; *p != 0; p++)
      {
         string[i++] = *p;
      }
      string[i++] = 0;
   }
   return (string);
}

//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////



/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
