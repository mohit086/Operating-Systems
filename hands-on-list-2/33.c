#include <stdio.h>
#include <unistd.h>

int main(){
    int fd1[2], fd2[2];
    char buf[80];
    pipe(fd1);
    pipe(fd2);
    if (!fork()){
        close(fd1[0]);
        close(fd2[1]);
        read(fd2[0],buf,sizeof(buf));
        printf("In child, parent message is : %s\n",buf);
        printf("Child message : ");
        scanf("%[^\n]",buf);
        write(fd1[1],buf,sizeof(buf));
    }
    else{
        close(fd1[1]);
        close(fd2[0]);
        printf("Parent message : ");
        scanf("%[^\n]",buf);
        write(fd2[1],buf,sizeof(buf));
        read(fd1[0],buf,sizeof(buf));
        printf("In parent, child message is : %s\n",buf);
    }
    return 0;
}
