#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

/*
28. Determining and Modifying Program Priority: Find out the priority of your running program
and modify it using the nice command.
*/

int main(){
    printf("Current priority: %d\n", getpriority(PRIO_PROCESS,getpid()));
    printf("Enter increment value between 0 and 19\n");
    int x; 
    scanf("%d",&x);    
    nice(x);
    printf("New priority: %d\n",getpriority(PRIO_PROCESS,getpid()));
    return(0);
}

/*./a.out*/