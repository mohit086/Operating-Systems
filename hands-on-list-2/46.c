#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main(){ // delete a message queue using msgctl
    int key = ftok(".", 'a');
    int msqid = msgget(key, 0);
    if(msgctl(msqid, IPC_RMID, NULL) == -1) printf("Delete unsuccessful\n");
    else printf("Delete successful\n");
    return (0);
}