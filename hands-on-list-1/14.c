#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

/*
14. File Type Identification: Write a program that takes input from the command line and
identifies the type of file. Ensure the program can recognize various file types.
*/

int main(int argc, char *argv[]){
    struct stat sb;
    if (argc != 2) {
        fprintf(stderr,"Usage: %s <file>\n",argv[0]);
        return 1;
    }
    if (lstat(argv[1],&sb) == -1){
        perror("Error");
        return 2;
    }
    stat(argv[1],&sb);
    printf("File type: ");
    if (S_ISREG(sb.st_mode)) printf("Regular file\n");
    else if (S_ISDIR(sb.st_mode)) printf("Directory\n");
    else if (S_ISCHR(sb.st_mode)) printf("Character Device File\n");
    else if (S_ISBLK(sb.st_mode)) printf("Block device file\n");
    else if (S_ISFIFO(sb.st_mode)) printf("FIFO file\n");
    else if (S_ISLNK(sb.st_mode)) printf("Softlink file\n");
    else if (S_ISSOCK(sb.st_mode)) printf("Socket file\n");
    else printf("Unknown\n");
    return(0);
}

/*./a.out filename*/