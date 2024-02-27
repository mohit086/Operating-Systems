#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
24. Creating and Waiting for Child Processes: Write a program to create three child processes.
The parent process should wait for a specific child process using the waitpid system call.
*/

int main(){
    int p1 = fork();
    if(p1){
        int p2 = fork();
        if(p2){
            int p3 = fork();
            if(p3){
                printf("Parent waiting for process %d using waitpid\n",p2);
                int wstat;
                waitpid(p2,&wstat,0);
                printf("Process %d exited with status %d\n",p2,wstat);
            }
        }
        else sleep(5);
    }
    return 0;
}

/*./a.out*/