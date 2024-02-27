#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

/*
4. Opening Existing File: Write a program to open an existing file in read-write mode.
Experiment with the O_EXCL flag.
*/

int main(){
	int fd = open("file04",O_CREAT|O_RDWR|O_EXCL,0744);
	perror("fd");
	printf("File descriptor: %d\n",fd);
	return 0;
}

/*./a.out. If the file already exists, this will give an error*/