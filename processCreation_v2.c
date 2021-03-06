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
    
    child_a = fork(); //fork Parent to Child A
    
    if (child_a == 0) { //execute Child A code
        execl("childA.out", "childA.out", NULL);
        exit(0);
    }
    
    child_b = fork(); //fork Parent to Child B
        
    if(child_b == 0) { //execute Child B code
        execl("childB.out", "childB.out", NULL);
        exit(0);
    }
    
    int status;
    pid_t pid;
            
    for (int i = 0; i < 2; i++) { //wait for children to finish
        pid = wait(&status);
        printf("Child terminated\n");
    }
            
    printf("Both children terminated, ending program\n");
    return(0);
}
