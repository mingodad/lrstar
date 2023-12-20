//    LRSTAR Parser Header

#if !defined(_LRSTAR_PARSER_H_)
#define _LRSTAR_PARSER_H_
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lowercase.h"

#define EOF_CHAR 26             // End Of File character.

enum ast_pass_t {
   FIRST_PASS  = 1,
   SECOND_PASS = 2,
   THIRD_PASS  = 3,
   FOURTH_PASS = 4,
};

typedef enum parse_direction_t {
   TOP_DOWN,
   BOTTOM_UP
} parse_direction_t;


class Symbol {                   // Symbol in Symbol Table.
public:
   char     *start;             // Start of symbol in input file or ?.
   unsigned  length;            // Length of symbol.
   unsigned  cell;              // Cell number in hash vector (if need to free later).
   int       type;              // Type of symbol: int, char, float, short, ...
   int       term;              // Terminal number for lookup function.
   int       scope;             // Scope: global, local, inner loop, ...

   Symbol() :
      start(0),
      length(0),
      cell(~0U),
      type(~0),
      term(~0),
      scope(~0)
   {
   }
};

class Node {         // AST Node.
public:
   int         nodenum;         // Number used to refer to a node in AST dump.
   int         id;              // Node ID number.
   int         sti;             // Symbol-table index (perm or temp var).
   int         line;            // Line number in input file.
   const char *token;           // Token referenced, iff applicable.
   size_t      token_len;
   const char *node_name;       // Name as defined by '+>' or '*>' productions.
   char       *start;           // Start of symbol in input area.
   Node       *prev;            // Previous node.
   Node       *next;            // Next node.
   Node       *child;           // Child node.
   Node       *parent;          // Parent node.
   Node       *alloc_link;      // Linked list of all nodes;
   Node(int         nodenum_,
        int         id_,
        int         sti_,
        int         line_,
        char       *start_,
        const char *token_,
        size_t      token_len_,
        const char *node_name_) :
      nodenum(nodenum_),
      id(id_),
      sti(sti_),
      line(line_),
      token(token_),
      token_len(token_len_),
      node_name(node_name_),
      start(start_),
      prev(0),
      next(0),
      child(0),
      parent(0),
      alloc_link(0)
   {
   }


   bool
   has_symbol()
   {
      // Is a symbol associated with node?
      return (start != 0) && (sti != 0) && (line != 0);
   }


   void print_node_ref_(FILE *fp,
                        const char *label,
                        const Node *n)
   {
      if (n != NULL) {
         fprintf(fp, "%s=%d  ", label, n->nodenum);
      } else {
         fprintf(fp, "%s=--  ", label);
      }
   }


   char *
   get_token()
   {
      // Caller is responsible for 'delete []' on the result.
      if (token != 0) {
         char *result = new char[token_len + 1];
         strncpy(result, token, token_len);
         result[token_len] = '\0';
         return result;
      } else {
         return 0;
      }
   }

   void
   print(FILE *fp)
   {
      fprintf(fp, "%d:  %s  ln=%d  ", nodenum, node_name, line);
      print_node_ref_(fp, "prv", prev);
      print_node_ref_(fp, "nxt", next);
      print_node_ref_(fp, "par", parent);
      print_node_ref_(fp, "chd", child);

      if (token != 0) {
         char *tok = get_token();

         fprintf(fp, "tok=%s", tok);
         delete [] tok;
      } else {
         fprintf(fp, "tok=--");
      }
      fprintf(fp, "\n");
   }
};

class PStack {       // Parser stack.
public:
   int   state;                 // Parser state.
   int   sym;                   // Tail symbol.
   int   sti;                   // Symbol table index.
   int   line;                  // Input line number.
   char *start;                 // Start of symbol in input file area.
   Node *node;                  // Pointer to node.
   Node *last;                  // Pointer to last in list.
   PStack() :
      state(~0),
      sym(~0),
      sti(~0),
      line(~0),
      start(0),
      node(0),
      last(0)
   {
   }
};

class RStack {       // Restore Stack.
public:
   PStack *ptr;                 // Parse stack pointer.       4  4
   int     state;               // State.                        4
   int     sym;                 // Symbol.                       4  12 bytes.
   RStack() :
      ptr(0),
      state(~0),
      sym(~0)
   {
   }
};

class SStack {       // State stack.
public:
   int    state;     // Parser state.
};

class Stack {        // AST Stack.
public:
   int    id;        // Node id.                      4
   int    counter;   // Counter of node accesses.     4   8 bytes
};


class lrstar_user_data_t {
   /* Extend this class for storing user data in the parser.
    * Use 'user_data' field.
    */
};

template<const char    *C_grammar,
         bool           C_action,
         bool           C_debug_parser,
         bool           C_debug_trace,
         bool           C_expecting,
         bool           C_insensitive,
         int            C_lookaheads,
         bool           C_make_ast,
         bool           C_nd_parsing,
         int            C_nd_threads,
         bool           C_node_actions,
         bool           C_reversable,
         bool           C_semantics,
         unsigned long  C_stksize,
         bool           C_term_actions,
         typename       T_lexer_t,
         typename       T_parser_tables_t>
class lrstar_parser {
public:
   typedef void (*init_func_t)(lrstar_parser *parser);
   typedef int  (*tact_func_t)(lrstar_parser *parser, int &t);
   typedef void (*nact_func_t)(ast_pass_t         pass,
                               parse_direction_t  direction,
                               lrstar_parser     *parser,
                               Node              *t);

public:
   lrstar_user_data_t *user_data;
   const char         *grammar; /* Name of grammar. */

private:
   init_func_t *init_func; /* Pointer to init_func table. */
   tact_func_t *tact_func; /* Pointer to tact_func table.  */
   nact_func_t *nact_func; /* Pointer to nact_func table.  */

