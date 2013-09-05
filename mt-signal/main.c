/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/2013 08:06:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wartalker (LiuWei), wartalker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static int run1 = 1;
static int run2 = 1;

void *
th_fun(void *arg) {
    while (*(int *)arg) {
        fprintf(stdout, "%u: hello world!\n", pthread_self());
        sleep(2);
    }

    fprintf(stdout, "%u: exit\n", pthread_self());
    pthread_exit(0);
}

/*
 * signal handler 
 */

#if 0
void
sig_handler(int sig) {
    fprintf(stdout, "Sig handle %d\n", sig);
    run1 = 0;
    run2 = 0;
}

int
main(int argc, char **argv) {
    struct sigaction sig_act;
    pthread_t t1;
    pthread_t t2;

    memset((void *)&sig_act, 0, sizeof(sig_act));
    sigemptyset(&sig_act.sa_mask);
    sig_act.sa_handler = sig_handler;
    sig_act.sa_flags = 0;

    sigaction(SIGINT, &sig_act, NULL);
    sigaction(SIGTERM, &sig_act, NULL);
    sigaction(SIGQUIT, &sig_act, NULL);

    pthread_create(&t1, NULL, th_fun, &run1);
    pthread_create(&t2, NULL, th_fun, &run2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return EXIT_SUCCESS;
}
#endif

/*
 *  signal thread
 */

#if 1
void *
th_sig(void *arg) {
    sigset_t *set = arg;
    int sig;

    while (1) {
        sigwait(set, &sig);
        if ((SIGINT == sig) || (SIGTERM == sig) || (SIGQUIT == sig)) {
            fprintf(stdout, "signal handle %d\n", sig);
            run1 = 0;
            run2 = 0;
            break;
        }
    }
    pthread_exit(0);
}

int
main(int argc, char **argv) {
    sigset_t set;
    pthread_t ts;
    pthread_t t1;
    pthread_t t2;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGTERM);
    sigaddset(&set, SIGQUIT);
    
    pthread_sigmask(SIG_BLOCK, &set, NULL);

    pthread_create(&ts, NULL, th_sig, &set);
    pthread_create(&t1, NULL, th_fun, &run1);
    pthread_create(&t2, NULL, th_fun, &run2);

    pthread_join(ts, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return EXIT_SUCCESS;
}
#endif
