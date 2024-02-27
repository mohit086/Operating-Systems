#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*
10. File Write and Seek: Implement a program to open a file in read-write mode, write 10
bytes, move the file pointer by 10 bytes using lseek, and then write another 10 bytes.
a. Check the return value of lseek.
b. Open the file with od command and examine the empty spaces between the data.
*/

int main(){
	int fd = open("file10",O_CREAT | O_RDWR);
	perror("fd");
	char a[10] = {'0','1','2','3','4','5','6','7','8','9'};
	write(fd,a,10);
	int x = lseek(fd,10,SEEK_CUR);
	write(fd,a,10);
	printf("%d\n",x);
	close(fd);
	return 0;
}

/*./a.out, then od file10*/
