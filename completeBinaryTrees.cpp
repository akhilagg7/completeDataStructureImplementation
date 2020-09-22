#include<iostream>
#include<queue>
using namespace std;

class binaryTreeNode{
	public:
		int data;
		binaryTreeNode* left;
		binaryTreeNode* right;
		
		binaryTreeNode(int data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
		
		~binaryTreeNode()
		{
			delete left;
			delete right;
		}
};

// Take Input recursive
binaryTreeNode* takeInput()
{
	int data;
	cout<<"enter data "<<endl;
	cin>>data;
	if(data==-1)
	{
		return NULL;
	}
	binaryTreeNode*root=new binaryTreeNode(data);
	cout<<"enter left child of "<<root->data<<endl;
	binaryTreeNode*lchild=takeInput();
	cout<<"enter right child of "<<root->data<<endl;
	binaryTreeNode* rchild=takeInput();
	root->left=lchild;
	root->right=rchild;
	return root;
}

// Print Recursive
void print(binaryTreeNode* root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->data<<": ";
	if(root->left!=NULL)
	{
		cout<<"L "<<root->left->data<<",";
	}
	if(root->right!=NULL)
	{
		cout<<"R "<<root->right->data<<",";
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}

// Function to takeInput Level Wise
binaryTreeNode* takeInputLevelWise()
{
	int rootdata;
	cout<<"enter root data "<<endl;
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	binaryTreeNode*root=new binaryTreeNode(rootdata);
	queue<binaryTreeNode*>q;
	q.push(root);
	while(q.size()!=0)
	{
		binaryTreeNode*front=q.front();
		q.pop();
		cout<<"enter leftchild of "<<front->data<<endl;
		int lchildval;
		cin>>lchildval;
		if(lchildval!=-1)
		{
			binaryTreeNode* lchild=new binaryTreeNode(lchildval);
			q.push(lchild);
			front->left=lchild;
		}
		cout<<"enter rightchild of "<<front->data<<endl;
		int rchildval;
		cin>>rchildval;
		if(rchildval!=-1)
		{
			binaryTreeNode* rchild=new binaryTreeNode(rchildval);
			q.push(rchild);
			front->right=rchild;
		}
	}
	return root;
}

//Function to print level wise
void printLevelWise(binaryTreeNode* root)
{
	queue<binaryTreeNode*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binaryTreeNode* front=q.front();
		q.pop();
		cout<<front->data<<": ";
		if(front->left!=NULL)
		{
			cout<<"L "<<front->left->data<<",";
			q.push(front->left);
		}
		if(front->right!=NULL)
		{
			cout<<"R "<<front->right->data<<",";
			q.push(front->right);
		}
		cout<<endl;
	
	}
}

// Find height of a tree 
int height(binaryTreeNode *root)
{
	if(root==NULL)
	{
		return -1;
	}
	int lheight=height(root->left);
	int rheight=height(root->right);
	int ans=max(lheight,rheight);
	return ans+1;
}

//total nodes in tree
int nodes(binaryTreeNode *root)
{
	int ans=0;
	if(root==NULL)
	{
		return 0;
	}
	ans+=nodes(root->left);
	ans+=nodes(root->right);
	return ans+1;
}

//preorder traversal 
void preorder(binaryTreeNode *root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

//inorder traversal
void inorder(binaryTreeNode *root)
{
	if(root==NULL)
	{
		return ;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

//postorder traversal
void postorder(binaryTreeNode *root)
{
	if(root==NULL)
	{
		return ;
	}
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

//Helper function to Build tree from inorder and preorder
binaryTreeNode* buildTreeHelper(int*pr, int*in,int pres,int pree,int ins,int ine)
{
	if(ins>ine)
	{
		return NULL;
	}
	int rootData=pr[pres];
	int rootIndex=-1;
	for(int i=ins;i<=ine;i++)
	{
		if(rootData==in[i])
		{
			rootIndex=i;
			break;
		}
	}
	int lins=ins;
	int line=rootIndex-1;
	int rins=rootIndex+1;
	int rine=ine;
	int lprs=pres+1;
	int lpre=line-lins+lprs;
	int rprs=lpre+1;
	int rpre=pree;
	binaryTreeNode* root=new binaryTreeNode(rootData);
	binaryTreeNode* lchild=buildTreeHelper(pr,in,lprs,lpre,lins,line);
	binaryTreeNode* rchild=buildTreeHelper(pr,in,rprs,rpre,rins,rine);
	root->left=lchild;
	root->right=rchild;
	return root;
}

//Build tree from inorder and preorder
binaryTreeNode* buildTree(int pr[],int in[],int size)
{
	return buildTreeHelper(pr,in,0,size-1,0,size-1);
}


//Function to find dimaeter of tree in O(N*H) where H is height of tree
int diameter(binaryTreeNode* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lheight=height(root->left);
	int rheight=height(root->right);
	int option1=1+lheight+rheight;
	int option2=diameter(root->left);
	int option3=diameter(root->right);
	int ans=max(option1,max(option2,option3));
	return ans+1;
}

class pair1{
	public:
	int diamater;
	int height;
};

// function to find dimater of tree in O(h) where h is height of tree
pair1 heightDiam(binaryTreeNode* root)
{
	if(root==NULL)
	{
		pair1 ans;
		ans.diamater=0;
		ans.height=0;
		return ans;
	}
	pair1 lpair=heightDiam(root->left);
	pair1 rpair=heightDiam(root->right);
	int lh=lpair.height;
	int rh=rpair.height;
	int ld=lpair.diamater;
	int rd=rpair.diamater;
	int height=1+max(lh,rh);
	int diam=max(lh+rh,max(ld,rd));
	pair1 ans;
	ans.diamater=diam;
	ans.height=height;
	return ans;
}

//TreeInput: 10 20 30 40 50 60 70 -1 -1 80 90 -1 100 -1 -1 110 -1 -1 -1 -1 -1 -1 -1
// inorder:  40 20 110 80 50 90 10 60 100 30 70
//preorder:  10 20 40 50 80 110 90 30 60 100 70
//postorder: 40 110 80 90 50 20 100 60 70 30 10
int main()
{
	binaryTreeNode*root=takeInputLevelWise();
	printLevelWise(root);
	cout<<"Height of binary tree edges : "<<height(root)<<endl;
	cout<<"Total Nodes in binary tree : "<<nodes(root)<<endl;
	cout<<"Preorder : ";
	preorder(root);
	cout<<endl<<"Inorder : ";
	inorder(root);
	cout<<endl<<"Postorder : ";
	postorder(root);
	cout<<endl;
	int in[]={40, 20, 110, 80, 50, 90, 10, 60, 100, 30, 70};
	int pre[]={10, 20, 40, 50, 80, 110, 90, 30, 60, 100, 70};
	int n=sizeof(pre)/sizeof(pre[0]);
	cout<<n<<endl;
	binaryTreeNode*root1=buildTree(pre,in,n);
	printLevelWise(root1);
	cout<<endl;
	cout<<"diameter: "<<diameter(root)<<endl;
	pair1 ans=heightDiam(root);
	cout<<"diameter: "<<ans.diamater<<endl;
	cout<<"height: "<<ans.height<<endl;
}
