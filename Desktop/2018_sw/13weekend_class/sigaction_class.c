#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>
void ouch(int sig)
{
   printf("OUCH : I am groot%d)",sig);
}
int main ()
{
   struct sigaction sa;
   sigemptyset(&sa.sa_mask);
   sa.sa_flags=0;
   sa.sa_handler =ouch;
   //class
   //struct sigaction sa_int
   //sa_int.sa.handler =ouch
   //s
   //for (;;){ } for loop
   sigaction(SIGINT,&sa,NULL);  
   while(1)
   {
      printf("%ld\n",(long)getpid());
      sleep(1);
    }
   return 0;

}
