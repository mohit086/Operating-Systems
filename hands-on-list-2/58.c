#include <pthread.h>
#include <stdio.h>

void handler(void){
    printf("From thread: %ld\n", pthread_self());
}
// use -lpthread flag while compiling using gcc if not linked to pthread default
int main(){
    unsigned long id1, id2, id3;
    pthread_create(&id1, NULL, (void *)handler, NULL);
    pthread_create(&id2, NULL, (void *)handler, NULL);
    pthread_create(&id3, NULL, (void *)handler, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id3, NULL);
    return 0;
}