   Node  *allocated_nodes;      // List of allocated nodes

public:
   T_lexer_t         lt;        /* Lexer tables. */
   T_parser_tables_t pt;        /* Parser tables. */

public:
   // Parser variables
   char     *path;              // Path of input file.
   PStack   *PS;                // Parse stack pointer.
   PStack    PSstart[C_stksize]; // Parser stack start.
   unsigned  n_nodes;           // Number of nodes in AST.
   unsigned  n_symbols;         // Number of symbols.
   int       n_errors;


private:
   // Parser variables
   RStack *RS;
   bool   *T_exp;       // Terminal expected.
   bool   *S_exam;      // State examined.
   RStack RSstart[C_stksize];

   // ND parsing ...
   int     LA;                     // Look Ahead token.
   int     n_warnings;             // Numbor of warnings.
   int     last_line;
   SStack **SS;                    // State stack pointer.
   SStack **SSstart;               // State stack start.
   int     *State;                 // State, during lookahead.
   int     *Action;                // Parsing action.
   int     *Parsed;                // Parsed (0 or 1).
   int     *LAcount;               // Lookahead count.

public:
   Symbol *symbol;        // Symbol.

private:
   unsigned  hashdiv;           // Hash divisor.
   int      *hashvec;           // Hash vector.
   unsigned  max_cells;         // Maximum number of cells in the hash vector.
   unsigned  max_symbols;       // Maximum number of symbols.

public:                          // AST Area ...
   ast_pass_t  traversal;       // AST traversal number: 1, 2, 3 ...
   int         stacki;          // AST stack index.
   Node       *root;            // Current root node.
   Node       *node;            // Current AST node.
   Stack      *stack;           // AST stack array.

private:
   int      *counter;           // Node counter array.

private:                        // LR Parser
   void
   reduce(int p)
   {
      if (C_semantics) {
         if (pt.argy[p] >= 0) {
            symbol[PS[0].sti].term = pt.argy[p];
         }
      }

      if (C_make_ast) {
         int psi;                                        // Parse stack index.
         if (pt.node_numb[p] >= 0) {                     // MAKE NODE ?
            Node *n;
            if (pt.argx[p] >= 0) {                       // If first argument specified.
               psi = pt.argx[p];               // Parse Stack Index.
               n   = new_node(pt.node_numb[p],
                              PS[psi].sti,     // Move sti from parse stack to node.
                              PS[psi].line,    // Move line from parse stack to node.
                              PS[psi].start);  // Move start from parse stack to node.
            } else { // No argument on production.
               // Create a Node with no Symbol attachment.
               n = new_node(pt.node_numb[p], 0, 0, 0);
            }
            psi = linkup(p);                             // Linkup the nodes in this rule.
            if (psi >= 0) {                              // Any nodes found in this rule?
               n->child = PS[psi].node;                  // Define child.
               PS[psi].node->parent = n;                 // Define parent.
            }
            PS[0].node = n;                              // Define this node in the parse stack.
            PS[0].last = n;                              // Define this node in the parse stack.
         } else {                                        // Check for nodes not linked?
            psi = linkup (p);                            // Get parse-stack index.
            if (psi > 0) {                               // If we have a node here ...
               PS[0].node = PS[psi].node;                // Move node to 1st position.
               PS[0].last = PS[psi].last;                // Move last also.
            }
         }
      }
   }


   int
   linkup(int p)
   {
      int i;
      int next = -1;

      if (C_reversable && pt.reverse[p] != 0) {          // IF NOT TO REVERSE THE ORDER.
         for (i = 0; i <= pt.PL[p]; i++) {               // For each tail pointer.
            if (PS[i].node != 0) {                       // If tail points to node.
               if (next >= 0) {                          // If one waiting.
                  PS[i   ].last->next = PS[next].node;   // Define next node.
                  PS[next].node->prev = PS[i].last;      // Define previous node.
                  PS[i   ].last       = PS[next].last;   // Change last to next last.
               }
               next = i;                                 // Next = Curr.
            }
         }
      } else {                                           // REVERSE THE ORDER.
         for (i = pt.PL[p]; i >= 0; i--) {               // For each tail pointer.
            if (PS[i].node != NULL) {                    // If tail points to node.
               if (next >= 0) {                          // If one waiting.
                  PS[i   ].last->next = PS[next].node;   // Define next node.
                  PS[next].node->prev = PS[i   ].last;   // Define previous node.
                  PS[i   ].last       = PS[next].last;   // Change last to next last.
               }
               next = i;                                 // Next = Curr.
            }
         }
      }
      return next;
   }


