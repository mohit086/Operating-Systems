#include <stdio.h>
#include <unistd.h>

/*
20. Printing Parent and Child Process IDs: Write a program that calls fork and prints both the
parent and child process IDs.
*/

int main(){
	int p = fork();
	p==0 ? printf("Child pid: %d\n", getpid()) : printf("Parent pid: %d\n", getpid());
	return 0;
}

/*./a.out*/