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

/* multiplication functions */

signed long long multsll(signed long long lhs, signed long long rhs){
	errno = 0;
	if ( (lhs == 0) || (rhs == 0)) return 0;
	if( lhs > 0){
		if( rhs > 0){
			if(lhs > (LLONG_MAX / rhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		} else {
			if ( rhs < (LLONG_MIN / lhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		}
	} else {
		if(rhs > 0){
			if( lhs < (LLONG_MIN / rhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		} else {
			if( (lhs != 0) && (rhs < (LLONG_MAX / lhs))){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		}
	}

	return lhs * rhs;
}

unsigned long long multull(unsigned long long lhs, unsigned long long rhs){
	errno = 0;
	if (lhs == 0 || rhs == 0) return 0;

	if (lhs > ULLONG_MAX/rhs){ 
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}

	return lhs * rhs;
}

#if (LLONG_MAX >= 2*LONG_MAX)
signed long multsl(signed  long lhs, signed  long rhs){
	signed long long tmp = (signed long long)lhs * (signed long long)rhs;
	errno = 0;
	if ( (tmp > LONG_MAX) || (tmp < LONG_MIN)){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return (signed long)tmp;
}
#else
signed long multsl(signed long lhs, signed long rhs){
	errno = 0;
	if ( (lhs == 0) || (rhs == 0)) return 0;
	if( lhs > 0){
		if( rhs > 0){
			if(lhs > (LONG_MAX / rhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		} else {
			if ( rhs < (LONG_MIN / lhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		}
	} else {
		if(rhs > 0){
			if( lhs < (LONG_MIN / rhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		} else {
			if( (lhs != 0) && (rhs < (LONG_MAX / lhs))){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		}
	}

	return lhs * rhs;
}
#endif /* LLONG_MAX >= 2*LONG_MAX */

#if (ULLONG_MAX >= ULONG_MAX * 2)
unsigned long multul(unsigned  long lhs, unsigned  long rhs){
	unsigned long long tmp = (unsigned long long)lhs * (unsigned long long)rhs;
	errno = 0;
	if (tmp > (unsigned long long)ULONG_MAX){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return (unsigned long)tmp;
}
#else
unsigned long multul(unsigned long lhs, unsigned long rhs){
	errno = 0;
	if (lhs == 0 || rhs == 0) return 0;

	if (lhs > ULONG_MAX/rhs) {
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}

	return lhs * rhs;
}
#endif /* ULLONG_MAX >= ULONG_MAX*2 */

/* signed int multiplication */
#if (LONG_MAX >= 2*INT_MAX) 
int multsi(int lhs, int rhs){
	signed long tmp = (signed long)lhs * (signed long)rhs;
	errno = 0;

	if ((tmp > INT_MAX) || (tmp < INT_MIN)){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
}
#elif (LLONG_MAX >= 2*INT_MAX)
int multsi(int lhs, int rhs){
	signed long long tmp = (signed long long)lhs * (signed long long)rhs;

	errno = 0;
	if ( (tmp > INT_MAX) || (tmp < INT_MIN)) {
		/* The product cannot fit in a 32-bit int */
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}	

	return (int)tmp;
}
#else
int multsi(int lhs, int rhs){
	errno = 0;
	if ( (lhs == 0) || (rhs == 0)) return 0;
	if( lhs > 0){
		if( rhs > 0){
			if(lhs > (INT_MAX / rhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		} else {
			if ( rhs < (INT_MIN / lhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		}
	} else {
		if(rhs > 0){
			if( lhs < (INT_MIN / rhs)){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		} else {
			if( (lhs != 0) && (rhs < (INT_MAX / lhs))){
				error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
				errno = EINVAL;
			}
		}
	}

	return lhs * rhs;
}
#endif /* signed int multiplication */

#if (ULONG_MAX >= 2*UINT_MAX)
unsigned int multui(unsigned int lhs, unsigned int rhs){
	unsigned  long tmp = (unsigned long long)lhs * (unsigned long long)rhs;
	errno = 0;
	if (tmp > UINT_MAX ){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}

	return (unsigned int)tmp;
}
#elif (ULLONG_MAX >= 2*UINT_MAX)
unsigned int multui(unsigned int lhs, unsigned int rhs){
	unsigned long long tmp = (unsigned long long)lhs * (unsigned long long)rhs;
	errno = 0;
	if( (tmp > UINT_MAX) ){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return (unsigned int)tmp;
}
#else
unsigned int multui(unsigned int lhs, unsigned int rhs){
	errno = 0;
	if (lhs == 0 || rhs == 0) return 0;
	if( lhs > UMAX_INT/rhs){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return lhs * rhs;
}
#endif /* unsigned int multiplication */

size_t multst(size_t lhs, size_t rhs){
	errno = 0;
	if(lhs == 0 || rhs == 0) return 0;
	if(lhs > SIZE_MAX/rhs){
		error_handler("OVERFLOW ERROR", NULL, EOVERFLOW);
		errno = EINVAL;
	}
	return lhs * rhs;
}