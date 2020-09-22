#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//class for BST same as Binary tree
class binarySearchTreeNode
{
	public:
		int data;
		binarySearchTreeNode* left;
		binarySearchTreeNode* right;
		binarySearchTreeNode(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
		~binarySearchTreeNode()
		{
			delete left;
			delete right;
		}
};

//Take Input Level wise
binarySearchTreeNode* takeInput()
{
	int rootdata;
	cout<<"enter root data "<<endl;
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	binarySearchTreeNode* root=new binarySearchTreeNode(rootdata);
	queue<binarySearchTreeNode*>q;
	q.push(root);
	while(q.size()!=0)
	{
		binarySearchTreeNode* front=q.front();
		q.pop();
		cout<<"enter left child value of "<<front->data<<endl;
		int lchild;
		cin>>lchild;
		if(lchild!=-1)
		{
			binarySearchTreeNode* leftChild=new binarySearchTreeNode(lchild);
			q.push(leftChild);
			front->left=leftChild;
		}
		int rchild;
		cout<<"enter right child value of "<<front->data<<endl;
		cin>>rchild;
		if(rchild!=-1)
		{
			binarySearchTreeNode* rightChild=new binarySearchTreeNode(rchild);
			q.push(rightChild);
			front->right=rightChild;
		}
		
	}
	return root;
}

//Print Level Wise
void print(binarySearchTreeNode* root)
{
	if(root==NULL)
	{
		return ;
	}
	queue<binarySearchTreeNode*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binarySearchTreeNode* front=q.front();
		q.pop();
		cout<<front->data<<": ";
		if(front->left!=NULL)
		{
			cout<<"L "<<front->left->data<<",";
			q.push(front->left);
		}
		if(front->right!=NULL)
		{
			cout<<"R "<<front->right->data;
			q.push(front->right);
		}
		cout<<endl;
	}
}

//Search specific Key in BST
int search(binarySearchTreeNode* root,int key)
{
	int ans=-1;
	if(root==NULL)
	{
		cout<<"Not present "<<endl;
		return -1;
	}
	
	if(root->data==key)
	{
		cout<<"key is present "<<endl;
		return root->data;
	}
	if(root->data<key)
	{
		ans=search(root->right,key);
	}
	if(root->data>key)
	{
		ans=search(root->left,key);
	}
	return ans;
	
}

//Function to print elements in given range
int elementsInRange(binarySearchTreeNode* root,int min,int max)
{
	static int ans=0;
//	int ans=0;
	if(root==NULL)
	{
		return -1 ;
	}
	
	if(root->data>=min && root->data<=max)
	{
		ans++;
		cout<<root->data<<" ";
	}
	if(root->data>min)
	{
		int lhs=elementsInRange(root->left,min,max);
	}
	if(root->data<max)
	{
		int rhs=elementsInRange(root->right,min,max);
	}
	return ans;
}

//Function to find maximum node value in BST
int maximum(binarySearchTreeNode *root)
{
	if(root==NULL)
	{
		return INT_MIN;
	}
	int lmax=maximum(root->left);
	int rmax=maximum(root->right);
	int ans=max(root->data,max(lmax,rmax));
	return ans;
}

//Function to find minimum node value in BST
int minimum(binarySearchTreeNode* root)
{
	if(root==NULL)
	{
		return INT_MAX;
	}
	int lmin=minimum(root->left);
	int rmin=minimum(root->right);
	int ans=min(root->data,min(lmin,rmin));
}


//Function to check whether the given tree is BST or Not 1
bool checkIsBST1(binarySearchTreeNode* root)
{
	if(root==NULL)
	{
		return true;
	}
	int lmax=maximum(root->left);
	int rmin=minimum(root->right);
	bool lBST=checkIsBST1(root->left);
	bool rBST=checkIsBST1(root->right);
	bool ans=(root->data>lmax) && (root->data<rmin) && lBST && rBST;
	return ans; 
}

