#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

union sem{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main(){
    int sem_key1 = ftok(".",'A');
    int sem_key2 = ftok(".",'B');
    int sem_id1 = semget(sem_key1, 1 , IPC_CREAT | 0666 );
    int sem_id2 = semget(sem_key2, 1 , IPC_CREAT | 0666 );
    union sem inst;
    inst.val = -1; // indicates that one process is waiting for the resource
    int stat = semctl(sem_id2,0,SETVAL,inst);
    sleep(10);
    printf("Trying to acquire semaphore 1\n"); // trying to get semaphore 1
    struct sembuf sops;
    sops.sem_num = 0;
    sops.sem_op = -1;
    sops.sem_flg = 0;
    semop(sem_id1,&sops,1); // trying to lock sem1 but 50a already has it
}