#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main ()
{
   //for (;;){ } for loop
   while(1)
   {
      printf("%ld\n",(long)getpid());
      sleep(1);
    }
   return 0;

}
