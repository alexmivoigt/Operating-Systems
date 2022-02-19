#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  printf("Child A initialized\n");  
  for (int i = 0; i <= 10000; i++) {
    if (i % 1000 == 0) {
      printf("Child A reached iteration %d\n", i);
    }
  }
  exit(0);
}
