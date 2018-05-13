#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef int Status;
typedef struct
{
      int top[2];
      ElemType *data;
      int stacksize;
}TwoWayStack;

Status inistack(TwoWayStack &tws,int size)
{
      tws.data=(ElemType*)malloc(sizeof(ElemType)*size);
      tws.stacksize=size;
      tws.top[0]=0;
      tws.top[1]=size-1;
      return 1;
}

Status push(TwoWayStack &tws,int i,ElemType x)
{
      if(tws.top[0]==tws.top[1])
            return 0;
      else if(i==0)
      {
            tws.data[tws.top[0]]=x;
            tws.top[0]=tws.top[0]+1;
      }
      else if(i==1)
      {
            tws.data[tws.top[1]]=x;
            tws.top[1]=tws.top[1]-1;
      }
      return 1;
}
Status pop(TwoWayStack &tws,int i,ElemType &x)
{
      if(tws.top[0]==0&&i==0)
            return 0;
      else if(tws.top[1]==tws.stacksize-1&&i==1)
            return 0;
      switch(i)
      {
            case 0:tws.top[0]-=1;
                   x=tws.data[tws.top[0]];
                   break;
            case 1:tws.top[1]+=1;
                   x=tws.data[tws.top[1]];
                   break;
      }
      return x;
}
int main()
{
      TwoWayStack s;
      ElemType e;
      inistack(s,5);
      push(s,1,1);
      push(s,1,3);
      push(s,1,5);
      push(s,1,8);
      for(int k=1;k<5;k++)
      {
            pop(s,1,e);
            printf("%d ",e);
      }

}
