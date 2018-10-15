#ifndef VA2-11_H_INCLUDED
#define VA2-11_H_INCLUDED


typedef int ElemType;
typedef int Status;

 #define LIST_INIT_SIZE 10
 #define LISTINCREMENT 2
typedef struct LNode
  {   int data;
      struct LNode *next;
  } LNode;

//函数声明，函数定义在Va2-11.cpp里
Status InitList(SqList &L);
Status ListInsert(SqList &L,int i,ElemType e);
Status ListTraverse(SqList L,void(*show)(ElemType&));

#endif // VA2-11_H_INCLUDED*/