   int
   nd_parser_la(int i, int la)            // ND LA Parser.
   {
      int p;                                   // Production (rule).

      if (la == 0) {                           // LA is first one?
         if (Action[i] > 0) {                  // Shift and goto action?
            SS[i]++;
            SS[i]->state = State[i];                  // Put State stack.

            if (Action[i] > pt.accept_state) {        // Shift and reduce?
               State[i] = pt.accept_state - Action[i];   // Convert to production number.
               goto SR;
            }
            State[i] = Action[i];                     // Get next state.
            return 1;
         }
         p = -Action[i];                              // Get production.
         goto Red;                                    // Reduce.
      }

   Shft:
      if (pt.Bm[pt.Br[State[i]] +
                pt.Bc[LA]] & pt.Bf[LA]) {             // Check B-matrix for shift action.
         SS[i]++;
         SS[i]->state = State[i];                     // Put current state on stack.
         State[i] = pt.Tm[pt.Tr[State[i]] +
                          pt.Tc[LA]];                 // Get next state from term. trans. matrix.
         while (State[i] < 0) {                       // While shift-reduce actions.
         SR:
            p = -State[i];
            SS[i] -= pt.PL[p];                        // Reduce stack ptr by production length.
            State[i] = pt.Nm[pt.Nr[SS[i]->state] +
                             pt.Nc[p]];               // Get next state from nonter. trans. matrix.
         }
         return 1;                                    // Return success.
      }

      if ((p = pt.Rr[State[i]]) > 0 ||                   // Default reduction?
          (p = pt.Rm[pt.Rc[LA] - p]) > 0) {              // Compute reduction?
      Red:
         SS[i] -= pt.PL[p]; // Reduce parse stack ptr by rule length - 1.
         if (pt.PL[p] < 0) {
            SS[i]->state = State[i];      // Stack current state.
         }
         while (1) {
            State[i] = pt.Nm[pt.Nr[SS[i]->state] +
                             pt.Nc[p]]; // Get next state from nonterminal transition.
            if (State[i] > 0) {
               goto Shft;       // If a state, continue parsing.
            }
            p = -State[i];     // Make the production number positive.
            SS[i] -= pt.PL[p]; // Reduce parse stack ptr by rule length - 1.
         }
      }

      if (State[i] == pt.accept_state) {
         return 1;
      }

      // LOOK FOR A SHIFT ACTION FOR THIS TOKEN ...
      for (int j = pt.nd_fterm[State[i]];
           j < pt.nd_fterm[State[i] + 1]; j++) {
         if (pt.nd_term[j] == LA) {
            int k = pt.nd_faction[j];

            if (pt.nd_action[k] > 0) {                    // Shift action (always first one)?
               SS[i]++;
               SS[i]->state = State[i];                   // Put State on stack.

               if (pt.nd_action[k] > pt.accept_state) {   // Shift and reduce?
                  State[i] = pt.accept_state - pt.nd_action[k];// Convert to production number.
                  goto SR;
               }
               State[i] = pt.nd_action[k];
               return 1;
            }
            if (C_debug_parser) {
               char string[16];
               // A recursive call to nd_parse() is needed to continue
               // the ND lookahead parsing.  This version of the LR(*)
               // algorithm does not support 2nd, 3rd or more depths
               // of recursion.  Probably the grammar has ambiguity
               // that needs to be resolved.
               n_warnings++;
               sprintf(string, "In state %d", State[i]);

               if (la == 0) {
                  syntax_error(string, &lt.token, pt.term_symb[LA]);
               } else {
                  syntax_error(string, &lt.lookahead, pt.term_symb[LA]);
               }

               printf ("\n   STOPPED LR(*) parsing after %d lookaheads, "
                       "for conflicting actions:\n\n", la + 1);
               do {
                  print_prod ("   * Reduce", -pt.nd_action[k], 0);
               } while (++k < pt.nd_faction[j+1]);
               print_action ("\n   IGNORING ", i);
            }
            return 0;
         }
      }

      if (C_debug_parser) {
         char string[16];
         sprintf(string, "In state %d", State[i]);
         if (la == 0) {
            syntax_error(string, &lt.token, pt.term_symb[LA]);
         } else {
            syntax_error(string, &lt.lookahead, pt.term_symb[LA]);
         }
         print_action("\n   IGNORING ", i);
      }
      return 0;      // Did not find a match for LA in this state.
   }


   int
   nd_parser(int x, int t, int na)
   {
      int  i;
      int  la;             // Lookaheads to try.
      int  total;          // Total number parsed.
      int  limit;          // Lookahead limit.
      char string[64];

      if (C_debug_parser) {
         if (lt.token.line > last_line) {
            printf ("\n");
         }
         last_line = lt.token.line;
         sprintf(string, "In state %d", x);
         printf("////////////////////////////////////////////////////////////\n");
         syntax_error(string, &lt.token, pt.term_symb [t]);
         printf("\n   STARTED LR(*) parsing for the following choices:\n\n");
         print_actions(na);
         n_warnings++;
      }

      // COPY PARSE STACK TO ND STATE STACK FOR EACH ACTION ...
      for (i = 0; i < na; i++) {
         SS[i] = SSstart[i];
         for (PStack *P = &PSstart[0]; P < PS;) {
            (++SS[i])->state = (++P)->state;
         }
         Parsed[i] = 1;
      }

      // TRY TO ACCEPT LOOKAHEAD TOKENS ...
      LA    = t;
      total = 0;
      la    = 0;
      i     = 0;
      do {
         if (Parsed[i] > 0) {
            total += Parsed[i] = nd_parser_la (i,la);
         }
      } while (++i < na);

      // ONE ACTION SUCCEEDED ? ...
      if (total == 1) {
         LAcount[1]++;
         if (C_debug_parser) {
            n_warnings = 0;
         }
         i = 0;
         do {
            if (Parsed[i] > 0) {
               if (C_debug_parser) {
                  printf("   CHOOSING ");
                  print_action("", i);
                  printf ("\n");
               }
               return Action[i];
            }
         } while (++i < na);
      }

      lt.lookahead.end      = lt.token.end; // Prime get_lookahead().
      lt.lookahead_linenumb = lt.linenumb;
      limit                 = C_lookaheads;
      la                    = 1;

      do {
         total = 0;
         LA = lt.get_lookahead();
         if (C_term_actions) {
            if (pt.tact_numb[LA] >= 0) {                // If term action ...
               (*tact_func[pt.tact_numb[LA]])(this, LA);   // Call term-action function.
            }
         }

         if (LA == pt.eof_symb) {
            limit = la; // <eof> ?
         }

         i = 0;
         do {
            if (Parsed[i] > 0) {
               total += Parsed[i] = nd_parser_la (i,la);
            }
         } while (++i < na);

         // ONE ACTION SUCCEEDED ? ...
         if (total == 1) {
            LAcount[la+1]++;
            if (C_debug_parser) {
               n_warnings = 0;
            }

            i = 0;
            do {
               if (Parsed[i] > 0) {
                  if (C_debug_parser) {
                     printf ("   CHOOSING ");
                     print_action ("", i);
                     printf("\n");
                  }
                  lt.lookahead.start = 0; // Stop lookahead mode in lookup().
                  return Action[i];
               }
            } while (++i < na);
         }

         // TOKEN NOT ACCEPTED, SYNTAX ERROR ...
         if (total == 0) {
            if (n_warnings == 0) {
               syntax_error("Error", &lt.lookahead, pt.term_symb[LA]);
               printf("\n   AMBIGUITY after %d lookaheads, unable to choose from:\n\n",
                      la + 1);
               print_actions(na);
            } else {
               printf("\n   AMBIGUITY after %d lookaheads, cannot make a decision.\n",
                      la + 1);
            }
            n_errors = INT_MAX; // No more error messages.
            return 0;           // FAILURE
         }
      } while (++la < limit);

      // TRIED ALL LOOKAHEADS, STILL AMBIGUOUS ...
      LAcount[limit]++;
      if (Action[0] > 0) { // Shift action?
         if (C_debug_parser) {
            printf("\n   AMBIGUITY after %d lookaheads, "
                   "choosing the Shift action.\n", limit);
            printf("\n");
            n_warnings = 0;
         }
         lt.lookahead.start = 0; // Stop lookahead mode in lookup().
         return Action[0];
      }

      // Some parsers choose the lowest numbered reduction.
      // Not a good idea, because the grammar is ambiguous.
      // Fix the grammar or increase option /k, if necessary.
      if (C_debug_parser) {
         printf("\n   AMBIGUITY after %d lookaheads, unable to decide.\n", limit);
      } else {
         sprintf(string, "In state %d", x);
         syntax_error(string, &lt.token, pt.term_symb[t]);
         printf("\n   AMBIGUITY after %d lookaheads, unable to choose from:\n\n", limit);
         print_actions(na);
      }
      n_errors = INT_MAX; // No more error messages.
      return 0;           // FAILURE
   }

public:
   void
   internal_error(const char *fmt, ...) NO_RETURN
   {
      va_list args;

      va_start(args, fmt);
      fprintf(stderr, "internal error: ");
      vfprintf(stderr, fmt, args);
      va_end(args);
      exit(100);
   }

