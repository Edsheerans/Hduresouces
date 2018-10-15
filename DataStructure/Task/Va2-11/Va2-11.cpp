 #include "Va2-11.h"
 #include "Va.h"
using namespace std;
typedef int ElemType;

 //构造
 Status InitList(SqList &L)
 {
   L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L.elem)
     exit(OVERFLOW);
   L.length=0;
   L.listsize=LIST_INIT_SIZE;
   return OK;
 }
 //插入
 Status ListInsert(SqList &L,int i,ElemType e)
 {
   ElemType *newbase,*q,*p;
   if(i<1||i>L.length+1)
     return ERROR;
   if(L.length>=L.listsize)
   {
     if(!(newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType))))
       exit(OVERFLOW);
     L.elem=newbase;
     L.listsize+=LISTINCREMENT;
   }
   q=L.elem+i-1;
   for(p=L.elem+L.length-1;p>=q;--p)
     *(p+1)=*p;
   *q=e;
   ++L.length;
   return OK;
 }
 //遍历
  Status ListTraverse(SqList L,void(*show)(ElemType&))
 {
   ElemType *p;
   int i;
   p=L.elem;
   for(i=1;i<=L.length;i++)
     show(*p++);
   cout<<endl;
   return OK;
 }
