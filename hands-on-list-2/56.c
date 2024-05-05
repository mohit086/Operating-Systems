#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

unsigned long long rdtsc(){ 
    unsigned long long dst;
    __asm__ __volatile__("rdtsc" : "=A"(dst));
    return dst;
}

int main(){
    unsigned long long start, end;
    struct timeval t1, t2;
    
    start = rdtsc();
    for (int i = 0; i < 100; i++) getppid();
    end = rdtsc();

    long long int duration_cycles = end - start;
    printf("Time taken for 100 getppid system calls: %llu clock cycles\n", duration_cycles);

    gettimeofday(&t1, NULL);
    for (int i = 0; i < 100; i++) getppid();
    gettimeofday(&t2, NULL);

    long long int duration_usec = (t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec);
    printf("Time taken for 100 getppid system calls: %lld microseconds\n", duration_usec);

    return 0;
}