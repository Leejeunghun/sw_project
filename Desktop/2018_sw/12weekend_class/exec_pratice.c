#include<unistd.h>

int main(void)
{
   pid_t pid;
    const char *ps_argv[]={"ps","-ef",NULL};
    execl("bin/ls",*ps_argv);
   fork(); 
   if(pid==fork())
  {
    execl("/bin/ls",ps_argv);
  }   
else
   

return 0;
}
