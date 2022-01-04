#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.c" //引用自定义文件
int main()
{
int id;
memset(Head,0,sizeof(STU)*(N+1)); //清空数组缓存
while(1) {                        //循环执行
    menu();
    scanf("%d",&id);
    switch(id) {                  //根据id选择操作
        case 1:
            Input(Head);
            break;
        case 2:
            Loadstudent(Head,N);
            break;
        case 3:
            Show();
            break;
        case 4:
            FindnStudent();
            break;
        case 5:
            Findscore();
            break;
        case 6:
            Maxscore();
            break;
        case 7:
            Choosesort();
            break;
        case 8:
            Bubblesort();
            break;
        case 9:
            Save(Head,N);
            break;
        case 10:
            Insertsort();
            break;
        case 0:
            return 0;
            break;
        default:
            printf("没有此功能!!!!\n");
            system("cls");       //清屏
    }
  }
         return 0;
}
