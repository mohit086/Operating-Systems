#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*
6. Input and Output Using System Calls: Craft a program to take input from STDIN and display
it on STDOUT using only read/write system calls.
*/

int main(){
	char buf[BUFSIZ];
	int size = read(0,buf,sizeof(buf));
	write(1,buf,size);
	return 0;
}

/*./a.out, then type your input*/