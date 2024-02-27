#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

/*
16. Mandatory Locking Implementation: Write a program to perform mandatory locking with
the following implementations:
a. Implement a write lock.
b. Implement a read lock.
*/

int main(void){
	int fd = open("file16",O_CREAT | O_RDWR,0744);
	printf("Enter 0 for read lock, 1 for write lock\n");
	int x;
	scanf("%d",&x);
	struct flock lock;
	lock.l_type = x==0 ? F_RDLCK : F_WRLCK;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 0;
	int y = fcntl(fd,F_SETLK,&lock);
	perror("Status");
	x==0 ? printf("File read-locked by process %d\n",getpid()) : printf("File write-locked by process %d\n",getpid());
}

/*./a.out*/