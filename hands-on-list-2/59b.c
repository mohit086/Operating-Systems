#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(){
    printf("signal SIGINT received\n");
}

int main(){
    signal(SIGINT,handler);
    while(1) ;
}

//press ctrl + c to see sigint signal