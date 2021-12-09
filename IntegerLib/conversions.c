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

constraint_handler_t error_handler = strict_handler;

constraint_handler_t set_constraint_handler_s(constraint_handler_t handler){
	constraint_handler_t p = error_handler;
	if( handler == NULL)
		error_handler = abort_handler;
	else 
		error_handler = handler;
	return p;
}

/* conversion functions */
signed char sl2sc(signed long i) {
	errno = 0;
	if ( (i < SCHAR_MIN) || (i > SCHAR_MAX) ) {
		// handle error condition
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (signed char)i;
}

unsigned char sl2uc(signed long i){
	errno = 0;
	if ( (i < 0) || (i > UCHAR_MAX)){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (unsigned char)i;
}

signed char si2sc(int i){
	errno = 0;
	if ( (i < SCHAR_MIN) || (i > SCHAR_MAX) ){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (signed char)i;
}

unsigned char si2uc(int i){
	errno = 0;
	if ( (i < 0) || (i > UCHAR_MAX) ){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (unsigned char) i;
}

signed char ui2sc(unsigned int i){
	errno = 0;
	if ( (i > SCHAR_MAX) || ( i < 0)){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (signed char)i;
}

unsigned char ui2uc(unsigned int i){
	errno = 0;
	if ( (i > UCHAR_MAX) || (i < 0) ){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (unsigned char)i;
}

signed char  ul2sc(unsigned long i) {
	errno = 0;
	if ((i > SCHAR_MAX) || (i < SCHAR_MIN)) {
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (signed char)i;
}

unsigned char ul2uc(unsigned long i){
	errno = 0;
	if ((i < 0) || (i > UCHAR_MAX)){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (unsigned char)i;
}

short ul2ss(unsigned long i) {
	errno = 0;
	if ((i < SHRT_MIN) || (i > SHRT_MAX)) {
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (short)i;
}

unsigned short ul2us(unsigned long i){
	errno = 0;
	if ((i > USHRT_MAX) || (i < 0)){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (unsigned short)i;
}

short si2ss(int i){
	errno = 0;
	if( (i < SHRT_MIN) || (i > SHRT_MAX)){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (short)i;
}

short ui2ss(unsigned int i){
	errno = 0;
	if( i > SHRT_MAX){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}

	return (short)i;
}

unsigned short si2us(int i){
	errno = 0;
	if( (i < 0) || (i > USHRT_MAX)){
		error_handler("UNABLE TO DOWNCAST",NULL,ERANGE);
		errno = ERANGE;
	}
	return (unsigned short)i;
}

unsigned short ui2us(unsigned int i){
	errno = 0;
	if( i > USHRT_MAX){
		error_handler("UNABLE TO DOWNCAST", NULL, ERANGE);
		errno = ERANGE;
	}
	return (unsigned short)i;
}
/* end conversion functions */


/* error handling functions */
void abort_handler(const char *msg, void *ptr, errno_t error){
	fprintf(stderr,"ERROR: %d, %s\n",error, msg);
	abort();
}

void ignore_handler(const char *msg, void *ptr, errno_t error){
	/* do nothing, ignoring error */
	return;
}

/* strict_handler - prints an error message to stderr */
void strict_handler(const char *msg, void *ptr, errno_t error){
	fprintf(stderr, "ERROR: %d, %s\n", error, msg);
}