#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*
7. File Copying: Develop a program to copy the contents of file1 into file2, emulating the
behavior of the $cp file1 file2 command.
*/

int main(){
	char buf[80];
	int fd = open("file07",O_CREAT | O_RDONLY);
	int size = read(fd,buf,sizeof(buf));
	close(fd);
	fd = open("file07_copy",O_CREAT | O_WRONLY);
	write(fd,buf,size);
	return 0;
}

/*./a.out*/