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
      exit(55);
    case 0 :
      printf("child\n");
      for(i=0;i<1000;i++)
      {
          printf("child: %d\n",i);
	  fflush(NULL);
      }
      break;
    default:
      printf("parent\n");
      for(i=1000;i<2000;i++)
      {
         printf("parent: %d\n",i);
	 fflush(NULL);
      }
     // wait(&child_status);
     break;
    }
}

void main ()
{
 //  fork_a();
   lecture_fork();
}
