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

/* division overflow detection */
int divsi(int lhs, int rhs){
	errno = 0;
	if ( (rhs == 0) || ((lhs == INT_MIN) && (rhs == -1))){
		error_handler("OVERFLOW ERROR", NULL, EINVAL);
		errno = EINVAL;
		return 0;
	}
	return lhs/rhs;
}


unsigned int divui(unsigned int lhs, unsigned int rhs){
	errno = 0;
	if(rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
		return 0;
	}
	return lhs/rhs;
}

signed long divsl(signed long lhs, signed long rhs){
	errno = 0;
	if( (rhs == 0) || ( (lhs == LONG_MIN) && (rhs == -1) ) ){
		error_handler("ERROR OVERFLOW", NULL, EOVERFLOW);
		errno = EINVAL;
		return 0;
	}
	return lhs/rhs;
}

unsigned long divul(unsigned long lhs, unsigned long rhs){
	errno = 0;
	if (rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
		return 0;
	}
	return lhs/rhs;
}

signed long long divsll(signed long long lhs, signed long long rhs){
	errno = 0;
	if( (rhs == 0) || ((lhs == LLONG_MIN) && (rhs == -1))){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
		return 0;
	}
	return lhs/rhs;
}

unsigned long long divull(unsigned long long lhs, unsigned long long rhs){
	errno = 0;
	if (rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
		return 0;
	}
	return lhs/rhs;
}

size_t divst(size_t lhs, size_t rhs){
	errno = 0;
	if(rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", NULL, EINVAL);
		errno = EINVAL;
		return 0;
	}
}
/* end division functions */
/* modulo functions */
int modsi(int lhs, int rhs){
	errno = 0;
	if (rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", &rhs, EINVAL);
		errno = EINVAL;
		return 0;
	}
	return lhs % rhs;
}

unsigned int modui(unsigned int lhs, unsigned int rhs){
	errno = 0;
	if (rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", &rhs, EINVAL);
		errno = EINVAL;
		return 0;
	}
	return lhs % rhs;
}

signed long modsl(signed long lhs, signed long rhs){
	errno = 0;
	if (rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", &rhs, EINVAL);
		errno = EINVAL;
		return 0;
	}
	return lhs % rhs;
}

unsigned long modul(unsigned long lhs, unsigned long rhs){
	errno = 0;
	if (rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", &rhs, EINVAL);
		errno = EINVAL;
		return 0;
	}
	return lhs % rhs;
}

signed long long modsll(signed long long lhs, signed long long rhs){
	errno = 0;
	if (rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", &rhs, EINVAL);
		errno = EINVAL;
		return 0;
	}
	return lhs % rhs;
}

unsigned long long modull(unsigned long long lhs, unsigned long long rhs){
	errno = 0;
	if (rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", &rhs, EINVAL);
		errno = EINVAL;
		return 0;
	}
	return lhs % rhs;
}

size_t modst(size_t lhs, size_t rhs){
	errno = 0;
	if(rhs == 0){
		error_handler("DIVIDE BY ZERO ERROR", &rhs, EINVAL);
		errno = EINVAL;
		return 0;
	}

	return lhs %rhs;
}
/* end modulo functions */
