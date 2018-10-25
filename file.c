#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int thing = open("./test.txt", O_RDWR/* | O_APPEND*/);
  if(thing < 0){
    printf("ERROR\n");
    _exit(0);
  }

  if(write(thing, "I don't know what I'm doing\n", 28) < 0){
    printf("ERROR\n");
    _exit(0);
  }

  thing = open("./test.txt", O_RDWR);
  char string[100];
  if(read(thing, string, 28) < 0){
    printf("ERROR\n");
    _exit(0);
  }else{
    printf("%s\n", string);
  }

  if(close(thing) < 0){
    printf("ERROR\n");
    _exit(0);
  }
  printf("closed\n");
  return 0;
}
