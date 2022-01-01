#ifndef BFS
#define BFS
#include <stdio.h>
#include <stdlib.h>

/******************************** 定义 队列********************************************/

struct node {
   int data;
   struct node* next;
//   struct node* pre;
} *head,*tail,*tmp; // 头节点，尾节点，临时节点

int count;

// 创建队列
void create() {
	head = NULL;
	tail = NULL;
}
//入队

void enque(int x)
{
  // 如果是空队列
  if (head == NULL)  {       
	  // 申请空间
	  head = (struct node*) malloc(sizeof(struct node));
	  head->data = x;
//	  head->pre = NULL;
          head->next = NULL;
	  tail = head;
  } 
  // 不是空队列
  else {
    tmp = (struct node*) malloc(sizeof(struct node));
    tmp->data = x;
    tail->next = tmp;
  //  tmp->pre = tail;
    tail = tmp;
  }
  count++;
}

// 出队列
int peek()
{
  int returnData = 0;
  if (head == NULL) {
     printf("队列为空\n");
     exit(1);
  } else {
     returnData = head->data;
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

int size() {return count;}

#endif
/****************************************************************************************/
/* test 
int main(int argc, char const *argv[])
{
	 create();
	 enque(5);
         printf("%d\n",size());
	 printf("%d\n",peek());
         printf("%d\n",size());
  	 return 0;
		    
}
*/
