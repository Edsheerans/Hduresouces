#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define  M  100
typedef int ElemType;
typedef struct
{
	int data[M];
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack &s)
{
      s.top=0;
}
//判断栈是否为空
int StackEmpty(SqStack s)//判断栈是否为空
{
     if (s.top>0)
        return 0;
     else
        return 1;
}
//入栈函数
int push(SqStack &s,ElemType x)
{
 if(s.top==M-1)
      return 0;
 else
 {
      s.data[s.top]=x;
      s.top++;
      return 1;
 }

}
//出栈函数
int pop(SqStack &s)
{
      if(StackEmpty(s))
            printf("该栈为空！");
      ElemType x;
      x=s.data[--s.top];
      return x;
}
int getTop(SqStack &s)
{
      return s.data[s.top-1];
}
int main()
{
      SqStack s;
      int n,i;
      ElemType x;
      InitStack(s);
      printf("请输入要入栈的元素个数：");
      scanf("%d",&n);
      printf("\n请输入要入栈的元素:\n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&x);
            push(s,x);
      }
      printf("\n将该栈的元素输出为:\n");
      while (!StackEmpty(s))           //当第一个栈不为空时，让元素出栈
      {
            int elem;
            elem = getTop(s);
            printf("%d ",elem);
            pop(s);
      }
      printf("\n");

}
