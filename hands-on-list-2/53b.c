#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(){
    printf("Received SIGVTALRM\n");
}

int main(){
    struct itimerval it;
    signal(SIGVTALRM, handler);
    it.it_value.tv_sec = 10;
    it.it_value.tv_usec = 10;
    it.it_interval.tv_sec = 10;
    it.it_interval.tv_usec = 10;
    setitimer(ITIMER_VIRTUAL, &it, NULL); // decrements only when process is RUNNING
    while (1) ;
}