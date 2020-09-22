//implemented by: Akhil Aggarwal
//contact : akhilagg123@gmail.com

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class treenode
{
	public:
		int data;
		vector<treenode*> children;
		treenode(int data)
		{
			this->data=data;
		}
		~treenode()
		{
			for(int i=0;i<this->children.size();i++)
			{
				delete children[i];
			}
		}
};


//function to take input 
treenode* takeInput()
{
	int rootdata;
	cout<<"enter root data "<<endl;
	cin>>rootdata;
	treenode *root=new treenode(rootdata);
	int n;
	cout<<"enter no. of children of "<<root->data<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		treenode *child=takeInput();
		root->children.push_back(child);
	}
	return root;
}

//function to take input level wise
treenode * takeInputLevelWise()
{
	int rootdata;
	cout<<"enter root data "<<endl;
	cin>>rootdata;
	treenode *root=new treenode(rootdata);
	queue<treenode *>q;
	q.push(root);
	while(q.size()!=0)
	{
		treenode* front=q.front();
		q.pop();
		cout<<"enter no. of children of "<<front->data<<endl;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"enter value of "<<i<<"th child of "<<front->data<<endl;
			int val;
			cin>>val;
			treenode *child=new treenode(val);
			q.push(child);
			front->children.push_back(child);
		}
	}
	return root;
}

//function to print
void print(treenode *root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		print(root->children[i]);
	}
}

//function to print levelwise
void printLevelWise(treenode *root)
{
	if(root==NULL)
	{
		return ;
	}
	queue<treenode*> q;
	q.push(root);
	while(q.size()!=0)
	{
		treenode *front=q.front();
		q.pop();
		cout<<front->data<<": ";
		for(int i=0;i<front->children.size();i++)
		{
			q.push(front->children[i]);
			cout<<front->children[i]->data<<",";
		}
		cout<<endl;
	}
}

//function to count no. of nodes
int count(treenode* root)
{
	int ans=0;
	if(root==NULL)
	{
		return 0;
	}
	for(int i=0;i<root->children.size();i++)
	{
		cout<<"ans called for "<<root->children[i]->data<<" "<<ans<<endl;
		ans+=count(root->children[i]);
		cout<<"ans called for "<<root->children[i]->data<<" "<<ans<<endl;
	
	}
	return ans+1;

}

//function to find nodes at depth k
void depth(treenode* root,int k)
{
	if(root==NULL)
	{
		return ;
	}
	if(k==0)
	{
		cout<<root->data<<" ";
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		depth(root->children[i],k-1);
	}
	
}

//function to count leafnodes
int leafnode(treenode *root)
{
	int ans=0;
	if(root==NULL)
	{
		return 0;
	}
	if(root->children.size()==0)
	{
		cout<<"leaf node: "<<root->data<<" ";
		return 1;
	}
	for(int i=0;i<root->children.size();i++)
	{
		ans+=leafnode(root->children[i]);
	}
	return ans;
}

//program to find height of a tree
int height(treenode* root)
{
	int ans=0;
	if(root==NULL)
	{
		return 0;
	}
	for(int i=0;i<root->children.size();i++)
	{
		int max1=height(root->children[i]);
		ans=max(ans,max1);
	}
	ans+=1;
	return ans;
}
//preorder traversal
void preorder(treenode* root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++)
	{
		preorder(root->children[i]);
	}
}

//postorder traversal
void postorder(treenode* root)
{
	if(root==NULL)
	{
		return ;
	}
	for(int i=0;i<root->children.size();i++)
	{
		postorder(root->children[i]);
	}
	cout<<root->data<<" ";;
}

// 10 3 20 30 40 2 50 60 2 70 80 1 90 1 100 0 0 0 0 0
int main()
{
	treenode *root=takeInputLevelWise();
	printLevelWise(root);
	cout<<count(root)<<endl;
	depth(root,2);
	cout<<endl;	
	cout<<"total leaf node = "<<leafnode(root)<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	cout<<height(root)<<endl;
	delete root;
}
