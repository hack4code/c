/**
 * 	reverse string, just like tac
 * 	assure dst has enough space for reverse src, and src is not empty
 */

void _tac(const char *src, char *dst) 
{
	int m, n = 0; /* src index, for copy, n is line start, and m is \n for last */
	int k = 0;    /* dst index */
	int i;

	while (src[n])
		++n;

	--n;
	m = n;

	/*	src may not end with \n, so we
	 * 	must append it
	 */
	if ('\n' != src[n]) {
		while ('\n' != src[n] && 0 < n)
			--n;

		/* only one line
		 */
		if (0 == n)
			goto firstline;

		for (i = n + 1; i <= m; ++i)
			dst[k++] = src[i];

		dst[k++] = '\n';
		m = n;
	}

	while (0 < --n)
		if ('\n' == src[n]) {
			for (i = n + 1; i <= m; ++i)
				dst[k++] = src[i];
			m = n;
		}

firstline:
	for (i = 0; i <= m; ++i)
		dst[k++] = src[i];

	dst[k] = '\0';
}


void tac(const char *src, char *dst)
{
	const char *start = src, *end, *tmp;

	while (*start)
		++start;

	--start;
	end = start;

	while (--start > src)
		if ('\n' == *start) {
			for (tmp = start + 1; tmp <= end; ++tmp)
				*dst++ = *tmp;

			if ('\n' != *end)
				*dst++ = '\n';

			end = start;
		}

	for (tmp = src; tmp <= end; ++tmp)
		*dst++ = *tmp;

	*dst = '\0';
}


#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	char dst[100];

	char *str1 = "hi,\nI am Lilei,\nHow are you.";
	tac(str1, dst);
	fprintf(stdout, "%s", dst);
	fprintf(stdout, "\n\n");

	char *str2 = "h.";
	tac(str2, dst);
	fprintf(stdout, "%s", dst);
	fprintf(stdout, "\n\n");

	char *str3 ="h";
	tac(str3, dst);
	fprintf(stdout, "%s", dst);
	fprintf(stdout, "\n\n");

	char *str4 ="hello\nworld\n";
	tac(str4, dst);
	fprintf(stdout, "%s", dst);

	return 0;
}
