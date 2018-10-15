#include <stdlib.h>
#include <stdio.h>

#define OVERFLOW 0
#define OK 1

typedef struct LNode
{
      int password;                       //密码
      int number;                         //编号
      struct LNode *next;
}LNode,*LinkList;

//创建一个带头结点的单循环链表
void InitList(LinkList &L)
{
      L=(LinkList)malloc(sizeof(LNode));
      if(!L)
            exit("OVERFLOW");
      L->next=L;
      return OK;
}
//初始化循环单链表
void CreateList(LinkList &L,int n)
{
      LinkList p,q;
      q=L;
      printf("请依次输入每个人的密码:");
      for(int i=1;i<=n;i++)
      {
            int k;
            scanf("%d",&k);

      }
}
int main()
{
    return 0;
}
