#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

/* 18. Record Locking Implementation: Write a program to perform record locking with the
following implementations:
a. Implement a write lock.
b. Implement a read lock.
Create three records in a file. Whenever you access a particular record, first lock it, then
modify/access it to avoid race conditions. */

struct Record{
    int id;
    char data[100];
};

int main(){
    struct Record r1,r2,r3;

    r1.id = 1; //initialising 3 records
    r2.id = 2;
    r3.id = 3;
    strcpy(r1.data,"data_of_record_1");
    strcpy(r2.data,"data_of_record_2");
    strcpy(r3.data,"data_of_record_3");
    
    int fd = open("file18",O_CREAT | O_RDWR, 0744);

    write(fd, &r1,sizeof(struct Record)); //writing them to a file
    write(fd, &r2,sizeof(struct Record));
    write(fd, &r2,sizeof(struct Record));

    struct flock lock; //defining the lock
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(struct Record);
    lock.l_start = 0;
    lock.l_type = F_WRLCK;

    fcntl(fd,F_SETLKW,&lock);
    printf("Record 1 write-locked, press enter to unlock\n");
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    printf("Unlocked\n");

    lock.l_type = F_RDLCK;
    lock.l_start = 2*sizeof(struct Record);
    fcntl(fd,F_SETLKW,&lock);
    printf("Record 3 read-locked, press enter to unlock\n");
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    printf("Unlocked\n");

    lock.l_start = 2* sizeof(struct Record);
    lock.l_type = F_WRLCK;
    fcntl(fd,F_SETLKW,&lock);
    printf("Record 3 write-locked, press enter to unlock\n");
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    printf("Unlocked\n");

    return 0;
}

/*./a.out, in 2 terminals*/