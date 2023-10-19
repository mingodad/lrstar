
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

		#pragma once

		#include "PG_Actions.h"

		class PG_CheckGrammar : public PG_NodeActions
		{
			public:
			static int   CheckGrammar ();

			private:
			static void  C_LENG ();
			static void  C_NULLS ();
			static void  C_HEADSYM ();
			static void  check_first_args ();
			static void  KEYWORDS_WARNING ();
			static void  KEYWORDS_CHECK ();
			static void  P_UNUSED_OR_UNDECLARED ();
			static void  P_USELESS_PROD ();
			static void  P_UNREACHABLES ();
			static void  P_UNREDUCIBLES ();
			static void  p_prod (int p, int dot, const char *before);
			static int	 p_sym (int s, const char *sp);
		};

/* Local Variables:    */
/* mode: c             */
/* c-basic-offset: 3   */
/* tab-width: 3        */
/* indent-tabs-mode: t */
/* End:                */
