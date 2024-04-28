#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(){
    printf("signal SIGVTALRM received\n");
}

int main(){
    signal(SIGVTALRM,handler);
    struct itimerval itim;
    itim.it_value.tv_sec = 1;
    itim.it_value.tv_usec = 0;
    itim.it_interval.tv_sec = 1;
    itim.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL,&itim,NULL);
    while(1) ;
}