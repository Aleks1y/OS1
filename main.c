#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define BUF_SIZE 256
#define SUCCESS 0
#define ERROR 1

void print_text(char* str) {
  for(int i = 0; i < 10; i++)	{
    printf("%s %d\n", str, i);
  }
}

void *thread_body(void *param) { 
  print_text("Child");
  return NULL;
}

int main(int argc, char *argv[]) { 
  pthread_t thread; 
  int code;
  
  code = pthread_create(&thread, NULL, thread_body, NULL); 
  if (code! = SUCCESS)	{
    char* buf = malloc(BUF_SIZE);
    while(ERANGE == strerror_r(code, buf, sizeof buf)){
      buf = realloc(buf, sizeof(buf) * 2);
    }
    fprintf(stderr, "%s: creating thread error: %s\n", argv[0], buf);
    free(buf);
    exit(ERROR);
  }
  
  print_text("Parent"); 
  pthread_exit(NULL);
}
