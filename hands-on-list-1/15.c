#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
15. Displaying User Environmental Variables: Create a program to display the environmental
variables of the user, utilizing the environ variable.
*/

int main(){
	extern char **environ;
	for(;*environ;environ++) printf("%s\n",*environ);
	return 0;
}

/*./a.out*/
