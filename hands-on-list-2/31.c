#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    char buf[80];
    pipe(fd);
    printf("Write to the pipe : ");
    scanf("%[^\n]",buf);
    write(fd[1],buf,sizeof(buf));
    printf("Reading from pipe : ");
    read(fd[0],buf,sizeof(buf));
    printf("%s\n",buf);
}