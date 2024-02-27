#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
21. File Writing by Parent and Child Processes: Develop a program that opens a file, calls fork,
and allows both the child and parent processes to write to the file. Examine the output of
the file.
*/

int main(){
	int fd = open("file21", O_CREAT | O_RDWR);
	int p = fork();
	if(p==0){
		printf("In child\n");
		write(fd,"Written by child\n",sizeof("Written by child\n"));
	}
	else{
		printf("In parent\n");
		write(fd,"Written by parent\n",sizeof("Written by parent\n"));
	}
	return 0;
}

/*./a.out, then cat file21*/