#include<iostream>
using namespace std;

//class of a linked list
class node{
	public:
		int data;
		node *next;
		node(int data)
		{
			this->data=data;
			next=NULL;
		}
};

//Linked list input with O(n^2) complexity
node *takeInput()
{
	int data;
	cin>>data;
	node *head=NULL;
	while(data!=-1)
	{
		node *newnode=new node(data);
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				
			}
			temp->next=newnode;
		}
		cin>>data;
	}
	return head;
}

//Linked list input with O(n) complexity
node *takeInputBetter()
{
	int data;
	cin>>data;
	node *head=NULL;
	node *tail=NULL;
	while(data!=-1)
	{
		node *newnode=new node(data);
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else
		{
			tail->next=newnode;
			tail=tail->next;
		}
		cin>>data;
	}
	return head;
}

//printing a linked list
void print(node *head)
{
	if(head==NULL)
	{
		return ;
	}
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

//insert element in a linked list
node* insert(node*head,int i,int data)
{
	if(head==NULL)
	{
		return NULL;
	}
	int count=0;
	node *temp=head;
	node *newnode=new node(data);
	if(i==0)
	{
		newnode->next=head;
		head=newnode;
		return head;
	}
	while(count<i-1&& temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return head;
}

//delete element from a linked list
node *del(node *head,int i)
{
	int count=0;
	if(i==0)
	{
		node *a=head;
		head=head->next;
		delete a;
		return head;
	}
	node *temp=head;
	while(count<i-1&&temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		node *a=temp->next;
		temp->next=a->next;
		delete a;
	}
	return head;
	
}

//insert recursively in linked list
node* insertRecursive(node*head,int i,int data)
{
	if(head==NULL)
	{
		cout<<"base condition called"<<endl;
		return NULL;
	}
	if(i==0)
	{
		cout<<"our calculation part called "<<endl;
		node *newnode =new node(data);
		newnode->next=head;
		head=newnode;
		return head;
	}
	node *ans=insertRecursive(head->next,i-1,data);
	head->next=ans;
	return head;
}

// code for recursively deleting node
node *delRecursive(node *head,int i)
{
	if(head==NULL)
	{
		return NULL ;
	}
	if(i==0)
	{
		node *a=head;
		head=head->next;
		delete a;
		return head;
	}
	node *ans=delRecursive(head->next,i-1);
	head->next=ans;
	return head;
}

//finding length of linked list
int length(node *head)
{
	if(head==NULL)
	{
		return 0;
	}
	int ans=length(head->next);
	return ans+1;
}
//middle of a linked list using length function
int mid1(node*head)
{
	int ans=length(head);
	int mid=(ans-1)/2;
	int count=0;
	while(count<mid)
	{
		head=head->next;
		count++;
	}
	return head->data;
}

//middle of a linked list using slow and fast pointer
int mid(node *head)
{
	node *slow=head;
	node *fast=head->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow->data;
}

//Merge two sorted Linked List
node*merge(node*h1,node*h2)
{
	node *fh=NULL;
	node *ft=NULL;

	if(fh==NULL)
	{
		if(h1->data<h2->data)
		{
			fh=h1;
			ft=h1;
			h1=h1->next;
		}
		else
		{
			fh=h2;
			ft=h2;
			h2=h2->next;
		}
	}
	
	while(h1!=NULL&&h2!=NULL)
	{
		if(h1->data<h2->data)
		{
			ft->next=h1;
			ft=h1;
			h1=h1->next;
		}
		else
		{
			ft->next=h2;
			ft=h2;
			h2=h2->next;
		}
	}
	if(h1!=NULL)
	{
		ft->next=h1;
		ft=h1;
		h1=h1->next;
	}
	if(h2!=NULL)
	{
		ft->next=h2;
		ft=h2;
		h2=h2->next;		
	}
	return fh;
}

//Reverse Linked list(recursive) in O(n^2)
node *reverse_LL(node *head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	node *smallAns=reverse_LL(head->next);
	node *temp=smallAns;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	return smallAns;
}

//Reverse Linked list(recursive) in O(n)
class pair1{
	public:
		node *head;
		node *tail;
};
pair1 reverse_LL2(node *head)
{
	if(head==NULL||head->next==NULL)
	{
		pair1 ans;
		ans.head=head;
		ans.tail=head;
		return ans;
	}
	pair1 smallAns=reverse_LL2(head->next);
	smallAns.tail->next=head;
	head->next=NULL;
	pair1 ans;
	ans.head=smallAns.head;
	ans.tail=head;
	return ans;
	
}

node *reverse_L(node *head)
{
	pair1 ans=reverse_LL2(head);
	return ans.head;
}

//Another O(n) approach for Reversing Linked List
node *reverse_LL3(node *head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	node *smallAns=reverse_LL3(head->next);
	node *tail=head->next;
	tail->next=head;
	head->next=NULL;
	return smallAns;
}

int main()
{
	cout<<"enter your linked list "<<endl;
	node *head=takeInputBetter();
	print(head);
	head=insert(head,0,99);
	print(head);
	head=del(head,0);
	print(head);
	head=insertRecursive(head,2,100);
	print(head);
	head=delRecursive(head,0);
	print(head);
	cout<<length(head)<<endl;
	cout<<mid(head)<<endl;
	cout<<mid1(head)<<endl;
	
	cout<<"enter your linked list "<<endl;
	node*h1=takeInputBetter();
	print(h1);
	cout<<"enter your linked list "<<endl;
	node *h2=takeInputBetter();
	print(h2);
	node *h3=merge(h1,h2);
	cout<<"Linked list after merging "<<endl;
	print(h3);

	head=reverse_LL3(head);
	print(head);
}




