#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
  int sd;
  char input[1024];
  fgets(input, 1024, stdin);
  *strchr(input, '\n') = 0; //insert terminating NULL

  int key = ftok("temp", 1);
  //-c N
  //create a semaphore and set value to N
  //if semaphore already exists, print a message indicating so
  if (strncmp(input, "-c", sizeof(input) - 2)) == 0){
    char n_value = input[sizeof(input) - 1];
    int n = n_value - 48;
    if (semctl(semget(key), n, IPC_CREAT)),
  }


}
