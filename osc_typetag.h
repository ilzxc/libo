/*
Written by John MacCallum, The Center for New Music and Audio Technologies,
University of California, Berkeley.  Copyright (c) 2009-12, The Regents of
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

#ifndef __OSC_TYPETAG_H__
#define __OSC_TYPETAG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include "osc_atom_u.h"
#include "osc_atom_array_u.h"

enum{
	OSC_TYPES_NULL = 0,
	OSC_TYPES_TRUE,
	OSC_TYPES_FALSE,
	OSC_TYPES_INT8,
	OSC_TYPES_UINT8,
	OSC_TYPES_INT16,
	OSC_TYPES_UINT16,
	OSC_TYPES_INT32,
	OSC_TYPES_UINT32,
	OSC_TYPES_INT64,
	OSC_TYPES_UINT64,
	OSC_TYPES_FLOAT32,
	OSC_TYPES_FLOAT64,
	OSC_TYPES_STRING
};

#define OSC_TYPETAG_ISFLOAT(tt) (tt == 'f' || tt == 'd')
#define OSC_TYPETAG_ISINT(tt) (tt == 'i' || tt == 'I' || tt == 'h' || tt == 'H' || tt == 'u' || tt == 'U' || tt == 'c' || tt == 'C')
#define OSC_TYPETAG_ISBOOL(tt) (tt == 'T' || tt == 'F')
#define OSC_TYPETAG_ISSTRING(tt) (tt == 's')
#define OSC_TYPETAG_ISNUMERIC(tt) (tt == 'f' || tt == 'd' || tt == 'i' || tt == 'I' || tt == 'h' || tt == 'H' || tt == 'u' || tt == 'U' || tt == 'c' || tt == 'C')

char *osc_typetag_str(int8_t tt);
int osc_typetag_compare(char tt1, char tt2);
char osc_typetag_getLargestType(int argc, t_osc_atom_array_u **argv);

#ifdef __cplusplus
}
#endif

#endif
