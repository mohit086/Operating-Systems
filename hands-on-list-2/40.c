#include <stdio.h>
#include <unistd.h>

int main(){
    long maxfiles = sysconf(_SC_OPEN_MAX); // system config constant
    long pipesize = pathconf(".", _PC_PIPE_BUF); // path config constant
    printf("Max number of files that can be opened within a process: %ld\n", maxfiles);
    printf("Size of a pipe (circular buffer): %ld\n", pipesize);
    return 0;
}