#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define KEY 1287
//note while testing, once you compile code, semaphore will already exist for defined KEY


//we need to take arguments to main in order to handle command line args
//shoutout to gbdirect.co.uk
int main(int argc, char *argv[]){

  /* using fgets below got me nowhere
  char input[1024];
  printf("Enter input here: ");
  fgets(input, 1024, stdin);
  *strchr(input, '\n') = 0; //insert terminating NULL
  */

  //-c N
  //create a semaphore and set value to N
  //if semaphore already exists, print a message indicating so

  //if the size of the args is 3
  if (argc == 3){
    //if the first part of args is -c
    if (strncmp(argv[1], "-c", 2) == 0){
      //semaphore descriptor sd will be used to input into semctl
      //we want to create 1 semaphore
      int sd = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);

      //if descriptor is 0, then we know it already exists
      if (sd > 0){
        int n;
        sscanf(argv[2], "%d", &n); //scan the string for the inputted n value
        printf("n value is %s \n", argv[2]);
        printf("semaphore created: %d \n", sd);

        //we're setting value of semaphore
        semctl(sd, 1, SETVAL, n);
        printf("value set: %d \n", semctl(sd, 1, GETVAL));
      }
      else{
        //if semaphore has value of 0, then it is unavailable
          printf("semaphore already exists \n"); }

    }

  }
}
