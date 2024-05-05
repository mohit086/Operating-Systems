#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

struct msgbuf{
    long mtype;
    char mtext[80];
};

int main(){
    int key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    struct msgbuf msg;
    msg.mtype = 2; //message type for the next question
    char text[80];
    printf("Enter message : ");
    scanf("%[^\n]", text);
    strcpy(msg.mtext, text);
    if (msgsnd(msqid, (struct msgbuf *) &msg, 80, IPC_NOWAIT) == -1) //last param is the flag 0/IPC_NOWAIT
        printf("Message not sent\n"); 
    else printf("Message sent successfully\n");
    return 0;
}