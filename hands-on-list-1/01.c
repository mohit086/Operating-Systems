#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

/* 
1. Creating Different File Types: Utilize both shell commands and system calls to create the
following types of files:
a. soft link (using the symlink system call)
b. hard link (using the link system call)
c. FIFO (using either the mkfifo Library Function or the mknod system call)
*/

int main(){
	printf("Enter source file, softlink, hardlink and FIFO filenames\n");

	char a[128],b[128],c[128],d[128];
	scanf("%s %s %s %s",a,b,c,d);
	open(a,O_CREAT | O_RDONLY);

	int i = symlink(a,b);
	int j = link(a,c);
	int k = mkfifo(d,0666);

	i==0 ? printf("Softlink created successfully\n") : printf("Error in creating softlink\n");
    j==0 ? printf("Hardlink created successfully\n") : printf("Error creating hardlink\n");
	k==0 ? printf("FIFO file created successfully\n") : printf("Error in creating FIFO file\n");

	return 0;
}

/*./a.out, type your inputs, then ls.*/