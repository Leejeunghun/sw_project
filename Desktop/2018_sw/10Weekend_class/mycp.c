#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <unistd.h>
#define SZ_BUF 1024

int main (int argc, char *argv[]){
  int fd;    
  int fd_out;
  int nb; 
  char buf[SZ_BUF]={0,};
    if(argc != 3)
    {
       printf("Opentest file name\n");
       exit(0);
    } 
    fd=open(argv[1], O_RDONLY );
    fd_out=open(argv[2], O_WRONLY | O_CREAT, 0x666  );

    if(fd==-1)
     {   
        perror("open");
        exit(0);
     }
    else
    { 
        printf("file %s open sucess\n",argv[1]);
      while( nb= read(fd,buf,SZ_BUF))
      {
        read(fd,buf,SZ_BUF);
        write(fd_out,buf,nb);
      }

   }  
   close(fd);
   close(fd_out);
   return 0;
}


