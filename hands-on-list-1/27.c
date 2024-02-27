#include <stdio.h>
#include <sched.h>

/*
27. Getting Maximum and Minimum Real-Time Priority: Develop a program to retrieve the
maximum and minimum real-time priority.
*/

int main(){
	printf("Max priority for real-time round-robin: %d\n", sched_get_priority_max(SCHED_RR));
	printf("Min priority for real-time round-robin: %d\n", sched_get_priority_min(SCHED_RR));
    printf("Max priority for real-time FIFO: %d\n", sched_get_priority_max(SCHED_FIFO));
	printf("Min priority for real-time FIFO: %d\n", sched_get_priority_min(SCHED_FIFO));
	return 0;
}

/*./a.out*/