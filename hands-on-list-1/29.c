#include <stdio.h>
#include <unistd.h>
#include <sched.h>

/*
29. Getting and Modifying Scheduling Policy: Write a program to obtain the scheduling policy
and modify it (e.g., SCHED_FIFO, SCHED_RR).
*/

int main(){
    int c;
	printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	printf("Enter 1 to change to FIFO, 2 to change to RR\n");
    scanf("%d",&c);
    if (c!=1 && c!=2) printf("Error\n");
	struct sched_param sp;
    sp.sched_priority = 50;
	if(c == 1){
		sched_setscheduler(getpid(), SCHED_FIFO, &sp);
		printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	}
	else if (c == 2){
		sched_setscheduler(getpid(), SCHED_RR, &sp);
		printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	}
	return 0;
}

/*sudo ./a.out, otherwise the same policy will continue*/