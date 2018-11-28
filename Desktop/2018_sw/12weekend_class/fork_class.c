#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void fork_a()
{
   pid_t pid;
   fork();
   if(pid==fork)
   printf("hellO i am child\n");
   else
   {
    printf("hello i am parent\n");
   }
}
void lecture_fork()
{
    pid_t pid =fork();
    int child_status; 
    int i;
    switch(pid){
    case -1:
      printf("error\n");
      exit(0);
    case 0 :
      printf("child\n");
      execl("/bin/ls","ls","-l",NULL);
      exit(100);
      break;
    default:
      printf("parent\n");
      printf("I made a chile process %ld\n",pid);
      pid_t wpid =wait(&child_status);
      WIFEXITED(child_status);
      printf("child process terminated%d\n  %\n",WEXITSTATUS(child_status),child_status);
    break;
    }
}

void main ()
{
 //  fork_a();
   lecture_fork();
}
