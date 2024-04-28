#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
    signal(SIGINT,SIG_IGN);
    printf("SIGINT has been ignored\n");
    sleep(10);
    signal(SIGINT,SIG_DFL);
    printf("SIGINT has been set to default\n");
    while(1);
}