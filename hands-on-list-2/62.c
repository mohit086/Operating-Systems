#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include <signal.h>
#include <bits/sigaction.h>

int main(){
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_IGN;
    sigaction(SIGINT,&act,NULL);
    printf("SIGINT has beeen ignored\n");
    sleep(10);
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_DFL;
    sigaction(SIGINT,&act,NULL);
    printf("SIGINT has been set to default\n");
    while(1);
    return(0);
}