#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *thread_name) {
    printf("%s initialized\n", (char *) thread_name);
    
    for (int i = 0; i <= 10000; i++) {
        if (i % 1000 == 0) {
            printf("%s reached iteration %d\n", (char *) thread_name, i);
        }
    }
}

int main()
{
    pthread_t thread_a;
    pthread_t thread_b;
    char *name_a = "Thread A";
    char *name_b = "Thread B";
    
    printf("Alex Voigt\n");
    
    pthread_create(&thread_a, NULL, thread_function, (void*) name_a);
    pthread_create(&thread_b, NULL, thread_function, (void*) name_b);
    
    pthread_join(thread_a, NULL);
    printf("Thread A terminated\n");
    pthread_join(thread_b, NULL);
    printf("Thread B terminated\n");
    
    exit(0);
}