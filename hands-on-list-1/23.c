#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/*
23. Creating an Orphan Process: Develop a program to create an orphan process.
*/

int main(){
	int p = fork();
	if(p==0){
		printf("In child process with PID %d\n", getpid());
		printf("PPID before reparenting is %d\n", getppid());
		sleep(5);
		printf("PPID after reparenting is %d\n", getppid());
	}
	else{
		printf("In parent process with PID %d\n", getpid());
		sleep(1);
	}
	return 0;
}

/*./a.out*/