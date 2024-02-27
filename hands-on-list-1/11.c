#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

/*
11. File Descriptor Duplication and Appending: Write a program to open a file, duplicate the
file descriptor, append the file with both descriptors, and verify whether the file is updated
correctly.
a. Use dup
b. Use dup2
c. Use fcntl
*/

int main(){
    int x;
    char name[20];
    printf("Enter 0 to use dup, 1 to use dup2, 2 to use fcntl\n");
    scanf("%d",&x);
    printf("Enter name\n");
    scanf("%s",name);
    int nfd, ofd = open(name,O_CREAT | O_RDWR);

    if(x==0){
        nfd = dup(ofd);
        perror("Status");
        write(ofd,"ofd\n",sizeof("ofd\n"));
        write(nfd,"nfd\n",sizeof("nfd\n"));
        close(nfd);
    }

    if(x==1){
        dup2(ofd,nfd);
        perror("Status");
        write(ofd,"ofd\n",sizeof("ofd\n"));
        write(nfd,"nfd\n",sizeof("nfd\n"));
        close(ofd);
        close(nfd);
    }
    
    if(x==2){
        nfd = fcntl(ofd,F_DUPFD);
        perror("Status");
        write(ofd,"ofd\n",sizeof("ofd\n"));
        write(nfd,"nfd\n",sizeof("nfd\n"));
        close(ofd);
        close(nfd);
    }
}

/*./a.out. Note - only one of the options will run at a time, after which you need to delete the file*/