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

void
sig_handler(int sig) {
    fprintf(stdout, "Sig handle\n");
    run1 = 0;
    run2 = 0;
}

void *
th_fun(void *arg) {
    while (*(int *)arg) {
        fprintf(stdout, "Hello\n");
        sleep(2);
    }
    fprintf(stdout, "Exit\n");
    pthread_exit(0);
    return NULL;
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
