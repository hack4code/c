#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

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

	return 0;
}
