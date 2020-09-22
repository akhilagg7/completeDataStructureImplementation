#include<iostream>
using namespace std;

template <typename T>
class node
{
	public:
		T data;
		node<T> *next;
		node(T d)
		{
			data=d;
			next=NULL;
		}
		
};

template <typename T>
class stackUsingLL{
	node<T>* head;
	int size;
	
	public:
		stackUsingLL()
		{
			head=NULL;
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
		
		void push(T element)
		{
			node<T> *newnode=new node<T>(element);
			newnode->next=head;
			head=newnode;
			size++;
		}
		
		T top()
		{
			if(size==0)
			{
				cout<<"empty stack "<<endl;
				return 0;
			}
			return head->data;
		}
		
		T pop()
		{
			if(size==0)
			{
				cout<<"empty stack "<<endl;
				return 0;
			}
			int ans=head->data;
			node <T>*a=head;
			head=head->next;
			delete a;
			size--;
			return ans;
		}
};

int main()
{
//	stackUsingLL<int> s1;
//	s1.push(10);
//	s1.push(20);
//	s1.push(30);
//	s1.push(40);
//	s1.push(50);
//	cout<<s1.pop()<<endl;
//	cout<<s1.pop()<<endl;
//	cout<<s1.top()<<endl;
//	cout<<s1.getSize()<<endl;
//	cout<<s1.isEmpty()<<endl;
//	cout<<s1.pop()<<endl;
//	cout<<s1.pop()<<endl;
//	cout<<s1.top()<<endl;
//	cout<<s1.getSize()<<endl;
//	cout<<s1.isEmpty()<<endl;
		
//	cout<<endl;
	stackUsingLL<char> s1;
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s1.push('d');
	s1.push('e');
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.top()<<endl;
	cout<<s1.getSize()<<endl;
	cout<<s1.isEmpty()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.top()<<endl;
	cout<<s1.getSize()<<endl;
	cout<<s1.isEmpty()<<endl;
	
}
