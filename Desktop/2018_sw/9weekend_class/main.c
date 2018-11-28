#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main ()
{
   pid_t mypid; 
   pid_t ppid;
   mypid = getpid();
   ppid  = getppid();
   printf("%ld",(long)mypid);
   printf("%ld",(long)ppid);  
}
