#include<unistd.h>

int main(void)
{
    execl("/bin/sh","sh",NULL);    

return 0;
}
