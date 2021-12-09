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

#ifndef __INTEGERLIB_H
#define __INTEGERLIB_H 1

#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef EOVERFLOW
#define EOVERFLOW 1
#endif

typedef void (*constraint_handler_t)(const char *msg, void *ptr, errno_t error);

/* standard error handlers */
extern void abort_handler(const char *msg, void *ptr, errno_t error);
extern void ignore_handler(const char *msg, void *ptr, errno_t error);
extern void strict_handler(const char *msg, void *ptr, errno_t error);

/* error handler to be called when an overflow occurs */
extern void (*error_handler)(const char* , void* , errno_t );

/* set_constraint_handler - sets the constraint handler to be called */
/* returns the previously set constraint handler */
extern constraint_handler_t set_constraint_handler_s(constraint_handler_t handler);

/* conversion functions */
extern signed char sl2sc(signed long i);

extern unsigned char sl2uc(signed long i);

extern signed char si2sc(int i);

extern unsigned char si2uc(int i);

extern signed char ui2sc(unsigned int i);

extern unsigned char ui2uc(unsigned int i);

extern signed char  ul2sc(unsigned long i);

extern unsigned char ul2uc(unsigned long i);

extern short ul2ss(unsigned long i);

extern unsigned short ul2us(unsigned long i);

extern short si2ss(int i);

extern short ui2ss(unsigned int i);

extern unsigned short si2us(int i);

extern unsigned short ui2us(unsigned int i);
/* end conversion functions */

/* addition functions */
extern int addsi(int lhs, int rhs);

extern unsigned int addui(unsigned int lhs, unsigned int rhs);

extern signed long addsl(signed long lhs, signed long rhs);

extern unsigned long addul(unsigned long lhs, unsigned long rhs);

extern signed long long addsll(signed long long lhs, signed long long rhs);

extern unsigned long long addull(unsigned long long lhs, unsigned long long rhs);
/* end addition functions */

/* subtraction functions */
extern int subsi(int lhs, int rhs);

extern unsigned int subui(unsigned int lhs, unsigned int rhs);

extern signed long subsl(signed long lhs, signed long rhs);

extern unsigned long subul(unsigned long lhs, unsigned long rhs);

extern signed long long subsll(signed long long lhs, signed long long rhs);

extern unsigned long long subull(unsigned long long lhs, unsigned long long rhs);
/* end subtraction functions */

/* multiplication functions */

extern signed long long multsll(signed long long lhs, signed long long rhs);

extern unsigned long long multull(unsigned long long lhs, unsigned long long rhs);

extern signed long multsl(signed  long lhs, signed  long rhs);

extern unsigned long multul(unsigned  long lhs, unsigned  long rhs);

/* signed int multiplication */
extern int multsi(int lhs, int rhs);

extern unsigned int multui(unsigned int lhs, unsigned int rhs);

/* division overflow detection */
extern int divsi(int lhs, int rhs);

extern unsigned int divui(unsigned int lhs, unsigned int rhs);

extern signed long divsl(signed long lhs, signed long rhs);

extern unsigned long divul(unsigned long lhs, unsigned long rhs);

extern signed long long divsll(signed long long lhs, signed long long rhs);

extern unsigned long long divull(unsigned long long lhs, unsigned long long rhs);
/* end division functions */

/* modulo functions */
extern int modsi(int lhs, int rhs);
extern unsigned int modui(unsigned int lhs, unsigned int rhs);
extern signed long modsl(signed long lhs, signed long rhs);
extern unsigned long modul(unsigned long lhs, unsigned long rhs);
extern signed long long modsll(signed long long lhs, signed long long rhs);
extern unsigned long long modull(unsigned long long lhs, unsigned long long rhs);
/* end modulo functions */

/* unary negation */
extern int unegsi(int rhs);
extern signed long unegsl(signed long rhs);
extern signed long long unegsll(signed long long rhs);

/* shift functions */
extern int lshftsi(int lhs, int rhs);
extern int rshftsi(int lhs, int rhs);
extern unsigned int lshftui(unsigned int lhs, unsigned int rhs);
extern unsigned int rshftui(unsigned int lhs, unsigned int rhs);
extern signed long lshftsl(signed long lhs, signed long rhs);
extern signed long rshftsl(signed long lhs, signed long rhs);
extern unsigned long lshftul(unsigned long lhs, unsigned long rhs);
extern unsigned long rshftul(unsigned long lhs, unsigned long rhs);
extern signed long long lshftsll(signed long long lhs, signed long long rhs);
extern signed long long rshftsll(signed long long lhs, signed long long rhs);
extern unsigned long long lshftull(unsigned long long lhs, unsigned long long rhs);
extern unsigned long long rshftull(unsigned long long lhs, unsigned long long rhs);

/* error handling functions */
extern void abort_handler(const char *msg, void *ptr, errno_t error);

extern void ignore_handler(const char *msg, void *ptr, errno_t error);

/* strict_handler - prints an error message to stderr */
extern void strict_handler(const char *msg, void *ptr, errno_t error);
	
#endif