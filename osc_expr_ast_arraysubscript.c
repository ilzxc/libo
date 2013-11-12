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

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "osc.h"
#include "osc_mem.h"
#include "osc_expr.h"
#include "osc_expr_func.h"
//#include "osc_expr_privatedecls.h"
#include "osc_expr_rec.h"
#include "osc_expr_ast_expr.h"
#include "osc_expr_ast_arraysubscript.h"
#include "osc_expr_ast_arraysubscript.r"


int osc_expr_ast_arraysubscript_evalInLexEnv(t_osc_expr_ast_expr *ast,
				      t_osc_expr_lexenv *lexenv,
				      long *len,
				      char **oscbndl,
				      t_osc_atom_ar_u **out)
{
	return 1;
}

long osc_expr_ast_arraysubscript_format(char *buf, long n, t_osc_expr_ast_expr *ast)
{
	if(!ast){
		return 0;
	}
	long offset = 0;
	t_osc_expr_ast_arraysubscript *a = (t_osc_expr_ast_arraysubscript *)ast;
	offset += osc_expr_ast_expr_format(buf ? buf + offset : NULL, buf ? n - offset : 0, a->base);
	offset += snprintf(buf ? buf + offset : NULL, buf ? n - offset : 0, "[[");
	t_osc_expr_ast_expr *ee = a->index_list;
	while(ee){
		offset += osc_expr_ast_expr_format(buf ? buf + offset : NULL, buf ? n - offset : 0, ee);
		if(ee->next){
			offset += snprintf(buf ? buf + offset : NULL, buf ? n - offset : 0, ", ");
		}
		ee = ee->next;
	}
	offset += snprintf(buf ? buf + offset : NULL, buf ? n - offset : 0, "]]");
	return offset;
}

t_osc_expr_ast_expr *osc_expr_ast_arraysubscript_copy(t_osc_expr_ast_expr *ast)
{
	if(ast){
		t_osc_expr_ast_arraysubscript *a = (t_osc_expr_ast_arraysubscript *)ast;
		t_osc_expr_ast_expr *basecopy = osc_expr_ast_expr_copy(a->base);
		t_osc_expr_ast_expr *indexcopy = osc_expr_ast_expr_copy(a->index_list);
		t_osc_expr_ast_arraysubscript *copy = osc_expr_ast_arraysubscript_alloc(basecopy, indexcopy);
		return (t_osc_expr_ast_expr *)copy;
	}else{
		return NULL;
	}
}

void osc_expr_ast_arraysubscript_free(t_osc_expr_ast_expr *e)
{
	if(e){
		osc_expr_ast_expr_free(((t_osc_expr_ast_arraysubscript *)e)->base);
		osc_expr_ast_expr_free(((t_osc_expr_ast_arraysubscript *)e)->index_list);
		osc_mem_free(e);
	}
}

t_osc_expr_ast_expr *osc_expr_ast_arraysubscript_getBase(t_osc_expr_ast_arraysubscript *e)
{
	if(e){
		return e->base;
	}
	return NULL;
}

t_osc_expr_ast_expr *osc_expr_ast_arraysubscript_getIndexList(t_osc_expr_ast_arraysubscript *e)
{
	if(e){
		return e->index_list;
	}
	return NULL;
}

void osc_expr_ast_arraysubscript_setBase(t_osc_expr_ast_arraysubscript *e, t_osc_expr_ast_expr *base)
{
	if(e){
		e->base = base;
	}
}

void osc_expr_ast_arraysubscript_setIndexList(t_osc_expr_ast_arraysubscript *e, t_osc_expr_ast_expr *index_list)
{
	if(e){
		e->index_list = index_list;
	}
}

t_osc_expr_ast_arraysubscript *osc_expr_ast_arraysubscript_alloc(t_osc_expr_ast_expr *base, t_osc_expr_ast_expr *index_list)
{
	if(!base || !index_list){
		return NULL;
	}
	t_osc_expr_ast_arraysubscript *e = osc_mem_alloc(sizeof(t_osc_expr_ast_arraysubscript));
	if(!e){
		return NULL;
	}
	osc_expr_ast_expr_init((t_osc_expr_ast_expr *)e,
			       OSC_EXPR_AST_NODETYPE_ARRAYSUBSCRIPT,
			       NULL,
			       osc_expr_ast_arraysubscript_evalInLexEnv,
			       osc_expr_ast_arraysubscript_format,
			       osc_expr_ast_arraysubscript_free,
			       osc_expr_ast_arraysubscript_copy,
			       sizeof(t_osc_expr_ast_arraysubscript));
	osc_expr_ast_arraysubscript_setBase(e, base);
	osc_expr_ast_arraysubscript_setIndexList(e, index_list);
	return e;
}