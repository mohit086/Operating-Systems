#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(){
    printf("signal SIGALRM received\n");
}

int main(){
    signal(SIGALRM,handler);
    while(1){
        alarm(1);
        sleep(1);
    }
}