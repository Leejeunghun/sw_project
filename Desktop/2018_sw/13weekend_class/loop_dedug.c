#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void func3()
{
   func2();

}
void func2()
{
   func1();

}

void func1()
{
  while(1)
   {
      printf("%ld\n",(long)getpid());
      sleep(1);
    }
   
}

int main ()
{
   func3();
   //for (;;){ } for loop
   return 0;

}
