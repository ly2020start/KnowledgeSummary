
/**
 * The example demonstrate how to create sub process and thread. 
 * Print pids of main process, sub process and tid of thread on terminal. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>

#define gettid() syscall(__NR_gettid)  

void *print_hello() {
        printf("this is thread %d  \n", gettid()); // pthread_self
        while(1);
}

int main(void) {
        pid_t ret = 0;
        ret = fork();

        pthread_t pst;

        if(ret >  0) { // main process
                printf("parent pid %d\n", getpid());
                int err = pthread_create(&pst, NULL, print_hello, NULL);
        } else if(ret == 0) { // sub process
                printf("child pid %d\n", getpid());
        }


        while(1);
        return 0;
}
