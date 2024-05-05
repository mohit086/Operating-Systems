#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
    int pid;
    printf("Enter pid \n");
    scanf("%d", &pid);
    printf("Sending SIGSTOP to process with pid %d\n", pid);
    kill(pid, SIGSTOP); // kill pid with sigstop
    return (0);
}