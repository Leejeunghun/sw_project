#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <unistd.h>

#include <stdlib.h>


int main (int argc, char *argv[]){
  int fd;    
  int num_bytes;  
  
  if(argc ==3)  
  {
     //use O_append flag in open
    num_bytes=atoi(argv[2]);
    fd=open(argv[1], O_WRONLY|O_CREAT | O_APPEND, 0x666);
    if(fd==-1){
      perror("open");
      exit(0);
     }
    int i;
    for(i=0;i<num_bytes;i++){
     write(fd,"o",1);
    }
  } 
  else if (argc==4 && !strcmp(argv[3], "x")){
    //use lseek) & write()
    
  if(fd==-1){
   int i;
   perror("open");
   exit(0);
   }
   int i;
   for(i=0; i<num_bytes;i++){
   lseek(fd,0,SEEK_END);
   write(fd,0,num_bytes);

   }
   }

  return 0;
}


