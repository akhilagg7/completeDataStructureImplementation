//implemented by: Akhil Aggarwal
//contact : akhilagg123@gmail.com

#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;
		node(int data)
		{
			this->data=data;
			next=NULL;
		}
};

class queue{
	node* head;
	node* tail;
	int size;
	
	public:
		queue()
		{
			head=NULL;
			tail=NULL;
			size=0;
		}
		
		int getSize()
		{
			return size;
		}
		
		bool isEmpty()
		{
			return size==0;
		}
		
		void push(int element)
		{
			node *newnode=new node(element);
			if(head==NULL)
			{
				head=newnode;
				tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
			size++;
		}
		
		int top()
		{
			if(size==0)
			{
				cout<<"queue is empty "<<endl;
				return 0;
			}
			return head->data;
		}
		
		int pop()
		{
			if(size==0)
			{
				cout<<"queue is empty "<<endl;
				return 0;
			}
			
			node *a=head;
			int ans=head->data;
			head=head->next;
			delete a;
			size--;
			return ans;
		}	
};

int main()
{
	queue q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout<<q.pop()<<endl;
	cout<<q.top()<<endl;
	q.push(40);
	cout<<q.pop()<<endl;
	q.push(50);
	q.push(60);
	q.push(70);
	q.push(80);
	q.push(90);
	cout<<q.top()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.isEmpty()<<endl;
	cout<<q.getSize()<<endl;
}
