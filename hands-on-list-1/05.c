#include<stdio.h>
#include<fcntl.h>

/*
5. Continuous File Creation: Create a program that generates five new files in an infinite loop.
Execute the program in the background and inspect the file descriptor table at /proc/pid/fd.
*/

int main(){
	int fd1 = open("file05_1",O_CREAT | O_RDONLY,0774);
	int fd2 = open("file05_2",O_CREAT | O_RDONLY,0774);
	int fd3 = open("file05_3",O_CREAT | O_RDONLY,0774);
	int fd4 = open("file05_4",O_CREAT | O_RDONLY,0774);
	int fd5 = open("file05_5",O_CREAT | O_RDONLY,0774);
	while(1);
	return 0;
}

/*./a.out, then /proc/pid/fd from another terminal*/