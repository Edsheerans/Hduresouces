#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_VERTEX_NUM 20
using namespace std;
int visited[MAX_VERTEX_NUM];


 struct ArcNode
 {
   int adjvex;                                  // 该弧所指向的顶点的位置
   ArcNode *nextarc;                            // 指向下一条弧的指针
 };                                             // 表结点
 typedef struct
 {
   char data;                             // 顶点信息
   ArcNode *firstarc;                           // 第一个表结点的地址,指向第一条依附该顶点的弧的指针
 }VNode,AdjList[MAX_VERTEX_NUM];                // 头结点
 struct ALGraph
 {
   AdjList vertices;
   int vexnum,arcnum;                           // 图的当前顶点数和弧数
 };

 //若G中存在顶点u,则返回该顶点在图中位置;否则返回-1
int LocateVex(ALGraph &G,char &v1)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data==v1)              //如果数组中有这个节点，返回该节点在数组中的索引
            return i;
    }
    return -1;
}
//构建一个图
void CreateDG(ALGraph &G)
{
      ArcNode *p,*q;
      char v1,v2,v;
      int i,j,k,n;
      printf("请输入图的顶点数和弧(边)数:");
      cin >> G.vexnum;
      cin >> G.arcnum;
      printf("请输入顶点:");
      for(i=0;i<G.vexnum;i++)                         //创建头结点
      {
            cin >> v;
            G.vertices[i].data=v;
            G.vertices[i].firstarc=NULL;
      }
      printf("请输入每条弧(边)的弧尾和弧头(以空格分开):");
      for(k=0;k<G.arcnum;k++)                         //创建边并连接头结点
      {
            cin >> v1;
            cin >> v2;
            i=LocateVex(G,v1);
            j=LocateVex(G,v2);
            if(G.vertices[i].firstarc==NULL)          //如果链表为空新建一个表节点，让头节点的指针指向该表节点
            {
                  p=(ArcNode*)new ArcNode;
                  G.vertices[i].firstarc=p;
                  q=G.vertices[i].firstarc;
            }
            else                                       //链表的插入
            {
                  q=G.vertices[i].firstarc;           //获取头结点的表头指针
                  for(n=0;n<G.arcnum;n++)             //将q指针移动至链表的尾处
                  {
                        if(!q->nextarc)
                              break;
                  }
                  p=(ArcNode*)new ArcNode;
                  q->nextarc=p;                       //将该边（弧）加入到链表中
                  q=q->nextarc;
            }
            q->adjvex=j;                              //记录弧头的索引
            q->nextarc=NULL;
      }
}
//基于深度优先搜索查询有没有i到j的弧
int DfsReachable(ALGraph G, int i, int j)
{
      ArcNode *w;
      int k;
      if(i==j)
            return 1;
      else
      {
            visited[i]=1;
            for(w=G.vertices[i].firstarc;w;w=w->nextarc)
            {
                  k=w->adjvex;
                  if(!visited[k]&&DfsReachable(G,k,j))
                        return 1;
                  else return 0;
            }
      }
      return -1;
}
int main()
{
    char i,j,m,n,t;
    ALGraph G;
    CreateDG(G);
    printf("请输入起始结点i:");
    cin >> i;
    m=LocateVex(G,i);
    printf("请输入最终结点j:");
    cin >> j;
    n=LocateVex(G,j);
    t=DfsReachable(G,m,n);
    if(t==1)
      printf("经查询该图中有此路径！");
    else
      printf("经查询该图中无此路径！");
}
