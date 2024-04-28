#include <stdio.h>
#include <unistd.h>

int main(){
    long maxfiles = sysconf(_SC_OPEN_MAX);
    long pipesize = pathconf(".", _PC_PIPE_BUF);
    printf("Max number of files that can be opened within a process: %ld\n", maxfiles);
    printf("Size of a pipe (circular buffer): %ld\n", pipesize);
    return 0;
}