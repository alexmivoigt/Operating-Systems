#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    long size;
    char *buf;
    char newdir[100];
    
    size = pathconf(".", _PC_PATH_MAX); //From the documentation example, it worked so I didn't mess with it
    
	printf("Alex Voigt");
	printf("\nCurrent directory: ");
	printf(getcwd(buf, (size_t)size));
	printf("\nEnter new directory path: ");
	scanf("%99s", newdir);
	chdir(newdir);
	printf("New directory: ");
	printf(getcwd(buf, (size_t)size));

	return(0);
}