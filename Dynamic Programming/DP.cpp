#include<iostream>
#include<math.h>
using namespace std;

int fibDP(int n)
{
	int *ar=new int [n+1];
	ar[0]=0;
	ar[1]=1;
	for(int i=2;i<=n;i++)
	{
		ar[i]=ar[i-1]+ar[i-2];
	}
	return ar[n];
}
int fibo_better(int n,int *ar)
{
	if(n<=1)
	{
		ar[n]=n;
		return n;
	}
	if(ar[n-1]==0)
	{
		ar[n-1]=fibo_better(n-1,ar);
		
	}
	if(ar[n-2]==0)
	{
		ar[n-2]=fibo_better(n-2,ar);
	}
	int ans=ar[n-1]+ar[n-2];
	return ans;
}
int fibo_better(int n)
{
	int *ar=new int[n+1];
	for(int i=0;i<n;i++)
	{
		ar[i]=0;
	}
	return fibo_better(n,ar);
}
int fib(int n)
{
	if(n<=1)
	{
		return n;
	}
	int ans1=fib(n-1);
	int ans2=fib(n-2);
	int ans=ans1+ans2;
	return ans;
}
int minSteps(int n)
{
	int x=INT_MAX,y=INT_MAX,z=INT_MAX;
	if(n==1)
	{
		return 0;
	}
	x=minSteps(n-1);
	if(n%2==0)
	{
		y=minSteps(n/2);
	}
	if(n%3==0)
	{
		z=minSteps(n/3);	
	}
	return min(x,min(y,z))+1;
	
	
}
int minSteps_better(int n,int *ar)
{
	if(n==1)
	{
		ar[n]=0;
		return 0;
	}
	if(ar[n-1]==-1)
	{
		ar[n-1]=minSteps_better(n-1,ar);
	}
	int y=INT_MAX,z=INT_MAX;
	if(n%2==0)
	{
		if(ar[n/2]==0)
			ar[n/2]=minSteps_better(n/2,ar);
		y=ar[n/2];
	}
	if(n%3==0)
	{
		if(ar[n/3]==-1)
			ar[n/3]=minSteps_better(n/3,ar);
		z=ar[n/3];
	}
	ar[n]=min(ar[n-1],min(y,z))+1;
	return ar[n];
}
int minSteps_better(int n)
{
	int *ar=new int[n+1];
	for(int i=0;i<n;i++)
	{
		ar[i]=-1;
	}
	return minSteps_better(n,ar);
}

int minDP(int n)
{
	int *ar=new int[n+1];
	ar[1]=0;
	ar[2]=1;
	ar[3]=1;
	for(int i=4;i<=n;i++)
	{
		if(i%2==0 && i%3==0)
		{
			ar[i]=min(ar[i-1],min(ar[i/2],ar[i/3]))+1;
		}
		else if(i%2==0)
		{
			ar[i]=min(ar[i-1],ar[i/2])+1;
			
		}
		else if(i%3==0)
		{
			ar[i]=min(ar[i-1],ar[i/3])+1;
		}
		else
		{
			ar[i]=ar[i-1]+1;
		}
	}
	return ar[n];
}

int minCount(int n)
{
	if(n==0||n==1||n==2||n==3)
	{
		return n;
	}
	int ans=INT_MAX;
	int i=1;
	while(i*i<=n)
	{
		int x=minCount(n-(i*i));
		ans=min(x,ans);
		i++;
	}
	return ans+1;
	
}
int minCount_better(int n,int* ar)
{
	if(n==0,n==1,n==2,n==3)
	{
		ar[n]=n;
		return n;
	}
	int ans=INT_MAX;
	int i=1;
	while(i*i<=n)
	{
		if(ar[n]==-1)
		{
			ar[n]=minCount_better(n-(i*i),ar);
		}
		ans=min(ar[n],ans);
		i++;
	}
	return ans;
}	
int minCount_better(int n)
{
	int *ar=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		ar[i]=-1;
	}
	return minCount_better(n,ar);
}	

int balancedBT(int n)
{
	if(n<=1)
	{
		return 1;
	}
	int mod=(int)(pow(10,9))+7;
	
	int x=balancedBT(n-1);
	int y=balancedBT(n-2);
	
	int temp1=(int)(((long)(x)*x)%mod);
	int temp2=(int)((2*(long)(x)*y)%mod);
	
	int ans=(temp1+temp2)%mod;
	
	return ans;
	
}	

int balancedBT_better(int n,int *ar)
{
	if(n<=1)
	{
		ar[n]=1;
		return 1;
	}
	int mod=(int)(pow(10,9))+7;
	
	if(ar[n-1]==-1)
	{
		ar[n-1]=balancedBT_better(n-1,ar);
	}
	
	if(ar[n-2]==-1)
	{
		ar[n-2]=balancedBT_better(n-2,ar);
	}
	
	int temp1=int(((long)(ar[n-1])*ar[n-1])%mod);
	int temp2=int(2*(long)(ar[n-2])*ar[n-1]%mod);
	ar[n]=(temp1+temp2)%mod;
	return ar[n];
}
int balancedBT_better(int n)
{
	int *ar=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		ar[i]=-1;	
	}
	return balancedBT_better(n,ar);
}

int balancedBtDp(int n)
{
	int *ar=new int[n+1];
	ar[0]=1;
	ar[1]=1;
	int mod=(int)(pow(10,9))+7;

	for(int i=2;i<=n;i++)
	{
		ar[i]=(int)((((long)(ar[i-1])*ar[i-1])%mod)+((long)(ar[i-1])*ar[i-2]*2%mod))%mod;
	}
	return ar[n];
}
int main()
{
	int n;
	cin>>n;
	int ans=fibo_better(n);
	cout<<ans<<endl;
	cout<<fibDP(n)<<endl;
	cout<<fib(n)<<endl;
	cout<<minSteps(n)<<endl;
	cout<<minSteps_better(n)<<endl;
	cout<<minDP(n)<<endl;
	cout<<minCount(n)<<endl;
	cout<<minCount_better(n)<<endl;
	cout<<balancedBT(n)<<endl;
	cout<<balancedBT_better(n)<<endl;
	cout<<balancedBtDp(n)<<endl;
}
