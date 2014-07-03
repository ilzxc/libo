/*
  Written by John MacCallum, The Center for New Music and Audio Technologies,
  University of California, Berkeley.  Copyright (c) 2011-13, The Regents of
  the University of California (Regents). 
  Permission to use, copy, modify, distribute, and distribute modified versions
  of this software and its documentation without fee and without a signed
  licensing agreement, is hereby granted, provided that the above copyright
  notice, this paragraph and the following two paragraphs appear in all copies,
  modifications, and distributions.

  IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
  SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING
  OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF REGENTS HAS
  BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
  PURPOSE. THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED
  HEREUNDER IS PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE
  MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
*/

/** 	\file osc_expr_ast_list.h
	\author John MacCallum

*/

#ifndef __OSC_EXPR_AST_LIST_H__
#define __OSC_EXPR_AST_LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "osc_atom_u.h"
#include "osc_bundle_u.h"

typedef struct _osc_expr_ast_list t_osc_expr_ast_list;

int osc_expr_ast_list_evalInLexEnv(t_osc_expr_ast_expr *ast,
				   t_osc_expr_lexenv *lexenv,
				   t_osc_bndl_u *oscbndl,
				   t_osc_atom_ar_u **out);
int osc_expr_ast_list_evalLvalInLexEnv(t_osc_expr_ast_expr *ast,
				       t_osc_expr_lexenv *lexenv,
				       t_osc_bndl_u *oscbndl,
				       t_osc_msg_u **assign_target,
				       long *nlvals,
				       t_osc_atom_u ***lvals);
long osc_expr_ast_list_format(char *buf, long n, t_osc_expr_ast_expr *v);
long osc_expr_ast_list_formatLisp(char *buf, long n, t_osc_expr_ast_expr *v);
t_osc_expr_ast_expr *osc_expr_ast_list_copy(t_osc_expr_ast_expr *ast);
void osc_expr_ast_list_free(t_osc_expr_ast_expr *v);
t_osc_bndl_u *osc_expr_ast_list_toBndl(t_osc_expr_ast_expr *e);
t_osc_expr_ast_expr *osc_expr_ast_list_fromBndl(t_osc_bndl_u *b);
t_osc_expr_ast_expr *osc_expr_ast_list_getList(t_osc_expr_ast_list *v);
t_osc_expr_ast_expr *osc_expr_ast_list_getListCopy(t_osc_expr_ast_list *v);
void osc_expr_ast_list_setList(t_osc_expr_ast_list *v, t_osc_expr_ast_expr *list);
long osc_expr_ast_list_getLen(t_osc_expr_ast_list *v);
t_osc_expr_ast_list *osc_expr_ast_list_alloc(t_osc_expr_ast_expr *list);

#ifdef __cplusplus
}
#endif

#endif