   lrstar_parser(const char  *input_path_,
                 char        *input_text_,
                 unsigned     max_symb_,
                 init_func_t *init_func_,
                 tact_func_t *tact_func_,
                 nact_func_t *nact_func_) :
      user_data(0),
      grammar(C_grammar),
      init_func(init_func_),
      tact_func(tact_func_),
      nact_func(nact_func_),
      allocated_nodes(0),
      lt(input_text_),
      pt(),
      path(strdup(input_path_)),
      PS(0),
      n_nodes(0),
      n_symbols(0),
      n_errors(0),
      RS(0),
      T_exp(0),
      S_exam(0),
      LA(0),
      n_warnings(0),
      last_line(0),
      SS(0),
      SSstart(0),
      State(0),
      Action(0),
      Parsed(0),
      LAcount(0),
      symbol(0),
      hashdiv(0),
      hashvec(0),
      max_cells(0),
      max_symbols(max_symb_),
      traversal(FIRST_PASS),
      stacki(0),
      root(0),
      node(0),
      stack(0),
      counter(0)
   {
      unsigned i;

      if (C_nd_parsing) {
         SS      = new SStack *[C_nd_threads];
         SSstart = new SStack *[C_nd_threads];
         State   = new int[C_nd_threads];
         Action  = new int[C_nd_threads];
         Parsed  = new int[C_nd_threads];
         LAcount = new int[C_lookaheads + 1];
      }

      if (C_nd_parsing) {
         for (i = 0; i < C_nd_threads; i++) {
            SSstart[i] = new SStack[C_stksize];
         }
         for (i = 0; i < C_lookaheads + 1; i++) {
            LAcount[i] = 0;
         }
         last_line = 0;
         n_warnings = 0;
      }

      PS      = &PSstart[0];              // Set parse-stack pointer.
      n_nodes = 0;                        // In case of no parser creation.

      {                                   // Initialize symbol table.

         assert(max_symb_ > 0);           // Prerequisite.

         n_symbols   = 1;                 // 0 is reserved for null symbol.
         max_symbols = max_symb_;
         max_cells   = 2 * max_symbols;
         symbol      = new Symbol[max_symbols];
         hashvec     = new int[max_cells];
         hashdiv     = UINT_MAX / max_cells + 1;

         for (i = 0; i < max_cells; i++) {
            hashvec[i] = -1;
         }
      }

      if (C_make_ast) {
         n_nodes = 1;
         node    = new_node(-1, 0, 0, 0); // Invalid Node.
      }

      if (C_action) {
         (*init_func[0])(this);          // init_action()
      }

      {
         /* Work around gcc defect.
          *
          * If the 'pt' variables are left in the 'new' expresions,
          * gcc issues the following diagnostic:
          *
          *   error: conversion to 'long unsigned int' from 'sizetype' may change
          *          the sign of the result [-Werror=sign-conversion]
          */
         int n_terms  = pt.n_terms;
         int n_states = pt.n_states;

         T_exp  = new bool[n_terms];
         S_exam = new bool[n_states];
      }

      i = 0;
      while (i < static_cast<unsigned>(pt.n_terms)) {
         T_exp[i] = false;
         ++i;
      }

      i = 0;
      while (i < static_cast<unsigned>(pt.n_states)) {
         S_exam[i] = false;
         ++i;
      }
   }


   ~lrstar_parser()
   {
      Node *n = allocated_nodes;

      while (n != 0) {
         Node *next = n->alloc_link;
         delete n;
         n = next;
      }

      free(path);

      delete [] symbol;
      delete [] hashvec;

      delete [] T_exp;
      delete [] S_exam;

      if (C_node_actions) {
         if (n_nodes >  1 && pt.n_nodeactns > 0) {
            delete [] stack;
            delete [] counter;
         }
      }

      if (C_nd_parsing) {
         for (int i = 0; i < C_nd_threads; i++) {
            delete [] SSstart[i];
         }

         delete [] SS;
         delete [] SSstart;
         delete [] State;
         delete [] Action;
         delete [] Parsed;
         delete [] LAcount;
      }
   }


