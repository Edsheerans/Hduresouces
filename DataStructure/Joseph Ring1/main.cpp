#include <iostream>

using namespace std;
struct LinkNode
{
      int num;                      //序号
      int password;
      LinkNode *next;
};

class Josephus
{
private:
      int M;                        //初始人数
      int N;
      int K;
      LinkNode *head;               //循环列表头结点
      LinkNode *link                //串联出列的结点
public:
      Josephus();                         //构造函数
      void createJoseRing();              //创建一个约瑟夫环
      void outputJoseRing(int n);         //传入出列序号，输出出列次序
};
int *p[10];
//构造函数
Josephus::Josephus()
{
      head=new LinkNode;
      head->num=1;
      head->next=head;
}
//创建一个约瑟夫环
void Josephus::createJoseRing()
{
      LinkNode *p=head;
      for(int i=2;i<=M;i++)
      {
            LinkNode *n = new LinkNode;
            n->num=i;
            n->next=head;
            p->next=n;
            p=n;
      }

}
//输出出列次序
void::Josephus::outputJoseRing()
{
      for(int i=1;i<=M;i++)
      {
            LinkNode *p=head;             //指针指向第一个人
            LinkNode *q=NULL;             //p的前驱指针
            int j=1;                      //计数器找到第N个人
            while(j!=N)
            {
                  j++;
                  q=p;
                  p=p->next;
            }

            q->next=p->next;
            head=q->next;

            link = p ;                          //第一个出列的元素
            p->next = head;                     //用辅助指针串联起出列的序号
            LinkNode* s = link ;
            while( s->next !=head)
            {
               s = s->next;
            }
            p->next = head;
            p->password = K;
            s->next = p;

            if(q->next==link)                   //将辅助指针link置空，head继续成为新表头
            {
                  LinkNode* _p=link;
                  link = NULL;
                  head = _p;                    //这里进行还原
            }

            cout << p->num << " ";

      }

}
int main()
{
      return 0;
}

