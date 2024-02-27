#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/*
22. Creating a Zombie State: Write a program to create a zombie state in the running program.
*/

int main(){
	int p = fork();
	if(p==0) printf("Child PID: %d\n",getpid());
	else{
        printf("Parent PID: %d\n",getpid());
        while(1);
    }
	return 0;
}

/*./a.out, then ps -lax*/