/*
  Written by John MacCallum, The Center for New Music and Audio Technologies,
  University of California, Berkeley.  Copyright (c) 2011, The Regents of
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

/** 	\file osc_expr_oprec.r
	\author John MacCallum

*/
#ifndef __OSC_EXPR_OPREC_R__
#define __OSC_EXPR_OPREC_R__

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push)
#pragma pack(4)

/** \struct t_osc_expr_oprec
    A record that associates a function name (string) with a function pointer.
*/
struct _osc_expr_oprec
{
	char *name; /**< Name of the operator as a C string. */
	int input_arity;
	char **param_names;
	int output_arity; /**< All will be set to 1---this is here just in case we want to support this in the future. */
	char **output_names; /**< Plural for possible future support of multiple return values. */
	char *docstring;
	int associativity;
	int precedence;
	int fixity;
	char bytecode;
};
#pragma pack(pop)


#ifdef _cplusplus
}
#endif

#endif