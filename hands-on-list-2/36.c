#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
    char* path1 = "mknod_fifo";
    char* path2 = "mkfifo_fifo";
    mknod(path1, S_IFIFO | 0666, 0);
    mkfifo(path2,0666);
    printf("FIFO files created using both mkfifo and mknod\n");
    return 0;
}