#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
  int fd;    
    if(argc != 2)
    {
       printf("Opentest file name\n");
       exit(0);
    } 
    fd=open(argv[1], O_RDONLY );
    printf("%d\n",fd);
    printf("%d\n",*argv[1]);
    printf("%d\n",argv[1]); 
    printf("%s\n",argv[1]);
    printf("%s\n",*argv);
    if(fd==-1)
     {   
        perror("open");
        exit(0);
     }
   else
   { 
        printf("file %s open sucess\n",argv[1]);

   }  
   close(fd);
  return 0;
}


