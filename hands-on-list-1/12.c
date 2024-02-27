#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

/*
12. Determining Opening Mode of a File: Create a program to find out the opening mode of a
file using the fcntl system call.
*/

int main(){
    int fd = open("file12", O_CREAT | O_RDONLY);
    int r = fcntl(fd,F_GETFL);
    perror("Status");
    int mode = r & O_ACCMODE;
    if(mode == O_RDONLY) printf("File opened in O_RDONLY mode\n");
    else if(mode == O_RDWR) printf("File opened in O_RDWR mode\n");
    else if (mode == O_WRONLY) printf("File opened in O_WRONLY mode\n");
    else printf("File opened in mode other than O_RDWR, O_RDONLY, O_WRONLY\n");
    close(fd);
    return 0;
}

/*./a.out*/
