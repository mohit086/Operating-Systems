#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(){
    printf("signal SIGSEGV received\n");
}

int main(){
    signal(SIGSEGV,handler);
    //uncomment this to see sigsegv signal (segmentation fault)
    // int *ptr = NULL;
    // *ptr = 10;
    while(1) ;
}