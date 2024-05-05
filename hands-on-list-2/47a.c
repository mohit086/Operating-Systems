#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
    int key = ftok(".", 'a'); // create a key
    int shmid = shmget(key, 1024, IPC_CREAT | 0666); // create shared memory of size 1024 bytes
    char *data = shmat(shmid, (void *)0, SHM_R | SHM_W); // attach it to address space of calling process
    printf("Enter data to put in shared memory: ");
    scanf("%[^\n]s", data);
    printf("Data written to shared memory\n");
    // char *temp = shmat(shmid, (void *)0, SHM_R | SHM_W);
    // printf("%s\n",temp);
    return(0);
}