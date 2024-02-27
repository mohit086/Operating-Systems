#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*
8. Read-Only File Reading: Write a program to open a file in read-only mode, read line by line,
and display each line as it is read. Close the file upon reaching the end of the file.
*/

int main(){
	int fd,rsize;
	char buf[1000];
	fd = open("file08", O_CREAT | O_RDONLY);
	while (rsize = read(fd,buf,sizeof(buf)) > 0) printf("%s",buf);
	close(fd);
	return 0;
}

/*./a.out*/