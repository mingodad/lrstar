
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#include "CM_Global.h"
#include "LG_Global.h"
#include "LG_CreateTables.h"

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
      if      (max <=        127) return ("uchar"  ); // 1 byte
      else if (max <=        255) return ("uchar"  ); // 1 byte
      else if (max <=      32767) return ("ushort" ); // 2 bytes
      else if (max <=      65535) return ("ushort" ); // 2 bytes
      else if (max <= 2147483647) return ("uint"   ); // 4 bytes
      else                        return ("uint"   ); // 4 bytes
   }
   else if (max > -min)
   {
      if      (max <=        127) return ("char"   ); // 1 byte
      else if (max <=      32767) return ("short"  ); // 2 bytes
      else                        return ("int"    ); // 4 bytes
   }
   else
   {
      if      (min >=       -127) return ("char"   ); // 1 byte
      else if (min >=     -32767) return ("short"  ); // 2 bytes
      else                        return ("int"    ); // 4 bytes
   }
   return (""); // never gets here, avoid compiler error.
}


void  LG::GenerateLexerDefines ()
{
   FILE* header;
   char filename_h[PATH_MAX];

   const char* lexer_class = "_LexerTables";

   strcpy (filename_h, gdn);
   strcat (filename_h, gfn);
   strcat (filename_h, lexer_class);
   strcat (filename_h, ".h");

   if (chmod (filename_h, S_IWRITE) == 0) // File can be written ?
   {
      if (unlink (filename_h) != 0) // Delete it?
      {
         if (++n_errors == 1) prt_log ("\n");
         prt_log ("Output file '%s' cannot be written!\n", filename_h);
         Quit();
      }
   }

   header = fopen (filename_h, "w");
   if (header == NULL)
   {
      if (++n_errors == 1) prt_log ("\n");
      prt_log ("Output file '%s' cannot be written!\n", filename_h);
      Quit();
   }
   prt_logonly ("Generating: %s\n", filename_h);

   fprintf (header, "\n");
   fprintf (header, "////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (header, "//\n");
   fprintf (header, "//    %s (generated by %s %s)\n", filename_h, program, version);
   fprintf (header, "\n");

   fprintf (header, "      #pragma once\n\n");

   fprintf (header, "      #undef  LEXER\n");            // In case of multiple lexers.
   fprintf (header, "      #undef  DEBUG_LEXER\n\n");    // In case of multiple lexers.

   fprintf (header, "      #define LEXER         %s_Lexer\n", gfn);
   if (optn [LG_DEBUG]) fprintf (header, "      #define DEBUG_LEXER\n");

   fprintf (header, "\n/*\n");

   FILE* tables;
   char filename_hpp[PATH_MAX];
   char* make_term (char*);
   const char* vartype;

   strcpy (filename_hpp, gdn);
   strcat (filename_hpp, gfn);
   strcat (filename_hpp, lexer_class);
   strcat (filename_hpp, ".hpp");

   if (chmod (filename_hpp, S_IWRITE) == 0) // File can be written ?
   {
      if (unlink (filename_hpp) != 0) // Delete it?
      {
         if (++n_errors == 1) prt_log ("\n");
         prt_log ("Output file '%s' cannot be written!\n", filename_hpp);
         Quit();
      }
   }

   tables = fopen (filename_hpp, "w");
   if (tables == NULL)
   {
      if (++n_errors == 1) prt_log ("\n");
      prt_log ("Output file '%s' cannot be written!\n", filename_hpp);
      Quit();
   }
   prt_logonly ("Generating: %s\n\n", filename_hpp);

   fprintf (tables, "\n");
   fprintf (tables, "////////////////////////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (tables, "//\n");
   fprintf (tables, "//    %s (generated by %s %s)\n\n", filename_hpp, program, version);

   fprintf (tables, "      #define uint   unsigned int\n");
   fprintf (tables, "      #define uchar  unsigned char\n");
   fprintf (tables, "      #define ushort unsigned short\n");
   fprintf (tables, "      #define MAX    0x80000000\n\n");

   // T_matrix ...
   vartype = get_typestr (T_matrix, T_size);
   fprintf (header, "      static %-6s Tm[%6d]        ; // Terminal transition matrix.\n", vartype, T_size);
   fprintf (tables, "   // Terminal transition matrix ...\n");
   fprintf (tables, "      static %s Tm[%d] = \n", vartype,T_size);
   fprintf (tables, "      {");
   for (int i = 0; i < T_size; i++)
   {
      if (i % 20 == 0)
      {
         if (i > 0) fprintf (tables, ",");
         if (T_matrix[i] == INT_MAX)
            fprintf (tables, "\n      %5s", "  MAX");
         else fprintf (tables, "\n      %5d", T_matrix[i]);
      }
      else
      {
         if (T_matrix[i] == INT_MAX)
            fprintf (tables, ",%5s", "  MAX");
         else fprintf (tables, ",%5d", T_matrix[i]);
      }
   }
   fprintf (tables, "\n      };\n\n");

   // T_matrix row ...
   if (optn[LG_TABL_MEDIUM])
   {
      vartype = get_typestr (T_row, tt_states);
      fprintf (header, "      static %-6s Tr[%6d]        ; // Terminal transition matrix row.\n", vartype, tt_states);
      fprintf (tables, "   // Terminal transition matrix row ...\n");
      fprintf (tables, "      static %s Tr[%d] = \n", vartype, tt_states);
      fprintf (tables, "      {");
      for (int i = 0; i < tt_states; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", T_row[i]);
         }
         else fprintf (tables, ",%5d", T_row[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   // T_matrix column ...
   if (optn[LG_TABL_MEDIUM])
   {
      vartype = get_typestr (T_col, N_terms);
      fprintf (header, "      static %-6s Tc[%6d]        ; // Terminal transition matrix column.\n", vartype, N_terms);
      fprintf (tables, "   // Terminal transition matrix column ...\n");
      fprintf (tables, "      static %s Tc[%d] = \n", vartype, N_terms);
      fprintf (tables, "      {");
      for (int i = 0; i < N_terms; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", T_col[i]);
         }
         else fprintf (tables, ",%5d", T_col[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   // Terminal Numbers (one for for each state) ...
   if (optn[LG_TABL_MEDIUM])
   {
      vartype = get_typestr (D_red, N_states);
      fprintf (header, "      static %-6s term_numb[%6d] ; // Terminal number.\n", vartype, N_states);
      fprintf (tables, "   // Terminal number ...\n");
      fprintf (tables, "      static %s term_numb[%d] = \n", vartype, N_states);
      fprintf (tables, "      {");
      for (int i = 0; i < N_states; i++)
      {
         if (i % 20 == 0)
         {
            if (i > 0) fprintf (tables, ",");
            fprintf (tables, "\n      %5d", D_red[i]);
         }
         else fprintf (tables, ",%5d", D_red[i]);
      }
      fprintf (tables, "\n      };\n\n");
   }

   fprintf (tables, "//\n");
   fprintf (tables, "////////////////////////////////////////////////////////////////////////////////////////////////////\n");
   fprintf (tables, "\n");

   fclose (tables);
   chmod (filename_hpp, S_IREAD); // Make output file read-only.

   fprintf (header, "*/\n\n");
   if (n_constants > 0)
   {
      int i;
      fprintf (header,
               "      enum terminal\n"
               "      {\n");
      for (i = 0; i < n_constants-1; i++)
      {
         fprintf (header, "         %s = %d,\n", Defcon_name[i], Defcon_value[i]);
      }
      fprintf (header, "         %s = %d\n", Defcon_name[i], Defcon_value[i]);
      fprintf (header,
               "      };\n\n");
   }

   fprintf (header, "//\n");
   fprintf (header, "////////////////////////////////////////////////////////////////////////////////\n");

   fclose (header);
   chmod (filename_h, S_IREAD); // Make output file read-only.
}

//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
