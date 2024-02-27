#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
25. Executing an Executable Program:
a. Execute a program using the exec system call.
b. Pass input to an executable program (e.g., execute an executable as $./a.out name).
*/

int main(int argc, char *argv[]){
	execv("/bin/ls", argv);
    printf("This will not be printed");
	return 0;
}

/*./a.out*/