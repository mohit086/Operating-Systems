#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
    int key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);
    char *data = shmat(shmid, (void *)0, SHM_RDONLY); // <- This will give segmentation fault
    printf("Enter data to put in shared memory: ");
    scanf("%[^\n]s", data);
    printf("Data written to shared memory\n");
    return(0);
}