#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd[2];
	pipe(fd);

    if (!fork()){
        close(fd[0]);
        close(1);
        dup2(fd[1], 1);
        execl("/bin/ls", "/bin/ls", "-l", NULL);
    }
    else{
        close(0);
        close(fd[1]);
        dup2(fd[0], 0);
        execl("/bin/wc", "/bin/wc", NULL);
    }
	return (0);
}