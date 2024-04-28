#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
    int key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}