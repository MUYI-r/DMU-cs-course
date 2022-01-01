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


/*辅助函数 输出文件的大小和最后修改时间*/
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
	        printf("\tsize:%ldbytes\tmodifiedate: %s\n",statbuf.st_size,ctime(&statbuf.st_mtime)); //输出文件的大小和最后修改时间
	return(0); 
	 
} 
/******************************** BFS 利用队列********************************************/
// 在strcpy 指针前要先 申请空间
struct node {
   char* data;
   struct node* next;
//   struct node* pre;
} *head,*tail,*tmp; // 头节点，尾节点，临时节点


// 队列大小
int count;
// 创建队列
void create() {
	head = NULL;
	tail = NULL;
	tmp  = NULL;
}
//入队
void enque(char* path)
{
  // 如果是空队列
  if (head == NULL)  {       
	  // 申请空间
	  head = (struct node*) malloc(sizeof(struct node));
	  head->data = (char*) malloc(strlen(path)+1); 
	  strcpy(head->data,path);
          head->next = NULL;
	  tail = head;
  } 
  // 不是空队列
  else {
    tmp = (struct node*) malloc(sizeof(struct node));
    strcpy(tmp->data,path);
    tail->next = tmp;
    tail = tmp;
  }
  count++;
}

// 出队列
char*  peek()
{
  char*  returnData ;
  if (head == NULL) {
     return NULL;
  } else {
     returnData = (char*) malloc(strlen(head->data)+1); 
     strcpy(returnData,head->data);
     if (head->next == NULL) {
        free(head);
	 head=NULL;
         tail=NULL;
     }  else {
	  struct node* now = head;
          head = head->next;
	 free(now);
     }
  }
  count--;
  return returnData;
}
// 返回队列大小
int size() {return count;}
/********************END********************************/




/*************** DFS ********************/
void  dfs(const char *path)
{
    DIR *dir;   // 定义目录指针
    char chdpath[256];  // 子目录的全路径    
    if ( (dir=opendir(path)) == 0  ) return; // 打开目录	       
    struct dirent *stdinfo; // 用于存放从目录读取到的文件和目录信息		 
    while (1)
    {
        if ((stdinfo=readdir(dir)) == 0) break;   // 读取一记录 逐个读取，读到目录最后退出			       
	if (strncmp(stdinfo->d_name,".",1)==0) continue;  // 以.开始的文件不读 没有这句会死循环
	if (stdinfo->d_type==8)    // 如果是文件，显示出来
	 {
	  
	  printf("%s/%s",path,stdinfo->d_name);
	  char* file = (char*)malloc(256);
	  sprintf(file,"%s/%s",path,stdinfo->d_name); // 重新设置路径
	  get_file_size_time(file);
	 }
	if (stdinfo->d_type==4)   // 如果是目录，再调用一次dfs
	 {
	   sprintf(chdpath,"%s/%s",path,stdinfo->d_name); // 重新设置路径
	   dfs(chdpath);					          
	 }					    
     }		   
    closedir(dir);   // 关闭目录指针		    
    return;
}
/**************BFS***********************/
void bfs(char* path) {
    DIR *dir;   // 定义目录指针
    char chdpath[256];  // 子目录的全路径    
    struct dirent *stdinfo; // 用于存放从目录读取到的文件和目录信息		 
    
    create();// 创建队列
    char* now=NULL;
    enque(path); // 根目录入队  
    now = (char*)malloc(200); // 给个额定大小

    while(size()) {
        strcpy(now,peek());//出队放到 now
 //       printf("现在的now:%s\n",now);
        // 显示错误 
	errno = 0;
	if ( (dir=opendir(now)) == 0  ) // 打开目录	
          {
            printf("错误信息：%s  %s\n",now,strerror(errno));		        
            return; 
	  }
     	
//  	printf("现在的PATH:%s\n",now);


	while(1) {
	if ((stdinfo=readdir(dir)) == 0) break;   // 读取一记录 逐个读取，读到目录最后退出			       
	if (strncmp(stdinfo->d_name,".",1)==0) continue;  // 以.开始的文件不读 没有这句会死循环
	if (stdinfo->d_type==8)    // 如果是文件，显示出来
	 {
          printf("%s/%s",now,stdinfo->d_name);				       
	  char* file = (char*)malloc(256);
	  sprintf(file,"%s/%s",now,stdinfo->d_name); // 重新设置路径
	  get_file_size_time(file);
	 }
	if (stdinfo->d_type==4)   // 如果是目录，入队
	 {
	   sprintf(chdpath,"%s/%s",now,stdinfo->d_name); // 重新设置路径
	   enque(chdpath);					          
	 }					    
       }
       closedir(dir);
    }
    free(now);
}

int main(int argc,char **argv) 
{ 
	DIR *dirp; 
	struct dirent *direntp; 
	int stats; 
	char path[1024];
	if(argc!=3) //判断输入是否为两个参数
	{ 
	     printf("Usage:%s filename way(bfs or dfs)\n",argv[0]); 
	     exit(1); 
	} 

//    DFS
        if (!strcmp(argv[2],"dfs"))
            dfs(argv[1]);
//    BFS
        else 
            bfs(argv[1]);
	
	return 0;
}


