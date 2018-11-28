#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SZ_BUF 1024

int main(int argc, char *argv[])
{
    // using copy 
      int fd;
      int fd_out;
      int nb;
      char buf[SZ_BUF]={0,};
   // using chmod 
     struct stat buf_chmod;
     stat(argv[1],&buf_chmod); //buf_chmod save stat 
     printf("MODE: %Io\n",(unsigned long)buf_chmod.st_mode);//check permission
   //open file and copy file
   if(argc != 3) //argv num check
    {
       printf("Opentest file name\n");
       exit(0);
    }
    fd=open(argv[1], O_RDONLY );//read file open
    fd_out=open(argv[2], O_WRONLY | O_CREAT, 0x666 );//write file open
    // my cp 
    if(fd==-1)
     {
        perror("open");
        exit(0);
     }
    else
    {
      printf("file %s open sucess\n",argv[1]);
      while( nb= read(fd,buf,SZ_BUF)) //cp file
      {
        read(fd,buf,SZ_BUF);
        write(fd_out,buf,nb);
      } 

   }
   close(fd);
   close(fd_out);
   chmod(argv[2],buf_chmod.st_mode);
   
   return 0;


}