   bool opt_semantics(void)  { return C_semantics;  }
   bool opt_nd_parsing(void) { return C_nd_parsing; }

   void
   set_user_data(lrstar_user_data_t *data)
   {
      user_data = data;
   }


   void
   term_symtab()
   {
      n_symbols--;
   }


   void
   term_ast()
   {
      n_nodes--;
   }


   void
   term_parser()
   {
      if (C_make_ast) {
         term_ast();
      }

      term_symtab();
      if (C_action) {
         (*init_func[1])(this);               // term_action()
      }
   }


   void
   print_prod(const char *prefix, int p, int dot)
   {
      const char *symb;
      int len = pt.f_tail[p + 1] - pt.f_tail[p];

      printf("%s %4d %s -> ", prefix, p, pt.head_symb[pt.head_numb[p]]);
      for (int i = pt.f_tail[p]; i < pt.f_tail[p + 1]; i++) {
         int s = pt.tail[i];

         if (s >= 0) {
            symb = pt.term_symb[ s];
         } else {
            symb = pt.head_symb[-s];
         }

         if (len++ == dot) {
            printf(". ");
         }
         printf("%s ", symb);
      }

      if (len == dot) {
         printf (". ");
      }
      printf ("\n");
   }


   char *
   symbol_name(char *start, char *end)
   {
      char *p, *q;
      static char name[100];

      if (end - start > 99) {
         end = start + 99;
      }
      p = start;
      q = name;
      do {
         *q++ = *p++;
      } while (p < end);
      *q = '\0';
      return name;
   }


   char *                       // XXX dynamically allocate result.
   symbol_name(int sti)
   {
      unsigned     i;
      char        *p;
      static char  name[100];

      if (sti < 0) {            // Terminal symbol?
         p = (char *)pt.term_symb[-sti];
         for (i = 0; p[i] != 0; i++) {
            name[i] = p[i];
         }
         name[i] = 0;
      }
      else {                    // Input file symbol.
         unsigned L;

         assert(symbol[sti].length != ~0U); // Uninitialized structure?
         p = symbol[sti].start;
         L = symbol[sti].length;

         if (L >= 100) {
            L = 95;
            for (i = 0; i < L; i++) {
               name[i] = p[i];
            }
            name[i++] = ' ';
            name[i++] = '.';
            name[i++] = '.';
            name[i++] = '.';
            name[i] = '\0';
         } else {
            for (i = 0; i < L; i++) {
               name[i] = p[i];
            }
            name[i] = '\0';
         }
      }
      return name;
   }


   void
   print_action(const char* str, int i)
   {
      int y = Action[i];
      printf("%s", str);
      if (y > 0) {
         printf("Shift %s and ", symbol_name(lt.token.sti));
         if (y > pt.accept_state) {          // Shift and reduce ?
            int p = y - pt.accept_state;     // Convert to production number.
            print_prod("reduce", p, -1);
         } else {
            printf("goto %d\n", y);
         }
      } else {
         print_prod("Reduce", -y, 0);
      }
   }


   void
   print_actions(int na)
   {
      int i = 0;
      do {
         print_action("   * ", i);
      } while (++i < na);
   }


   void
   print_lookaheads()
   {
      int n = 0;
      for (int i = 0; i <= C_lookaheads; i++) {
         if (LAcount[i] != 0) {
            const char *msg;
            if (n++ == 0) {
               printf("\n");
            }
            if (LAcount[i] == 1) {
               msg = "time";
            } else {
               msg = "times";
            }
            if (i == 1) {
               printf("      %3d Lookahead needed: %6d %s\n",
                      i, LAcount[i], msg);
            } else {
               printf("      %3d Lookaheads needed: %6d %s\n",
                      i, LAcount[i], msg);
            }
         }
      }
   }


   int
   restore()
   {
      while (RS > &RSstart[0]) {       // Restore PS, RS and states.
         RS->ptr->state = RS->state;   // Reset state to saved state.
         RS->ptr->sym   = RS->sym;     // Reset symbol to saved symbol.
         RS--;
      }
      PS = RS->ptr;
      return RS->state;
   }


   void
   syntax_error(const char *msg, Token *T, const char *symb)
   {
      char  c;

      n_errors++;
      if (*T->start <= 32) {
         T->end = T->start+1;
         *(T->end) = '\n';
         if (*T->start == EOF_CHAR) {
            T->line--;
         }
      }

      printf("%s(%d) : %s ", path, T->line, msg);

      if (*T->start > ' ') {
         c = *T->end;
         *T->end = '\0';
         printf("at %s %s\n", T->start, symb);
         *T->end = c;
      } else {                  /* Control character. */
         printf("at %#x %s\n", *T->start, symb);
      }
   }

   void
   sort_terms(int *seq)
   {
      /* seq - the sorted sequence:
         name[seq[0]] gives the first name in the sorted list.
      */
      const char **P;
      const char  *P_temp;
      size_t      *L;
      int          seq_temp;
      int          i;
      int          j;
      int          c;
      size_t       L_temp;
      size_t       leng;

      L = new size_t[pt.n_terms];
      P = new const char *[pt.n_terms];

      for (i = 0; i < pt.n_terms; i++) {
         P[i] = pt.term_symb[i];
         L[i] = strlen(pt.term_symb[i]);
         seq[i] = i;
      }
      for (i = 1; i < pt.n_terms; i++) { // Bubble sort algorithm.
         P_temp   = P[i];
         L_temp   = L[i];
         seq_temp = seq[i];
         j        = i - 1;

         do {
            leng = L[j];
            if (L_temp < L[j]) {
               leng = L_temp;
            }

            c = strncmp(P_temp, P[j], leng);
            if (c == 0 && L_temp < L[j]) {
               P[j+1]   = P[j];
               L[j+1]   = L[j];
               seq[j+1] = seq[j];
               P[j]     = P_temp;
               L[j]     = L_temp;
               seq[j]   = seq_temp;
            } else {
               break;
            }
         } while (--j >= 0);
      }
      delete [] L;
      delete [] P;
   }


