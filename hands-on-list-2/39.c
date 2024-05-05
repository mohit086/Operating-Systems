#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>

int main(){
    fd_set rfds; // set the file descriptor for select 
    struct timeval tv; // timeout struct 
    int fd = open("myfifo", O_RDWR, 0666);
    printf("Timer started for 10 seconds.\n");

    FD_ZERO(&rfds); // initialise file descriptor set and add fifo file descriptor to it
    FD_SET(fd, &rfds);

    tv.tv_sec = 10; // set timeout to 10 seconds
    tv.tv_usec = 0;

    int stat = select(fd + 1, &rfds, NULL, NULL, &tv); // call to select
    if (stat){
        char buf[100];
        read(fd, buf, sizeof(buf));
        printf("Data from fifo: %s", buf);
    }
    else printf("No data got in 10 seconds.\n");
    close(fd);
    return (0);
}