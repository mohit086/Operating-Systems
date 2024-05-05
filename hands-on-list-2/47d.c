#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
    int key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);
    int stat = shmctl(shmid, IPC_RMID, NULL);
    if(stat==-1) printf("Delete Failed\n");
    else printf("Deleted\n");
    return 0;
}