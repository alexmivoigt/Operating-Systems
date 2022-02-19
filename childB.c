main() {
  printf("Child B initialized\n");  
  for (int i = 0; i <= 10000; i++) {
    if (i % 1000 == 0) {
      printf("Child B reached iteration %d\n", i);
    }
  }
  exit(0);
}
