#include <iostream>
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;


//定义结构体
typedef struct LNode
  {   int data;
      struct LNode *next;
  } *LinkList;


//初始化列表
int InitList(LinkList &L)
{
      L=(LinkList)malloc(sizeof(LNode));
      if(!L)
            exit(0);
      L->next = NULL;
      return 1;
}

//插入元素
int ListInsert(LinkList L,int i,ElemType e)
{
      int j=0;
      LinkList p=L,s;
      while(p&&j<i-1)
      {
           p=p->next;
           j++;
      }
      if(!p||j>i-1)
            return 0;
   s=(LinkList)malloc(sizeof(LNode));
   s->data=e;
   s->next=p->next;
   p->next=s;
   return 1;
}
//按照升序排序(冒泡排序)
void SortList(LinkList &L)
{
      LinkList p=L;
      int i,j,temp;
      int count=0;
      while(p!=NULL)
      {
            count++;
            p = p->next;
      }
      for(i=0;i<count-1;i++)
      {
            p = L;
           for(j=0;j<count-i-1;j++)
      {
            if(p->data>p->next->data)
            {
                  temp = p->data;
                  p->data = p->next->data;
                  p->next->data=temp;
            }
            p=p->next;
      }
      }
}
//调用show函数遍历元素
int ListTraverse(LinkList L,void(*show)(ElemType))
 {
   LinkList p=L->next;
   while(p)
   {
      show(p->data);
      p=p->next;
   }
   printf("\n");
   return 1;
 }

//输出链表中的元素
void show(ElemType e)
 {
   printf("%d ",e);
 }
int main()
{
      LinkList L;
      ElemType e,e1;
      int i,n;
      InitList(L);
            printf("请输入要录入链表的元素个数：");
            scanf("%d",&n);
            printf("\n请输入要放入单链表中的元素:\n");
            for(i=1;i<=n;i++)
            {
                  scanf("%d",&e);
                  ListInsert(L,i,e);
            }
      printf("\n当前单链表中的元素为：\n");
      ListTraverse(L,show);
      printf("\n请输入要插入的元素：");
      scanf("%d",&e1);
      ListInsert(L,n+1,e1);
      SortList(L);
      printf("\n现在按照升序排序的新单链表为:\n");
      ListTraverse(L,show);

      return 0;
}
