#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> //using fork and execlq
#include <sys/types.h>
#include <sys/wait.h>
int my_system(char *command)
{
   pid_t pid=fork();   //create child process
   int child_status;   //to wait
  switch(pid){   
  case -1:   //error
       printf("error\n");
       exit(0);
  case 0:   //child
       printf("child\n");
       execl("/bin/sh","sh","-c",command,NULL); //child proces change 
       exit(100);
  default:  //parent
     wait(&child_status);   //parent wait child finish
     printf("%d\n",child_status);
     printf("%d\n",WEXITSTATUS(child_status));
     if(WIFEXITED(child_status))  //child normal exit
     return child_status;     //return child_status
  }
  
}

int main (void)
{
    int status;
    //status=system("ls-l |wc");
    status=my_system("ls -l |wc");
    printf("exit code %d\n",WEXITSTATUS(status));
   return 0;
}