   void
   print_terms(int state)
   {
      printf ("\n");
      if (state >= 0) {
         printf("In state%5d, ", state);
      }
      printf("Expecting one of the following:\n\n");

      int t, x;
      int *seq = new int[pt.n_terms];
      sort_terms(seq);

      for (t = 0; t < pt.n_terms; t++) {
         x = seq[t];

         // if (x == pt.eof_symb) continue;
         if (T_exp[x]) {
            if (pt.term_symb[x][0] == '<' ||  pt.term_symb[x][0] == '{') {
               printf ("         %4d %-30s\n", x, pt.term_symb[x]);
            }
         }
      }

      for (t = 0; t < pt.n_terms; t++) {
         x = seq[t];
         if (x == pt.eof_symb) {
            continue;
         }
         if (T_exp[x]) {
            if (pt.term_symb[x][0] != '<' && pt.term_symb[x][0] != '{') {
               printf ("         %4d %-30s\n", x, pt.term_symb[x]);
            }
         }
      }
      delete [] seq;
   }


   void
   reduction(int q, int x)
   {
      // Save parse stack pointers.
      RStack* RSx = RS;                // Reset restore-stack pointer.
      PStack* PSx = PS;                // Save parse-stack pointer.

      PS -= pt.PL[q];                  // Reduce parse stack ptr by rule length - 1.
      if (pt.PL[q] < 0) {              // Null production?
         (++RS)->ptr = PS;             // Save parse-stack pointer.
         RS->state = PS->state;        // Save old state before replacing it.
         PS->state = x;                // Stack current state, replacing old state.
      }

      while (1) {
         x = pt.Nm[pt.Nr[PS->state] +
                   pt.Nc[q]];          // Get next state from nonterminal transition.
         if (x > 0) {
            if (!S_exam[x]) {          // Not been there yet?
               expecting(x);           // Recursive call, potential loop, but very rare.
            }
            break;
         }
         q = -x;                       // Set production number.
         PS -= pt.PL[q];               // Reduce parse stack pointer.
      }

      // Restore parse stack.
      PS = PSx;                           // Restore PS.
      while (RS > RSx) {
         RS->ptr->state = RS->state;      // Reset state to saved state.
         RS--;
      }
   }


   void
   expecting(int x)
   {
      int t;                                       // Terminal number.
      int p, q;

      S_exam[x] = true;                            // Mark this state as seen.
      for (t = 0; t < pt.n_terms; t++) {           // For all terminals.
         if (pt.Bm[pt.Br[x] +
                   pt.Bc[t]] & pt.Bf[t]) {         // Check B-matrix for shift action.
            T_exp[t] = true;                       // Mark this terminal.
         }
      }

      if (C_nd_parsing) {
         int i, j;
         for (i = pt.nd_fterm[x];
              i < pt.nd_fterm[x+1]; i++) {         // For all terminals in this state.
            for (j = pt.nd_faction[i];
                 j < pt.nd_faction[i+1]; j++) {    // For all actions for these terminals.
               if (pt.nd_action[j] > 0) {          // Terminal transition.
                  T_exp[pt.nd_term[i]] = true;     // Mark this terminal.
               } else if (pt.nd_action[j] < 0) {
                  int pp = -pt.nd_action[j];
                  reduction(pp, x);
               }
            }
         }
      }

      if ((p = pt.Rr[x]) > 0) {                    // Default reduction?
         reduction(p, x);
         return;
      }

      for (t = 0; t < pt.n_terms; t++) {           // For all terminals.
         q = pt.Rm[pt.Rc[t] - p];                  // Reduction for this terminal.
         if (q > 0) {                              // If not zero production?
            reduction(q, x);
         }
      }
   }


   void
   print_stack ()               // Print parser stack.
   {
      if (C_debug_parser) {
         printf("\nParse stack:\n");
         for (PStack* ps = &PSstart[1]; ps <= PS; ps++) {
            const char *name;
            const char *name2;
            int         sym = ps->sym;

            if (sym <= 0) {     // Terminal?
               name  = pt.term_symb[-sym];
               name2 = "";
               if (*name == '<' || *name == '{') {
                  if (ps->sti > 0) {
                     name2 = symbol_name(ps->sti);
                  }
               }

               printf("   state%5d %4d %s %s\n",  ps->state, -sym, name, name2);
            } else {            // Nonterminal.
               name = pt.head_symb[sym];
               printf("   state%5d %4d %s\n", ps->state, sym, name);
            }
         }
      }
   }


   void
   traverse_print_ast(FILE *fp, Node *n)
   {
      while (n->next != 0) {
         n->print(fp);

         if (n->child != 0) {
            traverse_print_ast(fp, n->child);
         }
         n = n->next;
      }

      n->print(fp);
      if (n->child != 0) {
         traverse_print_ast(fp, n->child);
      }
   }


   void
   print_ast_nodes(FILE *fp, Node *n)
   {
      fprintf(fp, "\nAbstract Syntax Tree ...\n\n");
      if (n != 0) {
         traverse_print_ast(fp, n);
      } else {
         fprintf(fp, "   Parser is empty.\n");
      }
   }


   void
   print_ast(FILE *fp)
   {
      if (C_debug_parser) {
         print_ast_nodes(fp, root);
      }
   }


   void
   find_root(Node *last_node)
   {
      root = last_node;                // Define root node.
      if (root != 0) {
         while (root->prev != 0) {     // In case of a list only.
            root = root->prev;         // Go up the list to first node.
         }
      }
   }


