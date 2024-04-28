#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    int fd = open("myfifo", O_RDONLY, 0666);
    char buf[80];
    read(fd, buf, sizeof(buf));
    printf("Reading from fifo: %s\n", buf);
    close(fd);
    return (0);
}