//Function to check whether the given tree is BST or Not 2
pair<pair<int,int>,bool> checkIsBST2(binarySearchTreeNode* root)
{
	if(root==NULL)
	{
		pair<pair<int,int>,bool> ans;
		ans.first.first=INT_MAX;
		ans.first.second=INT_MIN;
		ans.second=true;
		return ans;
	}
	pair<pair<int,int>,bool> ans=checkIsBST2(root->left);
	pair<pair<int,int>,bool> ans1=checkIsBST2(root->right);
	int mini=min(root->data,min(ans.first.first,ans1.first.first));
	int maxi=max(root->data,max(ans.first.second,ans1.first.second));
	bool answer=(root->data >ans.first.second)&& (root->data<ans1.first.first) && (ans.second) && (ans1.second);
	pair<pair<int,int>,bool> totalAns;
	totalAns.first.first=mini;
	totalAns.first.second=maxi;
	totalAns.second=answer;
	return totalAns;
	
}

//Function to check whether the given tree is BST or Not 3
bool checkIsBST3(binarySearchTreeNode* root,int min=INT_MIN,int max=INT_MAX)
{
	if(root==NULL)
	{
		return true;
	}
	
	if(root->data<min || root->data>max)
	{
		return false;
	}
	bool lBst=checkIsBST3(root->left,min,root->data-1);
	bool rBst=checkIsBST3(root->right,root->data,max);
	bool ans=lBst&&rBst;
	return ans;	
}

//Function to construct BST from sorted array
binarySearchTreeNode* constructBST(int*ar,int si,int ei)
{
	if(si>ei)
	{
		return NULL;
	}
	int mid=(si+ei)/2;
	binarySearchTreeNode* root=new binarySearchTreeNode(ar[mid]);
	binarySearchTreeNode* lchild=constructBST(ar,si,mid-1);
	binarySearchTreeNode* rchild=constructBST(ar,mid+1,ei);
	root->left=lchild;
	root->right=rchild;
	return root;
	
}

//Node class for linked list
class node
{
	public:
		int data;
		node* next;
		node(int d)
		{
			data=d;
			next=NULL;
		}
};

// function to convert BST to Sorted Linked List
node* BST2LL(binarySearchTreeNode* root)
{
	if(root==NULL)
	{
		return NULL;
	}
	node* leftSubTree=BST2LL(root->left);
	node* rightSubTree=BST2LL(root->right);
	node* root1=new node(root->data);
	root1->next=rightSubTree;
	if(leftSubTree==NULL)
	{
		return root1;
	}
	node*temp=leftSubTree;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=root1;
	return leftSubTree;
	 
}

//Function to print Linked list
void printLL(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;	
	}	
}

// Function to print path from root to  given node
vector<int>* getRootToNode(binarySearchTreeNode* root,int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==data)
	{
		vector<int>*op=new vector<int>();
		op->push_back(root->data);
		return op;
	}
	
	vector<int>* leftOp=getRootToNode(root->left,data);
	if(leftOp!=NULL)
	{
		leftOp->push_back(root->data);
		return leftOp;
	}
	vector<int>* rightOp=getRootToNode(root->right,data);
	if(rightOp!=NULL)
	{
		rightOp->push_back(root->data);
		return rightOp;
	}
	else
	{
		return NULL;
	}
}


// class bst for specific order insertion,deletion and searching
class BST{
	
	public:
		binarySearchTreeNode* root;
		BST()
		{
			root=NULL;
		}
		
		~BST()
		{
			delete root;
		}
		private: 
			bool hasData(int data,binarySearchTreeNode*root)
			{
				bool ans;
				if(root==NULL)
				{
					return false;
				}
				
				if(root->data==data)
				{
					return true;
				}
				
				if(root->data>data)
				{
					ans=hasData(data,root->left);
				}
				if(root->data<data)
				{
					ans=hasData(data,root->right);
				}
				return ans;
			}
			
			binarySearchTreeNode* insert(int data,binarySearchTreeNode* node)
				{
					if(node==NULL)
					{
						binarySearchTreeNode* newnode=new binarySearchTreeNode(data);
						return newnode;
					}
					if(node->data>data)
					{
						binarySearchTreeNode* insertLeft=insert(data,node->left);
						node->left=insertLeft;
						
					}
					else
					{
						binarySearchTreeNode* insertRight=insert(data,node->right);
						node->right=insertRight;
					}
					return node;
				}
				
