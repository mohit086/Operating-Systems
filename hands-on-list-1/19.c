#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

/*
19. Process States: Develop a program to initiate a process in distinct states:
a. running
b. sleeping
c. stopped
Confirm the current state of the process using the relevant commands.
*/

int main(){
    int p1 = fork();
    if(p1){
        int p2 = fork();
        if(p2){
            printf("Process with PID %d is in running state\n",getpid());
            while(1);
        }
        else{
            printf("Process with PID %d is in sleeping state\n",getpid());
            sleep(100);
        }
    }
    else{
        printf("Process with PID %d is in stopped state\n",getpid());
        kill(getpid(),SIGSTOP);
    }
    return 0;
}

/*./a.out, then htop or ps -lax*/