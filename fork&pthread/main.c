/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2013 02:27:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wartalker (LiuWei), wartalker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int g_count = 0;

void *fun(void *arg)
{
	++g_count;
	fprintf(stdout, "thread: g_count = %d\n", g_count);
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	pid_t p;
	int s;
	pthread_t t;

	if (0 == (p = fork())) {
		++g_count;
		fprintf(stdout, "child: g_count = %d\n", g_count);
		exit(0);
	}

	waitpid(p, &s, 0);
	fprintf(stdout, "parent: g_count = %d\n", g_count);

	pthread_create(&t, NULL, fun, NULL);
	pthread_join(t, NULL);
	fprintf(stdout, "parent: g_count = %d\n", g_count);

	return EXIT_SUCCESS;
}