				binarySearchTreeNode* deleteNode(int data,binarySearchTreeNode* node)
				{
					if(node==NULL)
					{
						return NULL;
					}
					
					if(node->data>data)
					{
						binarySearchTreeNode* delLeft=deleteNode(data,node->left);
						node->left=delLeft;
					}
					else if(node->data<data)
					{
						binarySearchTreeNode* delRight=deleteNode(data,node->right);
						node->right=delRight;
					}
					else
					{
						if(node->left==NULL && node->right==NULL)
						{
							delete node;
							return NULL;
						}
						if(node->left==NULL)
						{
							binarySearchTreeNode* temp=node->right;
							node->right=NULL;
							delete node;
							return temp;							
						}
						if(node->right==NULL)
						{
							binarySearchTreeNode* temp=node->right;
							node->right=NULL;
							delete node;
							return temp;
						}
						else
						{
							binarySearchTreeNode* minNode=node->right;
							while(minNode->left!=NULL)
							{
								minNode=minNode->left;
							}
							int min=minNode->data;
							node->data=min;
							node->right=deleteNode(data,node->right);
						}
					}
					return node;		
				}
				void printTree(binarySearchTreeNode* root)
				{
					if(root==NULL)
					{
						return ;
					}
					queue<binarySearchTreeNode*> q;
					q.push(root);
					while(q.size()!=0)
					{
						binarySearchTreeNode* front=q.front();
						q.pop();
						cout<<front->data<<": ";
						if(front->left!=NULL)
						{
							cout<<"L "<<front->left->data<<",";
							q.push(front->left);
						}
						if(front->right!=NULL)
						{
							cout<<"R "<<front->right->data;
							q.push(front->right);
						}
						cout<<endl;
					}
				}
		public:
			bool hasData(int data)
			{
				return hasData(data,root);
			}
			
			void insert(int data)
			{
				root=insert(data,root);
			}
			
			void deleteNode(int data)
			{
				root=deleteNode(data,root);
			}
			
			void printTree()
			{
				printTree(root);
			}
			
};
//input: 50 30 70 10 40 60 80 5 20 -1 45 -1 65 75 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
//	binarySearchTreeNode* root=takeInput();
//	print(root);
//	cout<<endl;
//	cout<<"search : "<<search(root,65)<<endl;
//	int min;
//	cout<<"enter min value "<<endl;
//	cin>>min;
//	int max;
//	cout<<"enter max value "<<endl;
//	cin>>max;
//	cout<<endl;
//	cout<<endl<<"total elements in this range are : "<<elementsInRange(root,min,max)<<endl;
//	cout<<"min value "<<minimum(root)<<endl;
//	cout<<"maximum value "<<maximum(root)<<endl;
//	cout<<checkIsBST1(root)<<endl;
//	pair<pair<int,int>,bool> ans=checkIsBST2(root);
//	cout<<ans.second<<endl;
//	bool ans1=checkIsBST3(root);
//	cout<<ans1<<endl;
//	int ar[]={1,2,3,4,5,6,7,8};
//	int si=0;
//	int size=sizeof(ar)/sizeof(ar[0]);
//	int ei=size-1;
//	binarySearchTreeNode* root=constructBST(ar,si,ei);
//	print(root);
//	node* head=BST2LL(root);
//	printLL(head);
//	cout<<endl<<endl;
//	vector<int>* op=getRootToNode(root,65);
//	if(op==NULL)
//	{
//		cout<<"No element present "<<endl;
//	}
//	else
//	{
//		for(int i=0;i<op->size();i++)
//		{
//			cout<<op->at(i)<<endl;
//		}
//	}
	BST b;
	b.insert(10);
	b.insert(20);
	b.insert(15);
	b.insert(5);
	b.insert(7);
	b.insert(3);
	b.insert(17);
	b.printTree();
	b.deleteNode(10);
	cout<<endl<<endl;
	b.printTree();
	cout<<endl<<endl;
	cout<<b.hasData(17);
	
//	delete op;
//	delete root;
}

