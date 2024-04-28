#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    char buf[80];
    pipe(fd);
    if (!fork()){
        read(fd[0],buf,sizeof(buf));
        printf("Child reads : %s\n",buf);
    }
    else{
        printf("Parent writes : ");
        scanf("%[^\n]",buf);
        write(fd[1],buf,sizeof(buf));
    }
}