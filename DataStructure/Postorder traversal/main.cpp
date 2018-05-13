#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
typedef char TElemType;
#define OVERFLOW 0

typedef struct BiTNode
{
      TElemType data;
      struct BiTNode *lchild,*rchild;                        // 左右孩子指针
      bool status;                                           // 进栈标志
}BiTNode,*BiTree;

//创建一棵树
void CreateTree(BiTree &T)
{
      TElemType temp;
      scanf("%c",&temp);
      if(temp==' ')
            T=NULL;
      else
      {
            T=(BiTree)malloc(sizeof(BiTNode));
            if(!T)
                  exit(OVERFLOW);
            T->data=temp;
            CreateTree(T->lchild);
            CreateTree(T->rchild);
      }

}
//后序遍历的非递归算法
void PostOrderNoRecursive(BiTree T)
{
      stack<BiTNode*> s;
      BiTNode *p=T;
      while(p||(!s.empty()))
      {
            if(p)                                           //找到左子树，最后一个进栈的是最左子树
            {
                  p->status=false;                          //设置该结点第一次进栈
                  s.push(p);                                //节点以及节点标志进栈
                  p=p->lchild;                              //指针指向进栈节点的左子树，遍历左子树
            }
            else
            {
                  if(!s.empty())
                  {
                        p=s.top();
                        s.pop();
                        if(p->status)                       //该节点是第二次退栈，就访问，并设置p=0继续退栈
                        {
                              printf("%c\t",p->data);
                              p=NULL;
                        }
                        else
                        {
                              p->status = true;             //说明该节点是第一次退栈，将进栈标志设为true，设置该节点是第二次进栈
                              s.push(p);
                              p = p->rchild;                //指针指向该节点的右子树，遍历右子树
                        }
                  }
            }
      }
}
int main()
{
      BiTree T = NULL;
      printf("请输入你要创建的树的结点数据：\n");
      CreateTree(T);
      printf("后序遍历二叉树非递归算法输出为：\n");
      PostOrderNoRecursive(T);
      printf("\n");
      return 0;
}
