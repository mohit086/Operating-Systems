#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(){
    printf("signal SIGFPE received\n");
}

int main(){
    signal(SIGFPE,handler);
    // int a = 0, b = 2, c = b/a;
    while(1) ;
}