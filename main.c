#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void print_text(char* scr) {
  for(int i = 0; i < 10; i++)	{
    printf("%s %d\n", str, i);
  }
}

void *thread_body(void *param) { 
  print_texc("Child");
  return NULL;
}

int main(int argc, char *argv[]) { 
  pthread_t thread; 
  int code;
  
  code = pthread_create(&thread, NULL, thread_body, NULL); 
  if (code!=0)	{
    char buf[256];
    strerror_r(code, buf, sizeof buf);
    fprintf(stderr, "%s: creating thread error: %s\n", argv[0], buf); 
    exit(1);
  }
  
  print_text("Parent"); 
  pthread_exit(NULL);
}
