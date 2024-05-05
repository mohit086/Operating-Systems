#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>
// this implements locking and increments the values
struct ticket{
    char *name;
    int num;
};

struct sembuf op; // structure used for argument to semop to describe operations

int main(){
    int fd = open("tickets.txt", O_RDWR);
    if (fd == -1){
        printf("Unable to open file\n");
        return -1;
    }
    int key = ftok(".", 'a');
    int sem_id = semget(key, 1, 0); // get 1 semaphore
    op.sem_num = 0;
    op.sem_op = -1; // -1 for lock
    op.sem_flg = 0;
    printf("Locking...\n");
    int ret = semop(sem_id, &op, 1); // lock critical section using semop
    if (ret == -1){
        printf("Lock failed!s\n");
        return -1;
    }
    
    printf("Locked\n");
    struct ticket ticket1;
    read(fd, &ticket1, sizeof(struct ticket));
    printf("Current ticket number: %d\n", ticket1.num);
    ticket1.num += 1;
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket1, sizeof(struct ticket));
    lseek(fd, 0, SEEK_SET);
    read(fd, &ticket1, sizeof(struct ticket));
    printf("Incremented ticket number: %d\n", ticket1.num);
    printf("Press enter to unlock\n");
    getchar();

    op.sem_op = 1; // 1 for unlock
    int stat = semop(sem_id, &op, 1); // critical ends here, so unlock
    printf("Unlocked\n");
    close(fd);
}