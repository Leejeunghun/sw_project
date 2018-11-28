#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>
void ouch(int sig)
{
   printf("OUCH : I am groot%d)",sig);

}
void quit_sig(int sig)
{
  printf("quit_ig: GOOD bye\n");
  exit(0);
}

void My_ssigalam_handler(int sig)
{
     printf("Alarm \n");
     alarm(1);
}
int main ()
{
   struct sigaction sa;
   sigemptyset(&sa.sa_mask);
   sa.sa_flags=0;
   sa.sa_handler =ouch;
   sigaction(SIGINT,&sa,NULL);

   struct sigaction sa_int;
   sigemptyset(&sa_int.sa_mask);
   sa_int.sa_flags=0;
   sa_int.sa_handler =quit_sig;
    
   sigaction(SIGQUIT,&sa_int,NULL);
  
   struct sigaction sa_ALRM;
   sigemptyset(&sa_ALRM.sa_mask);
   sa_ALRM.sa_flags=0;
   sa_ALRM.sa_handler =My_ssigalam_handler;
   sigaction(SIGALRM,&sa_ALRM,NULL);

   //class
   //struct sigaction sa_int
   //sa_int.sa.handler =ouch
   //s
   //for (;;){ } for loopa
   alarm(5);
   while(1)
   {
      printf("hello %ld  \n",(long)getpid());
      sleep(1);
    }
   return 0;

}
