#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
    if (!fork()){
        printf("Child process has pid %d\n", getpid());
        sleep(4);
        kill(getppid(), SIGKILL);
        printf("Parent killed, Child is now orphan\n");
        while(1);
    }
    else{
        printf("Parent process has pid: %d\n", getpid());
        while(1);
    }
    return 0;
}