   int
   parse(FILE *fp)
   {
      int x, t, T, p;
      x = 0;                                          // State = 0 to start.
   Read:
      T = t = lt.get_token();                         // Get incoming token.
      if (C_term_actions) {
         if (pt.tact_numb[t] >= 0) {                  // If token action ...
            // Call token-action function.
            lt.token.sti = (*tact_func[pt.tact_numb[t]])(this, t);
         }
      } else {
         lt.token.sti = -t;
      }
      if (C_expecting) {
         RS = &RSstart[0];
         RS->state = x;
         RS->ptr = PS;
      }

   Test:
      if (pt.Bm[pt.Br[x] +
                pt.Bc[t]] & pt.Bf[t]) {             // Check B-matrix for shift action.
         PS++;
         PS->state = x;                            // Put current state on stack.
         PS->sti   = lt.token.sti;                 // Put symbol-table index on stack.
         if (C_make_ast) {
            PS->line  = lt.token.line;             // Put line number on stack.
            PS->start = lt.token.start;            // Put start address on stack.
            PS->node  = 0;                         // Set node on stack to zero.
         }

         if (C_expecting) {
            PS->sym   = -t;                        // Put symbol on stack.
         }
         x = pt.Tm[pt.Tr[x] +
                   pt.Tc[t]];                      // Get next state from terminal transition matrix.
         while (x < 0) {                           // While shift-reduce actions.
            p = -x;
         SR:
            PS -= pt.PL[p];                        // Reduce stack ptr by production length.
            if (C_expecting) {
               PS->sym = pt.head_numb[p];          // Put symbol on stack.
            }
            reduce(p);                             // Call reduce action with production number.
            x = pt.Nm[pt.Nr[PS->state] +
                      pt.Nc[p]];                   // Get next state from nonterminal transition.
         }
         goto Read;                                // Go to read next token.
      }
      if ((p = pt.Rr[x]) > 0 ||                    // Default reduction 90% of the time.
          (p = pt.Rm[pt.Rc[t] - p]) > 0) {         // Compute reduction?
      Red:
         PS -= pt.PL[p];                           // Reduce parse stack ptr by rule length - 1.
         if (pt.PL[p] < 0) {                       // Null production?
            if (C_expecting) {
               RS++;
               RS->ptr   = PS;
               RS->state = PS->state;
               RS->sym   = PS->sym;
            }
            PS->state = x;                         // Stack current state, replacing old state.
            if (C_make_ast) {
               PS->node  = 0;                      // Set node on stack to zero.
            }
         }
         while (1) {
            if (C_expecting) {
               PS->sym = pt.head_numb[p];          // Put symbol on stack.
            }
            reduce(p);                             // Call reduce action with production number.
            x = pt.Nm[pt.Nr[PS->state] +
                      pt.Nc[p]];                   // Get next state from nonterminal transition.
            if (x > 0) {
               goto Test;                          // Continue parsing.
            }
            p = -x;                                // Set production number.
            PS -= pt.PL[p];                        // Reduce parse stack ptr by rule length - 1.
         }
      }

      if (C_nd_parsing) {
         int i, j, na, y;

         // For all ND terminals in this state.
         for (i = pt.nd_fterm[x]; i < pt.nd_fterm[x+1]; i++) {
            if (pt.nd_term[i] == t) {                 // Got a match?
               j = pt.nd_faction[i];                  // Start of actions.
               na = 0;                                // Number of actions.
               do {
                  State[na] = x;                      // Copy this state.
                  Action[na++] = pt.nd_action[j];     // Copy this action.
               } while (++j < pt.nd_faction[i+1]);    // While there's more.
               y = nd_parser (x,t,na);                // ND lookahead parser.
               if (y > 0) {                           // Shift?
                  PS++;                               // Increment parser stack pointer.
                  PS->state = x;                      // Put current state on stack.
                  PS->sti   = lt.token.sti;           // Put symbol table index on stack.
                  if (C_make_ast) {
                     PS->line  = lt.token.line;       // Put line number on stack.
                     PS->start = lt.token.start;      // Put start address on stack.
                     PS->node  = 0;                   // Set node on stack to zero.
                  }
                  if (y > pt.accept_state) {          // Shift and reduce action?
                     p = y - pt.accept_state;         // Shift and reduce.
                     goto SR;                         // Go to shift reduce.
                  }
                  if (C_expecting) {
                     PS->sym = -t;                       // Put symbol on stack.
                  }
                  x = y;                              // Shift and goto.
                  goto Read;                          // Go to read another token.
               }
               if (y < 0) {                           // Reduce ?
                  p = -y;                             // Reduce action.
                  goto Red;                           // Go to reduce.
               }
            }
         }
      }

      if (x == pt.accept_state) {                     // If Goal production.
         PS -= pt.PL[p];                              // Reduce parse stack ptr by rule length - 1.
         reduce (p);                                  // Call reduce action with production number.
         if (C_nd_parsing) {
            print_lookaheads();                       // Print lookahead statistics.
         }
         print_symtab(fp);                            // Print the symbol table contents.
         if (C_make_ast) {
            find_root (PS[0].node);
            print_ast(fp);
            traverse_nact(fp, FIRST_PASS);
         }

         if (C_debug_parser) {
            fprintf(fp, "\nDone.\n\n");
         }
         return lt.linenumb - 1;                       // Success.
      }

      if (C_expecting) {
         x = restore ();
         if (t != 0) {
            t = 0;                                    // Try <error>
            goto Test;
         }
      }

      if (n_errors < INT_MAX) {                   // Error message not printed?
         if (C_expecting) {
            print_stack ();
         }
         syntax_error ("Error", &lt.token, pt.term_symb[T]);
         if (C_expecting) {
            expecting (x);
            print_terms (x);
         }
      }
      return -lt.linenumb;      // Failure.
   }


   void
   traverse_invoke_nact(FILE *fp, Node *n)
   {
      if (C_node_actions) {
         Node *c;

         stacki++;
         counter[n->id]++;

         stack[stacki].id      = n->id;
         stack[stacki].counter = counter[n->id];

         if (nact_func[n->id] != 0) { // Got a node action ?
            tracer(n, TOP_DOWN);
            (*nact_func[n->id])(traversal, TOP_DOWN, this, n);
         }

         c = n->child;          // Child node pointer.
         while (c != 0) {
            traverse_invoke_nact(fp, c);
            c = c->next;
         }

         if (nact_func[n->id] != 0) { // Got a node action ?
            tracer(n, BOTTOM_UP);
            (*nact_func[n->id])(traversal, BOTTOM_UP, this, n);
         }
         stacki--;
      }
   }


