#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
    int key = ftok(".", 'a'); // create sysV ipc key based on filename and project identifier
    int msqid = msgget(key, IPC_CREAT | 0666); // create a message queue using the key
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}