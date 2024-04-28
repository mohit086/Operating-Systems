#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
    int key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    char *data = shmat(shmid, (void *)0, 0);
    shmdt(data);
    printf("Detached\n");
    return (0);
}