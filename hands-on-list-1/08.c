#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*
8. Read-Only File Reading: Write a program to open a file in read-only mode, read line by line,
and display each line as it is read. Close the file upon reaching the end of the file.
*/

int main(){
    int fd = open("file08", O_CREAT | O_RDONLY);
    char temp;
    while(read(fd,&temp,1)){
        write(1,&temp,1);
        if(temp=='\n')
        getchar();
    }
    close(fd);
    return 0;
}

/*./a.out*/