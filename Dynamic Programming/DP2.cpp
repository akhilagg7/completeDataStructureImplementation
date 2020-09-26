#include<iostream>
using namespace std;

int minCost(int m,int n,int **ar,int i,int j)
{
	//base case
	if(i==m-1 && j==n-1)
	{
		return ar[i][j];
	}
	
	//check if we are going out of limit
	if(i>m-1 || j>n-1)
	{
		return INT_MAX;
	}
	//recursive call
	int x=minCost(m,n,ar,i,j+1);
	int y=minCost(m,n,ar,i+1,j+1);
	int z=minCost(m,n,ar,i+1,j);
	
	int ans=min(x,min(y,z))+ ar[i][j];
	return ans;
}
int minCost(int m,int n,int **ar)
{
	return minCost(m,n,ar,0,0);
}

int minCost_better(int m,int n,int **ar,int i,int j,int **ans)
{
	if(i==m-1 && j==n-1)
	{
//		ans[i][j]=ar[i][j];
		return ar[i][j];
	}
	
	if(i>m-1 || j>n-1)
	{
		return INT_MAX;
	}
	
	if(ans[i][j]!=-1)
	{
		return ans[i][j];
	}
	
	int x=minCost_better(m,n,ar,i,j+1,ans);
	if(x<INT_MAX)
	{
		ans[i][j+1]=x;
	}
	int y=minCost_better(m,n,ar,i+1,j+1,ans);
	if(y<INT_MAX)
	{
		ans[i+1][j+1]=y;
	}
	int z=minCost_better(m,n,ar,i+1,j,ans);
	if(z<INT_MAX)
	{
		ans[i+1][j]=z;
	}
	ans[i][j]=min(x,min(y,z))+ar[i][j];
	return ans[i][j];
}

int minCost_better(int m,int n,int **ar)
{
	int **ans=new int*[m];
	for(int i=0;i<m;i++)
	{
		ans[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			ans[i][j]=-1;
		}
	}
	return minCost_better(m,n,ar,0,0,ans);
}

int minCostDp(int m,int n,int **ar)
{
	int **ans=new int*[m];
	for(int i=0;i<m;i++)
	{
		ans[i]=new int[n];
	}
	
	ans[m-1][n-1]=ar[m-1][n-1];
	for(int j=n-2;j>=0;j--)
	{
		ans[m-1][j]=ar[m-1][j]+ans[m-1][j+1];
	}
	
	for(int i=m-2;i>=0;i--)
	{
		ans[i][n-1]=ar[i][n-1]+ans[i+1][n-1];
	}
	
	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			ans[i][j]=ar[i][j]+min(ans[i][j+1],min(ans[i+1][j+1],ans[i][j+1]));
		}
	}
	return ans[0][0];
}

int lcs(string s,string t)
{
	if(s.size()==0|| t.size()==0)
	{
		return 0;
	}
	if(s[0]==t[0])
	{
		return 1+lcs(s.substr(1),t.substr(1));
	}
	else
	{
		int a=lcs(s,t.substr(1));
		int b=lcs(s.substr(1),t);
		int c=lcs(s.substr(1),t.substr(1));
		return max(a,max(b,c));
	}
}

int lcs_better(string s,string t,int **ar)
{
	if(s.size()==0||t.size()==0)
	{
		return 0;
	}
	
	int m=s.size();
	int n=t.size();
	
	if(ar[m][n]!=-1)
	{
		return ar[m][n];
	}
	
	if(s[0]==t[0])
	{
		ar[m-1][n-1]=lcs_better(s.substr(1),t.substr(1),ar);
		ar[m][n]=1+ar[m-1][n-1];
	}
	else
	{
		ar[m][n-1]=lcs_better(s,t.substr(1),ar);
		ar[m-1][n]=lcs_better(s.substr(1),t,ar);
		ar[m][n]=max(ar[m-1][n],ar[m][n-1]);
	}
	return ar[m][n];
}
int lcs_better(string s,string t)
{
	int m=s.size();
	int n=t.size();
	int **ar=new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		ar[i]=new int[n+1];
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			ar[i][j]=-1;
		}
	}
	return lcs_better(s,t,ar);
}

int lcsDp(string s,string t)
{
	int m=s.size();
	int n=t.size();
	int **ar=new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		ar[i]=new int[n+1];
	}
	for(int j=0;j<=n;j++)
	{
		ar[0][j]=0;
	}
	
	for(int i=0;i<=m;i++)
	{
		ar[i][0]=0;
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[m-i]==t[n-j])
			{
				ar[i][j]=1+ar[i-1][j-1];
			}
			else
			{
				ar[i][j]=max(ar[i-1][j],ar[i][j-1]);
			}
			
		}
	}
	return ar[m][n];
	
}
int main()
{
	int m,n;
	cin>>m>>n;
	int **ar=new int*[m];
	for(int i=0;i<m;i++)
	{
		ar[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>ar[i][j];
		}
	}
	cout<<minCost(m,n,ar)<<endl;
	cout<<minCost_better(m,n,ar)<<endl;
	cout<<minCostDp(m,n,ar)<<endl;
	string s,t;
	cin>>s>>t;
	
	cout<<lcs_better(s,t)<<endl;
	cout<<lcs(s,t)<<endl;
	cout<<lcsDp(s,t)<<endl;
}
