#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);

    if(!fork()){
        close(1); // close stdout
        dup2(fd1[1],1); // duplicate it to write end of fd1 
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("/bin/ls","/bin/ls","-Rl","/home/",(char*)NULL); // this will go to write end of fd1, not stdout
    }
    else {
        if(!fork()){
            close(0); // close stdin and stdout
            close(1);
            dup2(fd1[0],0); // duplicate stdin to read end of fd1
            dup2(fd2[1],1); // duplicate stdout to write end of fd2
            close(fd1[1]);
            close(fd2[0]);
            execlp("/bin/grep","/bin/grep","^d",(char*)NULL); // this will read earlier stuff and go to fd2
        }
        else{
            close(0); // close stdin
            dup2(fd2[0],0); // duplicate it to read end of fd2
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execlp("/bin/wc","/bin/wc","-l",(char*)NULL); // takes from fd2 and prints it on screen
        }
    }
    return 0;
}