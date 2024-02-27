# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>

/*17. Online Ticket Reservation Simulation: Develop a program to simulate online ticket
reservation with the implementation of a write lock. Write one program to open a file, store
a ticket number, and exit. Write a separate program to open the file, implement a write
lock, read the ticket number, increment the number, print the new ticket number, and then
close the file.*/

int main(){
    int fd;
    fd = open("file17", O_CREAT | O_RDWR);

    struct flock lock;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_start = 0;
    lock.l_type = F_WRLCK;

    fcntl(fd, F_SETLKW, &lock);
    printf("File is locked, press enter to unlock\n");
    int n = 0;
    lseek(fd, 0, SEEK_SET);
    read(fd, &n, sizeof(int));

    n++;
    printf("Number of tickets: %d\n", n);

    lseek(fd, 0, SEEK_SET);
    write(fd, &n, sizeof(int));

    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("File unlocked\n");

    close(fd);

    return 0;   
}

/*run 17a.c first, then ./a.out*/