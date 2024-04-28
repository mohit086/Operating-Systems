#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>

union sem{
    int val;
    struct semid_ds *buf;
    unsigned short int *array; 
};

int main(){
    union sem arg;
    int k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);
    int choice;
    printf("Choose 0 for binary semaphore, 1 for counting semaphore : ");
    scanf("%d", &choice);
    if (choice==0){
        printf("Created binary semaphore\n");
        arg.val = 1;
    }
    else if (choice==1){
        printf("Created counting semaphore\n");
        arg.val = 5;
    }
    else printf("Invalid choice\n");
    semctl(semid, 0, SETVAL, arg);
    return (0);
}