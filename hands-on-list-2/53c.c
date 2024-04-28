#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(){
    printf("Received SIGPROF\n");
}

int main(){
    struct itimerval it;
    signal(SIGPROF, handler);
    it.it_value.tv_sec = 10;
    it.it_value.tv_usec = 10;
    it.it_interval.tv_sec = 10;
    it.it_interval.tv_usec = 10;
    setitimer(ITIMER_PROF, &it, NULL);
    while (1) ;
}