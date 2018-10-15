#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define MAX_TREE_SIZE 100
#define ERROR 0
using namespace std;
typedef char TElemType;

typedef struct CTNode
{                                          //孩子结点
      int child;
      struct CTNode *next;
} *ChildPtr;

typedef struct
{                                               //双亲结点结构
      TElemType data;
      ChildPtr firstchild;                      //孩子链的头指针
      int parent;                               //双亲结点的位置
} CTBox;

typedef struct
{                                               //树结构
      CTBox nodes[MAX_TREE_SIZE];
      int n, r;                                 //结点数和根结点的位置
} CTree;

void InitTree(CTree &T)
{
      int i;
      printf("录入根节点的位置（非负数）：");
      scanf("%d",&i);
      if(i<0||i>MAX_TREE_SIZE-1)
      {
            printf(" i 值错误！\n");
            exit(ERROR);
      }
      T.r=i;
      T.n=0;
 }
//创建一棵树
void CreateTree(CTree &T)
 {
      TElemType ch;
      int i;                                    //i标记当前结点的父结点的位置
      int j;                                    //j标记当前结点的位置
      int k;                                    //k标记i结点的第一个孩子的位置
      ChildPtr p,q;                             //q始终指向child的尾指针
      printf("录入树的根节点-->");
      getchar();                                //抵掉回车
      scanf("%c",&ch);
      if(ch!='^')
      {
            i=T.r;
            T.nodes[i].parent=-1;
            T.nodes[i].data=ch;
            T.nodes[i].firstchild=NULL;
            T.n++;

            if(i!=0)                      //设置第二个结点的输入位置
                  j=0;                    //当前结点位置为0-根节点
            else                          //当前结点位置为1
                  j=1;
            k=j;
      }
      getchar();
      printf("输入结点:\n");
      scanf("%c",&ch);
      while(ch!='#')
     {
         p=q=NULL;
            while(1)
            {
                  scanf("%c",&ch);
                  if(ch=='^')
                        break;
                  else
                  {
                        T.nodes[j].parent=i;
                        T.nodes[j].data=ch;
                        T.nodes[j].firstchild=NULL;
                        T.n++;

                        p=(ChildPtr)malloc(sizeof(CTNode));
                        if(!p)
                             exit(ERROR);
                        p->child=j;
                        p->next=NULL;
                        if(T.nodes[i].firstchild==NULL)
                             T.nodes[i].firstchild=p;
                        else
                              q->next=p;
                              q=p;
                  }
                  if(j+1==T.r)
                        j=j+2;
                  else
                        j++;
            }
            i=k;
            if(j+1==T.r)
                  k=k+2;
            else
                  k++;
            scanf("%c",&ch);
    }
}
int TreeDepth(CTree T,int n)
{
        int max = 0;                // max是某个结点所有孩子中的最大深度
        int depth;
        ChildPtr p =T.nodes[n].firstchild;
        while(p)
      {
                depth = TreeDepth(T,p->child);
                if (depth > max)
                  max = depth;
                  p=p->next;
      }
        return max + 1;             //这里需要+1因为depth -> max是当前结点的孩子的深度, +1才是当前结点的深度
    }
int main()
{
      CTree T;
      InitTree(T);
      CreateTree(T);
      int depth=TreeDepth(T,T.r);
      printf("该树的深度为：%d\n",depth);
      return 0;
}
