#include<unistd.h>
#include<stdio.h>
int main(int argc[],char *argv[])
{
   pid_t pid;
   printf("%s\n",argv[1]);
   execl("/bin/sh","argv[1]",NULL);
   

return 0;
}
