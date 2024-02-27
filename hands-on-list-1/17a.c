# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

/*17. Online Ticket Reservation Simulation: Develop a program to simulate online ticket
reservation with the implementation of a write lock. Write one program to open a file, store
a ticket number, and exit. Write a separate program to open the file, implement a write
lock, read the ticket number, increment the number, print the new ticket number, and then
close the file.*/

int main(){
    printf("Give a number\n");
    int n = 1;
    scanf("%d", &n);

    int fd = open("file17", O_CREAT | O_WRONLY, 0744);
    write(fd, &n, sizeof(int));
    printf("Written successsfully\n");

    close(fd);
    return 0;
}

/*./a.out*/