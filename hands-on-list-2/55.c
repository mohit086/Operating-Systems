#include <stdio.h>
#include <sys/resource.h>
#include <errno.h>

int main(){ // used getrlimit and setrlimit
    struct rlimit rlim;
    printf("Old limits\n");
    getrlimit(RLIMIT_CPU, &rlim);
    printf("Soft - %lu\n", rlim.rlim_cur);
    printf("Hard - %lu\n", rlim.rlim_max);
    rlim.rlim_cur = 2;
    rlim.rlim_max = 3;
    if (setrlimit(RLIMIT_CPU, &rlim) != -1){
        printf("New limits\n");
        getrlimit(RLIMIT_CPU, &rlim);
        printf("Soft - %lu\n", rlim.rlim_cur);
        printf("Hard - %lu\n", rlim.rlim_max);
    }
    return(0);
}