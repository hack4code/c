/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Created:  04/03/2014 06:02:03 PM
 *
 * =====================================================================================
 */

#include <stdio.h>

int
main(int argc, char *argv[])
{
	union {
		short s;
		char c[2];
		struct {
		unsigned int b0 : 1,
			     b1 : 1,
			     b2 : 1,
			     b3 : 1,
			     b4 : 1,
			     b5 : 1,
			     b6 : 1,
			     b7 : 1,
			     b8 : 1,
			     b9 : 1,
			     b10 : 1,
			     b11 : 1,
			     b12 : 1,
			     b13 : 1,
			     b14 : 1,
			     b15 : 1;
		} b;
	} t;

	t.s = 0x0102;

	fprintf(stdout, "c[0] = %d c[1] = %d\n", t.c[0], t.c[1]);
	fprintf(stdout, "binary: %d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d\n",
			t.b.b15, t.b.b14, t.b.b13, t.b.b12, t.b.b11, t.b.b10, 
			t.b.b9, t.b.b8, t.b.b7, t.b.b6, t.b.b5, t.b.b4, t.b.b3, 
			t.b.b2, t.b.b1, t.b.b0);

	return 0;
}
