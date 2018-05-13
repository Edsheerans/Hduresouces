#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string>
using namespace std;

class STL_queue{
	public:
		STL_queue();
		~STL_queue();
		STL_queue(const STL_queue &q);
		STL_queue &operator=(const STL_queue &q);
		bool empty();
		bool En_queue(int t);
		int De_queue();
		void Print_queue();
		struct Q_Node
		{
			int data;
			Q_Node *next;
			Q_Node()
			{
				next = NULL;
			}
		};
		Q_Node *front;
		Q_Node *rear;
};

STL_queue::STL_queue()
{
	front = new Q_Node;
	rear = front;
}

STL_queue::~STL_queue()
{
	Q_Node *p;

	while(front)
	{
		p = front;
		front = front->next;
		delete p;
	 }
}

STL_queue::STL_queue(const STL_queue &q)
{
	Q_Node * p2 = q.front;
	while(p2)
	{
		Q_Node *newNode = new Q_Node;
		newNode->data = p2->next->data;
		rear->next = newNode;
		rear = newNode;


	}
}

STL_queue &STL_queue::operator=(const STL_queue &q)
{
	Q_Node* p=front;
    Q_Node* p2=q.front->next;
    while(p2)
    {
        Q_Node *newNode=new Q_Node;
        newNode->data=p2->data;

        p->next=newNode;
        rear=newNode;

        p=p->next;
        p2=p2->next;
    }
    return *this;
}

bool STL_queue::empty()
{
	return front == rear;
}

bool STL_queue::En_queue(int t)
{
	Q_Node *newNode = new Q_Node;
	newNode->data = t;
	newNode->next = NULL;
	rear->next = newNode;
	rear = newNode;
	return true;
}

int STL_queue::De_queue()
{
	if(!this->empty())
	{
		Q_Node *p = front;
		int t = p->next->data;
		front = front->next;
		delete p;
		return t;
	}


}

void STL_queue::Print_queue()
{
	while(!empty())
		cout<<De_queue()<<" ";
}

int main()
{
	char operation;
	STL_queue sq[3];
	int Num;
	int temp1,temp2;
	cin>>Num;
       while(Num--)
	{
		while(cin>>operation)
		{
			if(operation == 'E')
			{
				cin>>temp1;
				cin>>temp2;
				sq[temp1].En_queue(temp2);
			}

			if(operation == 'D')
			{
				cin>>temp1;
				cout<<sq[temp1].De_queue()<<" ";
			}

			if(operation == 'A')
			{
				cin>>temp1;
				sq[temp1].Print_queue();
			}
		}
	}

	return 0;
}
