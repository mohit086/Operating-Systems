#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(){
    printf("Received SIGALRM\n");
}

int main(){
    struct itimerval it;
    signal(SIGALRM, handler); // will give a signal every 10 seconds
    it.it_value.tv_sec = 10; // initial timer value
    it.it_value.tv_usec = 10;
    it.it_interval.tv_sec = 10; // timer interval value
    it.it_interval.tv_usec = 10;
    setitimer(ITIMER_REAL, &it, NULL); // real-time timer, decrements regardless of process time
    while (1);
}