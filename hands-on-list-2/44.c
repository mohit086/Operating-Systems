#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

struct msgbuf{
    long mtype;
    char mtext[80];
};

int main(){
    int key = ftok(".", 'a');
    struct msgbuf msg;
    int type;
    int msqid = -1;
    int choice = -1;
    printf("Enter 0 to use 0 as a flag, 1 to use IPC_NOWAIT as a flag : ");
    scanf("%d", &choice);
    if (choice==0){
        msqid = msgget(key, 0);
        printf("Enter message type : ");
        scanf("%d", &type);
        if (msgrcv(msqid, (struct msgbuf *) &msg, 80, type, 0) == -1) printf("No message\n");
        else printf("Message : %s\n", msg.mtext);
    }
    else if (choice ==1){
        msqid = msgget(key, 0);
        printf("Enter message type : ");
        scanf("%d", &type);
        if (msgrcv(msqid, (struct msgbuf *)&msg, 80, type, IPC_NOWAIT) == -1) printf("No message\n");
        else printf("Message : %s \n", msg.mtext);
    }
    else printf("Invalid choice\n");
    return (0);
}