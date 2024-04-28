#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
    int key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    struct msqid_ds st;
    msgctl(msqid, IPC_STAT, &st);
    printf("Access Permissions - %o\n", st.msg_perm.mode);
    printf("Uid and gid of owner - %d %d\n", st.msg_perm.uid, st.msg_perm.gid);
    printf("Uid and gid of creator - %d %d\n", st.msg_perm.cuid, st.msg_perm.cgid);
    printf("Time of last message sent and received in queue - %ld %ld\n", st.msg_stime, st.msg_rtime);
    printf("Time of last change - %ld\n", st.msg_ctime);
    printf("Size of the queue - %ld\n", st.__msg_cbytes);
    printf("No of messages in queue - %ld\n", st.msg_qnum);
    printf("Max no. of bytes allowed in queue - %ld\n", st.msg_qbytes);
    printf("Pid of the last msgsnd and msgrcv - %d %d\n", st.msg_lspid, st.msg_lrpid);
    return (0);
}