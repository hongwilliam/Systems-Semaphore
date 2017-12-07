#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define KEY 125182
//note while testing, once you compile code, semaphore will already exist for defined KEY


//we need to take arguments to main in order to handle command line args
//shoutout to gbdirect.co.uk
int main(int argc, char *argv[]){
  //semaphore descriptor sd will be used to input into semctl
  //we want to create 1 semaphore
  int sd;
  int n; //refer to -c N code

  //-c N
  //create a semaphore and set value to N
  //if semaphore already exists, print a message indicating so

  //if the size of the args is 3
  if (argc == 3){
    //if the first part of args is -c
    if (strncmp(argv[1], "-c", 2) == 0){
      //we want to create 1 semaphore
      sd = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
      //if descriptor is 0, then we know it already exists
      if (sd >= 0){
        sscanf(argv[2], "%d", &n); //scan the string for the inputted n value
        printf("n value is %s \n", argv[2]);
        printf("semaphore created: %d \n", sd);

        //we're setting value of semaphore
        semctl(sd, 1, SETVAL, n);
        printf("value set: %d \n", semctl(sd, 1, GETVAL)); }
      else{
            printf("semaphore already exists \n"); }
      }
    }

    if (argc == 2){
        //-v
        //view the CURRENT value of the semaphore
        //i haven't figured this out correctly
        if (strncmp(argv[1], "-v", 2) == 0){
          //include no flags, we are not creating a new semaphore
          sd = semget(KEY, 1, 0644);
          printf("semaphore value: %d \n", semctl(sd, 1, GETVAL)); }

        //-r
        //remove the semaphore
        if (strncmp(argv[1], "-r", 2) == 0){
          sd = semget(KEY, 1, 0644);
          //setting value of semaphore to 0 makes it unavaiable
          printf("semaphore removed: %d \n", semctl(sd, 1, SETVAL, 0)); }

    }

}
