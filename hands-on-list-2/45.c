#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main(){
    int key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    struct msqid_ds st_to_set;
    struct msqid_ds st_to_read;
    msgctl(msqid, IPC_STAT, &st_to_read); // read stats into st_to_read
    printf("Current access Permissions : %o\n", st_to_read.msg_perm.mode);
    st_to_set.msg_perm.mode = 0777; // new permissions
    msgctl(msqid, IPC_SET, &st_to_set); // set new permissions
    msgctl(msqid, IPC_STAT, &st_to_read); // read stats into st_to_read again
    printf("New access Permissions : %o\n", st_to_read.msg_perm.mode);
    return (0);
}