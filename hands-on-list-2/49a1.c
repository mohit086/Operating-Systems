#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>

// this sets the value. run this first
struct ticket{
    char *name;
    int num;
};

union sem{
    int val;
    struct semid_ds *buf; // buffer to get/set semaphore information
    unsigned short *arr;
};

int main(){
    int fd = open("tickets.txt", O_RDWR | O_CREAT, 0666);
    struct ticket ticket1 = {"temp", 101};
    write(fd, &ticket1, sizeof(struct ticket));
    printf("Train name: %s\n", ticket1.name);
    printf("Ticket number: %d\n", ticket1.num);
    close(fd);
    int key = ftok(".", 'a');
    int sem_id = semget(key, 1, IPC_CREAT | 0666); // get semaphore
    union sem inst;
    inst.val = 1;
    semctl(sem_id, 0, SETVAL, inst); // set value of semaphore to be 1 (binary semaphore)
    return 0;
}