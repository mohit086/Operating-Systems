#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>

union sem{
    int val;
    struct semid_ds *buf;
    unsigned short int *arr;
};

int main(){
    union sem inst;
    key_t key = ftok(".", 'E');
    int semid = semget(key, 1, 0);
    semctl(semid, 2, IPC_RMID, inst);
    printf("Semaphore removed\n");
    return (0);
}