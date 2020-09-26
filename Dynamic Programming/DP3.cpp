#include<iostream>
using namespace std;

int editDist(string s,string t)
{
	if(s.size()==0)
	{
		return t.size();
	}
	if(t.size()==0)
	{
		return s.size();
	}
	
	if(s[0]==t[0])
	{
		return editDist(s.substr(1),t.substr(1));
	}
	
	int x=editDist(s.substr(1),t)+1;
	int y=editDist(s,t.substr(1))+1;
	int z=editDist(s.substr(1),t.substr(1))+1;
	return min(x,min(y,z));
}

int editDist_better(string s,string t,int **ar)
{
	if(s.size()==0)
	{
		return t.size();
	}
	if(t.size()==0)
	{
		return s.size();
	}
	int m=s.size();
	int n=t.size();
	
	if(ar[m][n]!=-1)
	{
		return ar[m][n];
	}
	
	if(s[0]==t[0])
	{
		ar[m][n]=editDist_better(s.substr(1),t.substr(1),ar);
	}
	
	else
	{
		ar[m-1][n]=editDist_better(s.substr(1),t,ar);
		ar[m][n-1]=editDist_better(s,t.substr(1),ar);
		ar[m-1][n-1]=editDist_better(s.substr(1),t.substr(1),ar);
		
		ar[m][n]=min(ar[m-1][n],min(ar[m][n-1],ar[m-1][n-1]))+1;
	}
	return ar[m][n];
}
int editDist_better(string s,string t)
{
	int m=s.size();
	int n=t.size();
	int **ar=new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		ar[i]=new int[n+1];
		for(int j=0;j<=n;j++)
		{
			ar[i][j]=-1;
		}
	}
	return editDist_better(s,t,ar);
}

int editDistDp(string s,string t)
{
	int m=s.size();
	int n=t.size();
	int **ar=new int *[m+1];
	
	for(int i=0;i<=m;i++)
	{
		ar[i]=new int[n+1];
	}
	
	for(int j=0;j<=n;j++)
	{
		ar[0][j]=j;
	}
	
	for(int i=0;i<=m;i++)
	{
		ar[i][0]=i;
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[m-i]==t[n-j])
			{
				ar[i][j]=ar[i-1][j-1];
			}
			else
			{
				ar[i][j]=min(ar[i-1][j],min(ar[i-1][j-1],ar[i][j-1]))+1;
			}
		}
	}
	return ar[m][n];
}
int main()
{
	string s;
	string t;
	cin>>s>>t;
	cout<<editDist(s,t)<<endl;
	cout<<editDist_better(s,t)<<endl;
	cout<<editDistDp(s,t)<<endl;
}
