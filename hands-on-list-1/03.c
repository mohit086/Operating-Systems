#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

/*
3. File Creation and Descriptor Printing: Write a program that creates a file and prints its file
descriptor value using the creat() system call.
*/

int main(){
	int fd = creat("file03",0744);
	perror("fd");
	printf("File descriptor is %d\n",fd);
	return 0;
}

/*./a.out*/