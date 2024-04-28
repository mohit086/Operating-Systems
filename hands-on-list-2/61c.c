#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/sigaction.h>

void handler(int sig){
    printf("Signal received %d SIGFPE\n",sig);
}

int main(){
    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    ac.sa_handler = handler;
    sigaction(SIGFPE,&ac,NULL);
    // int a = 5, b = 0, c = a/b;
    while(1);
}