#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>

/*
9. File Information Extraction: Create a program to print various details about a given file,
including:
a. Inode
b. Number of hard links
c. UID
d. GID
e. Size
f. Block size
g. Number of blocks
h. Time of last access
i. Time of last modification
j. Time of last change
*/

int main(){
	struct stat file;
	int fd = open("file09",O_CREAT | O_RDONLY);
	stat("file09",&file);
	perror("fd");

	printf("Inode: %lu\n",file.st_ino);
	printf("No. of hardlinks: %lu\n",file.st_nlink);
	printf("UID: %d\n",file.st_uid);
	printf("GID: %d\n",file.st_gid);
	printf("Size: %ld\n",file.st_size);
	printf("Block size: %ld\n",file.st_blksize);
	printf("Number of blocks: %ld\n",file.st_blocks);
	printf("Time of last access: %s",ctime(&file.st_atime));
	printf("Time of last modification: %s",ctime(&file.st_mtime));
	printf("Time of last change: %s",ctime(&file.st_ctime));
	
	return 0;
}

/*./a.out*/