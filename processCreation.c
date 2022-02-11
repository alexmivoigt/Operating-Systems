#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child_a;
    pid_t child_b;
    
    printf("Alex Voigt\n");
    
    child_a = fork();
    
    if (child_a == 0) {
        printf("Child A initialized\n");
        
        for (int i = 0; i <= 10000; i++) {
            if (i % 1000 == 0) {
                printf("Child A reached iteration %d\n", i);
            }
        }
        
        exit(0);
    } else {
        child_b = fork();
        
        if (child_b == 0) {
            printf("Child B initialized\n");
            
            for (int i = 0; i <= 10000; i++) {
                if (i % 1000 == 0) {
                    printf("Child B reached iteration %d\n", i);
                }
            }
            
            exit(0);
        } else {
            int status;
            pid_t pid;
            
            for (int i = 0; i < 2; i++) {
                pid = wait(&status);
            }
            return(0);
        }
    }
}