   void
   traverse_nact(FILE *fp, ast_pass_t trav)
   {
      if (C_node_actions) {
         if (n_nodes > 1) {           // Any nodes in the tree?
            if (pt.n_nodeactns > 0) { // Any node actions?
               stacki  = -1;
               stack   = new Stack[C_stksize];
               counter = new int[pt.n_nodenames];

               for (int i = 0; i < pt.n_nodenames; i++) {
                  counter[i] = 0;
               }

               if (C_debug_parser) {
                  fprintf(fp,"\nDoing Tree Traversal ...\n\n");
               } else {
                  fprintf(fp,"\n");
               }

               traversal = trav;
               Node *n   = root;
               do {
                  traverse_invoke_nact(fp, n);
                  n = n->next;
               } while (n != 0);
            }
         }
      }
   }


   void
   tracer(Node *n, parse_direction_t direction)
   {
      if (C_debug_trace) {
         const char *name;
         if (C_node_actions) {
            const char *dir;
            switch (direction) {
            case TOP_DOWN:
               dir = "*>";
               break;
            case BOTTOM_UP:
               dir = "<*";
               break;
            }
            name = "";
            if (n->has_symbol()) {
               name = symbol_name(n->sti);
            }
            printf("   %d %s %s (%s)\n", traversal, dir,
                   pt.node_name[n->id], name);
         }
      }
   }

   void
   print_symtab(FILE *fp)
   {
      if (C_debug_parser) {
         fprintf(fp,"\nSymbol Table ...\n\n");
         if (n_symbols > 1) {
            fprintf(fp,"   sti  leng  type     name "
                    "                               terminal\n");
            for (int i = 1; i < static_cast<int>(n_symbols); i++) {
               fprintf(fp," %5d %5d %5d     %-30s %4d %s\n",
                       i,
                       symbol[i].length,
                       symbol[i].type,
                       symbol_name(i),
                       symbol[i].term,
                       pt.term_symb[symbol[i].term]);
            }
         } else {               // No symbols in the table.
            fprintf(fp,"   Symbol Table is empty.\n");
         }
      }
   }

   Node *
   new_node(int id, int sti, int line, char *start)
   {
      static int  node_num = 0;
      Node       *n;
      const char *node_name;
      const char *label;
      size_t      label_len;;

      node_name = "<invalid>";
      if (id != -1) {
         node_name = pt.node_name[id];
      }

      if (sti == 0) {
         label     = NULL;
         label_len = 0;
      } else if (sti > 0) {
         /* References symbol table. */
         label     = symbol[sti].start;
         label_len = symbol[sti].length;
      } else {
         // invariant: sti < 0
         /* References terminal symbol. */
         label     = pt.term_symb[-sti];
         label_len = strlen(label);
      }

      n = new Node(node_num, id, sti, line, start,
                   label, label_len, node_name);
      ++node_num;
      n_nodes++;
      n->alloc_link   = allocated_nodes;
      allocated_nodes = n;
      return n;
   }


   int
   add_symbol(int t, char* token_start, char* token_end)
   {
      const char *p      = token_start; // Point at start.
      long int    length = token_end - p; // Set length.
      unsigned    hash   = static_cast<unsigned>(length); // Set hash to length.
      int         i      = 0;   // Set shift value to 0.
      char        lowered;

      do {                                                // Assume length != 0
         if (C_insensitive) {
            lowered = lowercase[static_cast<unsigned char>(*p)];
         } else {
            lowered = *p;
         }
         hash += static_cast<uint8>(lowered) << i;
         i += 4;
         i %= 32;
      } while (++p < token_end);

      unsigned cell = hash % max_cells; // Get first cell.
      int      sti  = hashvec [cell]; // Get symbol table index.

      while (sti >= 0) {                        // Symbol exists?
         if (symbol[sti].length == length) {    // If lengths are equal ...
            p = token_start;                    // Point at token start.
            char* start = symbol[sti].start;
            char* end   = start + length;
            do {
               if (C_insensitive) {
                  lowered = lowercase[static_cast<unsigned char>(*start)];
               } else {
                  lowered = *start;
               }
               if (*p != lowered) {
                  goto Cont;                 // If characters not equal ...
               }
               start++;
               p++;
            } while (start < end);           // while end not reached.
            return sti;                      // Return sti.
         }
      Cont:
         hash *= 65549;
         cell = hash / hashdiv;               // Get cell number.
         sti  = hashvec[cell];                // Get symbol table index.
      }

      if (n_symbols >= max_symbols) {          // Reached maximum number?
         printf("\nNumber of symbols exceeds %d.\n\n", max_symbols);
         internal_error("%s:%d: Symbol table full; "
                        "increase instantiation size.",
                        __PRETTY_FUNCTION__, __LINE__);
      }
      assert(n_symbols <= INT_MAX);
      sti                = static_cast<int>(n_symbols);
      hashvec[cell]      = sti;          // Put symbol number into hash vector.
      symbol[sti].start  = token_start; // Pointer to original location in input file.
      symbol[sti].length = static_cast<unsigned>(length);      // Length of symbol.
      symbol[sti].cell   = cell;        // Cell in the hash vector.
      symbol[sti].type   = 0;           // Type of symbol: int, char, float, short.
      symbol[sti].term   = t;           // Terminal number for lookup funciton.
      symbol[sti].scope  = 0;           // Scope: global, local, inner loop.
      n_symbols++;
      return sti;                               // Return symbol table index.
   }
};
#endif
/* Local Variables:      */
/* mode: c++             */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
