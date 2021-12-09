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

int lshftsi(int lhs, int rhs){
	int maxshift = (sizeof(int)*8);
	errno = 0;
	if( (rhs < 0) || (rhs >= maxshift)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	
	return lhs << rhs;
}

int rshftsi(int lhs, int rhs){
	errno = 0;
	if ((rhs < 0) || (rhs >= sizeof(int)*8)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	
	return lhs >> rhs;
}

unsigned int lshftui(unsigned int lhs, unsigned int rhs){
	errno = 0;
	if((rhs < 0) || (rhs >= sizeof(int)*8)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs << rhs;
}

unsigned int rshftui(unsigned int lhs, unsigned int rhs){
	errno = 0;
	if( (rhs < 0) || (rhs >= sizeof(int)*8)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs >> rhs;
}

signed long lshftsl(signed long lhs, signed long rhs){
	errno = 0;
	if( (rhs < 0) || (rhs >= sizeof(long)*8) ){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs << rhs;
}

signed long rshftsl(signed long lhs, signed long rhs){
	errno = 0;
	if( (rhs < 0) || (rhs >= sizeof(long)*8) ){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs >> rhs;
}

unsigned long lshftul(unsigned long lhs, unsigned long rhs){
	errno = 0;
	if ((rhs < 0) || (rhs >= sizeof(long)*8)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs << rhs;
}

unsigned long rshftul(unsigned long lhs, unsigned long rhs){
	errno = 0;
	if( (rhs < 0) || (rhs >= sizeof(long)*8) ){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs >> rhs;
}

signed long long lshftsll(signed long long lhs, signed long long rhs){
	errno = 0;
	if( (rhs < 0) || (rhs >= sizeof(long long)*8)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs << rhs;
}

signed long long rshftsll(signed long long lhs, signed long long rhs){
	errno = 0;
	if ( (rhs < 0) || (rhs >= sizeof(long long)*8)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs >> rhs;
}

unsigned long long lshftull(unsigned long long lhs, unsigned long long rhs){
	errno = 0;
	if( (rhs < 0) || (rhs >= sizeof(long long)*8)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs << rhs;
}

unsigned long long rshftull(unsigned long long lhs, unsigned long long rhs){
	errno = 0;
	if( (rhs < 0) || (rhs >= sizeof(long long)*8)){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs >> rhs;
}	

size_t lshftst(size_t lhs, size_t rhs){
	errno = 0;
	if( rhs >= sizeof(size_t)*8){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs << rhs;
}

size_t rshftst(size_t lhs, size_t rhs){
	errno = 0;
	if( rhs >= sizeof(size_t)*8){
		error_handler("OVERFLOW ERROR", &rhs, EINVAL);
		errno = EINVAL;
	}
	return lhs >> rhs;
}