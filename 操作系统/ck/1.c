#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <dirent.h> 
#include <time.h> 
#include <string.h>
#include <ctype.h>
static int get_file_size_time(const char *filename) 
{ 
	struct stat statbuf; 
	if(stat(filename,&statbuf)==-1) //取 filename 的状态
	{ 
		printf("Get stat on %s Error:%s\n",filename,strerror(errno)); 
		 return(-1); 
		  
	} 
	if(S_ISDIR(statbuf.st_mode)) 
		return(1); //判断是否是目录文件
	if(S_ISREG(statbuf.st_mode)) //判断是否是普通文件
		 printf("%ssize:%ldbytes\tmodifiedat%s",filename,statbuf.st_size,ctime(&statbuf.st_mtime)); //输出文件的大小和最后修改时间
	 return(0); 
	 
} 
int main(int argc,char **argv) 
{ 
	DIR *dirp; 
	struct dirent *direntp; 
	int stats; 
	char path[1024];
	if(argc!=2) //判断输入是否为两个参数
	{ 
	   printf("Usage:%s filename\n\a",argv[0]); 
           exit(1); 		      
	 } 
	if(((stats=get_file_size_time(argv[1]))==0)||(stats==-1))
	   exit(1); //若 argv[1]为文件（输出文件大小和最后修改时间）或者 stats 错误，  
        if((dirp=opendir(argv[1]))==NULL) //打开目录，将打开的目录信息放至 dirp 中，若     为空，则打开失败
	 { 
	   printf("Open Directory %s Error:%s\n",argv[1],strerror(errno)); 
	   exit(1); 			       
         } 
        while((direntp = readdir(dirp)) != NULL) 
         {
           memset(path, 0, 1024);
           strcpy(path, argv[1]);
           strcat(path, "/");
	   strcat(path, direntp -> d_name);
	   if(get_file_size_time(path)==-1) //读取 dirp 目录下文件，直到出错或结束，退出
	   break; 			  
	  }
	 closedir(dirp); 
	 exit(1);       
}
