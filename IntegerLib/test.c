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

#include "stdafx.h"
#include "IntegerLib.h"

int _tmain()
{	
	char retsc;
	unsigned char retuc;
	signed short retss;
	unsigned short retus;
	int retsi;
	unsigned int retui;
	long retsl;
	unsigned long retul;
	long long retsll;
	unsigned long long retull;

	char xsc, ysc;
	unsigned char xuc, yuc;
	signed short xss, yss;
	unsigned short xus, yus;
	int xsi, ysi;
	unsigned int xui, yui;
	long xsl, ysl;
	unsigned long xul, yul;
	long long xsll, ysll;
	unsigned long long xull, yull;

	set_constraint_handler_s(strict_handler);

	/* Addition Fuction testing */
	printf("Addition function testing\n\n");

	/* Char functions */
	printf("SCHAR_MAX + 0 \n");
	xsc = SCHAR_MAX;
	ysc = 0;
	retsc = si2sc(addsi(xsc, ysc));
	
	printf("SCHAR_MAX + 1 \n");
	ysc = 1;
	retsc = si2sc(addsi(xsc, ysc));
	
	printf("UCHAR_MAX + 0  \n");
	xuc = UCHAR_MAX;
	yuc = 0;
	retuc = ui2uc(addui(xuc, yuc));

	printf("UCHAR_MAX + 1\n");
	yuc = 1;
	retuc = ui2uc(addui(xuc, yuc));

	/* Short functions */
	printf("\nSHORT_MAX + 0\n");
	xss = SHRT_MAX;
	yss = 0;
	retss = si2ss(addsi(xss, yss));

	printf("SHORT_MAX + 1\n");
	yss = 1;
	retss = si2ss(addsi(xss, yss));

	printf("USHORT_MAX + 0\n");
	xus = USHRT_MAX;
	yus = 0;
	retus = ui2us(addui(xus, yus));

	printf("USHORT_MAX + 1\n");
	yus = 1;
	retus = ui2us(addui(xus, yus));

	/* int fuctions */
	printf("\nINT_MAX + 0\n");
	xsi = INT_MAX;
	ysi = 0;
	retsi = addsi(xsi, ysi);

	printf("INT_MAX + 1\n");
	ysi = 1;
	retsi = addsi(xsi, ysi);

	printf("UINT_MAX + 0\n");
	xui = UINT_MAX;
	yui = 0;
	retui = addui(xui, yui);

	printf("UINT_MAX + 1\n");
	yui = 1;
	retui = addui(xui, yui);

	/* long functions */
	printf("\nLONG_MAX + 0\n");
	xsl = LONG_MAX;
	ysl = 0;
	retsl = addsl(xsl,ysl);

	printf("LONG_MAX + 1\n");
	ysl = 1;
	retsl = addsl(xsl, ysl);

	printf("ULONG_MAX + 0\n");
	xul = ULONG_MAX;
	yul = 0;
	retul = addul(xul, yul);

	printf("ULONG_MAX + 1\n");
	yul = 1;
	retul = addul(xul, yul);

	/* long long functions */
	printf("\n LLONG_MAX + 0\n");
	xsll = LLONG_MAX;
	ysll = 0;
	retsll = addsll(xsll, ysll);

	printf("LLONG_MAX + 1\n");
	ysll = 1;
	retsll = addsll(xsll, ysll);

	printf("ULLONG_MAX + 0\n");
	xull = ULLONG_MAX;
	yull = 0;
	retull = addull(xull, yull);

	printf("ULLONG_MAX + 1\n");
	yull = 1;
	retull = addull(xull, yull);

	/* end addition functions */

	/* subtraction functions */
	printf("\nSubtraction Function Tests\n\n");

	/* char functions */
	printf("CHAR_MIN - 0\n");
	xsc = CHAR_MIN;
	ysc = 0;
	retsc = si2sc(subsi(xsc, ysc));

	printf("CHAR_MIN - 1\n");
	ysc = 1;
	retsc = si2sc(subsi(xsc, ysc));

	printf("(UCHAR) 0 - 0 \n");
	xuc = yuc = 0;
	retuc = ui2uc(subui(xuc, yuc));

	printf("(UCHAR) 0 - 1\n");
	yuc = 1;
	retuc = ui2uc(subui(xuc, yuc));

	/* short functions */
	printf("\nSHRT_MIN - 0\n");
	xss = SHRT_MIN;
	yss = 0;
	retss = si2ss(subsi(xss, yss));

	printf("SHRT_MIN -1\n");
	yss = 1;
	retss = si2ss(subsi(xss, yss));

	/* int functions */
	printf("\nINT_MIN - 0\n");
	xsi = INT_MIN;
	ysi = 0;
	retsi = subsi(xsi, ysi);

	printf("INT_MIN -1 \n");
	ysi = 1;
	retsi = subsi(xsi, ysi);

	printf("UINT_MIN - 0\n");
	xui = yui = 0;
	retui = subui(xui, yui);

	printf("UINT_MIN - 1\n");
	yui = 1;
	retui = subui(xui, yui);

	/* long functions */
	printf("\nLONG_MIN - 0\n");
	xsl = LONG_MIN;
	ysl = 0;
	retsl = subsl(xsl, ysl);

	printf("LONG_MIN - 1\n");
	ysl = 1;
	retsl = subsl(xsl, ysl);

	printf("ULONG_MIN - 0\n");
	xul = yul = 0;
	retul = subul(xul, yul);

	printf("ULONG_MIN - 1\n");
	yul = 1;
	retul = subul(xul, yul);

	/* long long functions */
	printf("\nLLONG_MIN - 0\n");
	xsll = LLONG_MIN;
	ysll = 0;
	retsll = subsll(xsll, ysll);

	printf("LLONG_MIN -1\n");
	ysll = 1;
	retsll = subsll(xsll, ysll);

	printf("ULLONG_MIN - 0\n");
	yull = xull = 0;
	retull = subull(xull, yull);

	printf("ULLONG_MIN -1\n");
	yull = 1;
	retull = subull(xull, yull);

	/* end subtraction functions */

	/* multiplication functions */
	printf("\nMultiplication function test\n\n");

	/* char fuctions */
	printf("SCHAR_MAX * 1\n");
	xsc = SCHAR_MAX;
	ysc = 1;
	retsc = si2sc(multsi(xsc, ysc));

	printf("SCHAR_MAX * 2\n");
	ysc = 2;
	retsc = si2sc(multsi(xsc, ysc));

	printf("SCHAR_MIN * 1\n");
	xsc = SCHAR_MIN;
	ysc = 1;
	retsc = si2sc(multsi(xsc, ysc));

	printf("SCHAR_MIN * -1\n");
	ysc = -1;
	retsc = si2sc(multsi(xsc, ysc));

	printf("UCHAR_MAX * 1\n");
	xuc = UCHAR_MAX;
	yuc = 1;
	retuc = ui2uc(multui(xuc, yuc));

	printf("UCHAR_MAX * 2\n");
	yuc = 2;
	retuc = ui2uc(multui(xuc, yuc));

	/* short functions */
	printf("\nSHRT_MAX * 1\n");
	xss = SHRT_MAX;
	yss = 1;
	retss = si2ss(multsi(xss, yss));

	printf("SHRT_MAX * 2\n");
	yss = 2;
	retss = si2ss(multsi(xss, yss));

	printf("SHRT_MIN * 1\n");
	xss = SHRT_MIN;
	yss = 1;
	retss = si2ss(multsi(xss,yss));

	printf("SHRT_MIN * -1\n");
	yss = -1;
	retss = si2ss(multsi(xss,yss));

	printf("USHRT_MAX * 1\n");
	xus = USHRT_MAX;
	yus = 1;
	retus = ui2us(multui(xus,yus));

	printf("USHRT_MAX * 2\n");
	yus = 2;
	retus = ui2us(multui(xus, yus));

	/* int functions */
	printf("\nINT_MAX *1\n");
	xsi = INT_MAX;
	ysi = 1;
	retsi = multsi(xsi,ysi);

	printf("INT_MAX * 2\n");
	ysi =2;
	retsi = multsi(xsi, ysi);

	printf("INT_MIN * 1\n");
	xsi = INT_MIN;
	ysi = 1;
	retsi = multsi(xsi, ysi);

	printf("INT_MIN * -1\n");
	ysi = -1;
	retsi = multsi(xsi, ysi);

	printf("UINT_MAX * 1\n");
	xui = UINT_MAX;
	yui = 1;
	retui = multui(xui, yui);

	printf("UINT_MAX * 2\n");
	yui = 2;
	retui = multui(xui, yui);

	/* long functions */
	printf("\nLONG_MAX * 1\n");
	xsl = LONG_MAX;
	ysl = 1;
	retsl = multsl(xsl, ysl);

	printf("LONG_MAX * 2\n");
	ysl = 2;
	retsl = multsl(xsl, ysl);

	printf("LONG_MIN * 1\n");
	xsl = LONG_MIN;
	ysl = 1;
	retsl = multsl(xsl,ysl);

	printf("LONG_MIN * -1\n");
	ysl = -1;
	retsl = multsl(xsl,ysl);

	printf("ULONG_MAX * 1\n");
	xul = ULONG_MAX;
	yul = 1;
	retul = multul(xul,yul);

	printf("ULONG_MAX * 2\n");
	yul = 2;
	retul = multul(xul, yul);

	printf("\nLLONG_MAX * 1\n");
	xsll = LLONG_MAX;
	ysll = 1;
	retsll = multsll(xsll, ysll);

	/* long long functions */
	printf("LLONG_MAX * 2\n");
	ysll = 2;
	retsll = multsll(xsll, ysll);

	printf("LLONG_MIN * 1\n");
	xsll = LLONG_MIN;
	ysll = 1;
	retsll = multsll(xsll, ysll);

	printf("LLONG_MIN * 2\n");
	ysll = 2;
	retsll = multsll(xsll, ysll);

	printf("LLONG_MIN * -1\n");
	ysll = -1;
	retsll = multsll(xsll, ysll);

	printf("ULLONG_MAX * 1 \n");
	xull = ULLONG_MAX;
	yull = 1;
	retull = multull(xull, yull);

	printf("ULLONG_MAX * 2\n");
	yull = 2;
	retull = multull(xull, yull);

	/* end mutliplication functions */

	/* division function tests */

	/* char functions */
	printf("\n(SCHAR_MIN + 1) / -1\n");
	xsc = SCHAR_MIN + 1;
	ysc = -1;
	retsc = si2sc(divsi(xsc,ysc));

	printf("SCHAR_MIN / -1\n");
	xsc = SCHAR_MIN;
	retsc = si2sc(divsi(xsc,ysc));

	printf("0 / N\n");
	xsc = 0;
	ysc = 10;
	retsc = si2sc(divsi(xsc, ysc));

	printf("n / 0\n");
	xsc = 10;
	ysc = 0;
	retsc = si2sc(divsi(xsc, ysc));

	printf("0 / 0\n");
	xsc = 0;
	retsc = si2sc(divsi(xsc, ysc));

	printf("UNSIGNED 0 / 0\n");
	xuc = 0;
	yuc = 0;
	retuc = ui2uc(divui(xuc, yuc));

	/* short functions */
	printf("\nSHRT_MIN+1 / -1\n");
	xss = SHRT_MIN + 1;
	yss = -1;
	retss = si2ss(divsi(xss, yss));

	printf("SHRT_MIN / -1\n");
	xss = SHRT_MIN;
	retss = si2ss(divsi(xss, yss));

	printf("SHRT_MAX / 0 \n");
	xss = SHRT_MAX;
	yss = 0;
	retss = si2ss(divsi(xss,yss));

	printf("0 / 0 \n");
	xss = 0;
	retss = si2ss(divsi(xss, yss));

	printf("UNSIGNED 0 / 0\n");
	xus = 0;
	yus = 0;
	retus = ui2us(divui(xus, yus));

	printf("UNSIGNED USHRT_MAX / 0\n");
	xus = USHRT_MAX;
	retus = ui2us(divui(xus, yus));

	/* int functions */
	printf("\nINT_MIN+1 / -1\n");
	xsi = INT_MIN +1;
	ysi = -1;
	retsi = divsi(xsi, ysi);

	printf("INT_MIN / -1\n");
	xsi = INT_MIN;
	retsi = divsi(xsi, ysi);

	printf("INT_MIN / 0\n");
	ysi = 0;
	retsi = divsi(xsi, ysi);

	printf("0 / 0\n");
	xsi = 0;
	retsi = divsi(xsi, ysi);

	printf("UNSIGNED UINT_MAX / 0\n");
	xui = UINT_MAX;
	yui = 0;
	retui = divui(xui, yui);

	printf("UNSIGNED 0 / UINT_MAX\n");
	retui = divui(yui, xui);

	printf("UNSIGNED 0 / 0\n");
	xui = 0;
	retui = divui(xui, yui);

	printf("\nLONG_MIN + 1 / -1\n");
	xsl = LONG_MIN + 1;
	ysl = -1;
	retsl = divsl(xsl, ysl);

	printf("LONG_MIN / -1\n");
	xsl = LONG_MIN;
	retsl = divsl(xsl, ysl);

	printf(" 0 / 0\n");
	xsl = 0;
	ysl = 0;
	retsl = divsl(xsl, ysl);

	printf("n / 0\n");
	xsl = LONG_MAX;
	retsl = divsl(xsl, ysl);

	printf(" 0 / n \n");
	xsl = 0;
	ysl = LONG_MAX;
	retsl = divsl(xsl, ysl);

	/* end division functions */
	
	/* unary negation functions */
	printf("\nUnary Negation Testing\n\n");
	printf(" -(SHCAR_MIN + 1)\n");
	xsc = SCHAR_MIN +1;
	retsc = unegsi(xsc);

	printf("-(SCHAR_MIN)\n");
	xsc = SCHAR_MIN;
	retsc = si2sc(unegsi(xsc));

	printf("-(INT_MIN + 1)\n");
	xsi = INT_MIN+1;
	retsi = unegsi(xsi);

	printf("-(INT_MIN)\n");
	xsi = INT_MIN;
	retsi = unegsi(xsi);

	printf("-(LONG_MIN+1)\n");
	xsl = LONG_MIN + 1;
	retsl = unegsl(xsl);

	printf("-(LONG_MIN)\n");
	xsl = LONG_MIN;
	retsl = unegsl(xsl);

	printf("-(LLONG_MIN +1)\n");
	xsll = LLONG_MIN + 1;
	retsll = unegsll(xsll);

	printf("-(LLONG_MIN)\n");
	xsll = LLONG_MIN;
	retsll = unegsll(xsll);

	/* end unary negation functions */


	return 0;
}

