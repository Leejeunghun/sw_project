#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
        char buf[80]={0,};
        int fd;
        read(STDIN_FILENO , buf ,  sizeof( buf ));  //read stdin
        write(STDOUT_FILENO, buf , strlen( buf ));  //wriet stdout

        if(argc !=2)
	{
	  printf("open test file name\n");
	  exit(0);
	}
        fd=open(argv[1], O_WRONLY | O_CREAT,0666);

	if(fd ==-1)
	{
           perror("open");
	   exit(0);

	}
        else
	{
           write(fd, buf , strlen( buf )); //write file 


	}
        return 0;
}
