/*
 *
 * Copyright (c) 2005 Carnegie Mellon University.
 * All rights reserved.

 * Permission to use this software and its documentation for any purpose is hereby granted, 
 * provided that the above copyright notice appear and that both that copyright notice and 
 * this permission notice appear in supporting documentation, and that the name of CMU not 
 * be used in advertising or publicity pertaining to distribution of the software without 
 * specific, written prior permission.
 * 
 * CMU DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL CMU BE LIABLE FOR ANY SPECIAL, INDIRECT OR 
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, 
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, RISING OUT OF OR IN 
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
 */

#include "IntegerLib.h"

/* addition functions */
int addsi(int lhs, int rhs){
	errno = 0;
	if( (((lhs+rhs)^lhs)&((lhs+rhs)^rhs)) >> (sizeof(int)*CHAR_BIT-1) ) {
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}

	return lhs+rhs;
}

unsigned int addui(unsigned int lhs, unsigned int rhs){
	errno = 0;
	if(~lhs < rhs){
		error_handler("Arithmetic Overflow", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return lhs+rhs;
}

signed long addsl(signed long lhs, signed long rhs){
	errno = 0;
   if( (((lhs+rhs)^lhs)&((lhs+rhs)^rhs)) >> (sizeof(int)*CHAR_BIT-1) ) {
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
   }
   return lhs+rhs;
}

unsigned long addul(unsigned long lhs, unsigned long rhs){
	errno = 0;
	if(~lhs < rhs){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return lhs+rhs;
}

signed long long addsll(signed long long lhs, signed long long rhs){
	errno = 0;
	if( (((lhs+rhs)^lhs)&((lhs+rhs)^rhs)) >> (sizeof(signed long long)*CHAR_BIT-1) ) {
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
    }
    return lhs+rhs;
}

unsigned long long addull(unsigned long long lhs, unsigned long long rhs){
	errno = 0;
	if(~lhs < rhs){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return lhs + rhs;
}

size_t addst(size_t lhs, size_t rhs){
	errno = 0;
	if(~lhs < rhs){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return lhs + rhs;
}
/* end addition functions */