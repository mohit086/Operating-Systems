#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(){
    printf("signal SIGPROF received\n");
}

int main(){
    signal(SIGPROF,handler);
    struct itimerval it;
    it.it_value.tv_sec = 1;
    it.it_value.tv_usec = 0;
    it.it_interval.tv_sec = 1;
    it.it_interval.tv_usec = 0;
    setitimer(ITIMER_PROF,&it,NULL);
    while(1) ;
}