#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/sigaction.h>

void handler(int sig){
    printf("Signal received %d SIGSEGV\n",sig);
}

int main(){
    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    ac.sa_handler = handler;
    sigaction(SIGSEGV,&ac,NULL);
    // int* ptr = NULL;
    // *ptr = 10;
    while(1);
}