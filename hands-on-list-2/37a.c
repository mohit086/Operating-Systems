#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
// run this first, then b
int main(){
    char buf[80];
    int fd = open("myfifo",O_WRONLY, 0666);
    printf("Enter data to write: ");
    scanf("%[^\n]",buf);
    write(fd, buf, sizeof(buf));
    close(fd);
    return (0);
}