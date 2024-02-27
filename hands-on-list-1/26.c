#include<stdio.h>
#include<unistd.h>

/*
26. Executing ls -Rl Using Various exec System Calls: Write a program to execute ls -Rl using
the following system calls:
a. execl
b. execlp
c. execle
d. execv
e. execvp
*/

int main(int argc, char *argv[], char *envp[]){
    int c;
    printf("Enter 0,1,2,3,4 to use execl, execlp, execle, execv, execvp respectively\n");
    scanf("%d",&c);
    if (c==0){
        printf("Executing ls -la using execl\n");
        execl("/bin/ls", ".", "-l", "-a", NULL);
    }
    else if (c==1){
        printf("Executing ls -la using execlp\n");
        execlp("ls", "ls", "-l", "-a", NULL);
    }
    else if (c==2){
        printf("Executing ls -la using execle");
        execle("/bin/ls", ".", "-l", "-a", NULL, envp);
    }
    else if (c==3){
        printf("Executing ls -la using execv");
        char* arr[] = {"/bin/ls", ".", "-l", "-a", NULL};
        execv(arr[0], arr);
    }
    else if (c==4){
        printf("Executing ls -la using execvp");
        char* arr[] = {"ls", "-l", "-a", NULL};
        execvp("ls", arr);
    }
    return 0;
}

/*./a.out*/