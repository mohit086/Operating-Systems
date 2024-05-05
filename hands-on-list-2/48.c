#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>

union sem{ // union for the semaphore
    int val; // value
    struct semid_ds *buf; // pointer to semaphore data struct
    unsigned short int *array; // array as a waiting queue
};

int main(){
    union sem arg;
    int k = ftok(".", 'a'); // create a key
    int semid = semget(k, 1, IPC_CREAT | 0666); // create 1 semaphore
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
    semctl(semid, 0, SETVAL, arg); // set value of semaphore using the arg union
    return (0);
}