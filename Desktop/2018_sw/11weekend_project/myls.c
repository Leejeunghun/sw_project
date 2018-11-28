#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
     int i=0;
     DIR *dirp;
     struct stat buf;
     
     struct dirent *dp;
     if(argc!=2){
         fprintf(stderr,"usage:myls dirname/n");
	 exit(0);
	 }
     
     dirp=opendir(argv[1]);
     for(i=0; i<100;i++)
     {
         dp= readdir(dirp);
	 if(dp==NULL)
	 break;
	 else
         {
              printf("%s   \n",dp->d_name);
	 }
         stat(dp->d_name,&buf);
         switch (buf.st_mode & S_IFMT){
            case S_IFREG: printf("regular file\n"); break;
            case S_IFDIR: printf("dir\n"); break;
            default : printf("unknown\n"); break;

     }
}
}
