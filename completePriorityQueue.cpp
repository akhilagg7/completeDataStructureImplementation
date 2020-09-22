#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class priorityQueue
{
	vector<int>pq;
	public:
		priorityQueue()
		{
			
		}
		
		//function to check if min priority queue is empty
		bool isEmpty()
		{
			return (pq.size()==0);
		}
		
		//function to get size of min priority queue
		int getSize()
		{
			return pq.size();
		}
		
		//function to get min value of min priority queue
		int getMin()
		{
			if(pq.size()==0)
			{
				return -1;
			}
			return pq[0];
		}
		
		//function to insert value in min priority queue
		void insert(int element)
		{
			pq.push_back(element);
			int childIndex=pq.size()-1;
			while(childIndex>0)
			{
				int parentIndex=(childIndex-1)/2;
				if(pq[childIndex]<pq[parentIndex])
				{
					int temp=pq[childIndex];
					pq[childIndex]=pq[parentIndex];
					pq[parentIndex]=temp;
				}
				else
				{
					break;
				}
				childIndex=parentIndex;
			}
		}
		
		//function to delete min value from min priority queue
		int removeMin()
		{
			int ans=pq[0];
			pq[0]=pq[pq.size()-1];
			pq.pop_back();
			int parentIndex=0;
			int lchildIndex=2*parentIndex+1;
			int rchildIndex=2*parentIndex+2;
			int minIndex=parentIndex;
			while(lchildIndex<pq.size())
			{
				if(pq[minIndex]>pq[lchildIndex])
				{
					minIndex=lchildIndex;
				}
				if(rchildIndex<pq.size() && pq[minIndex]>pq[rchildIndex])
				{
					minIndex=rchildIndex;
				}
				if(parentIndex==minIndex)
				{
					break;
				}
				int temp=pq[parentIndex];
				pq[parentIndex]=pq[minIndex];
				pq[minIndex]=temp;
				
				parentIndex=minIndex;
				lchildIndex=2*parentIndex+1;
				rchildIndex=2*parentIndex+2;
			}
			return ans;			
		}
		
		
};


void inplaceHeap(int *ar,int size)
{
	for(int i=1;i<size;i++)
	{
		int childIndex=i;
		while(childIndex>0)
		{
			int parentIndex=(childIndex-1)/2;
			if(ar[childIndex]<ar[parentIndex])
			{
				int temp=ar[childIndex];
				ar[childIndex]=ar[parentIndex];
				ar[parentIndex]=temp;
			}
			else
			{
				break;
				
			}
			childIndex=parentIndex;			
		}		
	}
	
//	int size=n;
	while(size>1)
	{
		int temp=ar[0];
		ar[0]=ar[size-1];
		ar[size-1]=temp;
		size--;
		
		int parentIndex=0;
		int lchildIndex=2*parentIndex+1;
		int rchildIndex=2*parentIndex+2;
		int minIndex=0;
		while(lchildIndex<size)
		{
			if(ar[minIndex]>ar[lchildIndex])
			{
				minIndex=lchildIndex;
			}
			if(rchildIndex<size && ar[minIndex]>ar[rchildIndex])
			{
				minIndex=rchildIndex;
			}
			if(minIndex==parentIndex)
			{
				break;
			}
			int ans=ar[parentIndex];
			ar[parentIndex]=ar[minIndex];
			ar[minIndex]=ans;
			
			parentIndex=minIndex;
			lchildIndex=2*parentIndex+1;
			rchildIndex=2*parentIndex+2;
		}	
	}
	
}

//questions solved through inbuilt prioirty_queue

void kSorted(int ar[],int n,int k)
{
	priority_queue<int> pq;
	for(int i=0;i<k;i++)
	{
		pq.push(ar[i]);
	}
	int j=0;
	for(int i=k;i<n;i++)
	{
		ar[j]=pq.top();
		pq.pop();
		j++;
		pq.push(ar[i]);
	}
	while(pq.size()!=0)
	{
		ar[j]=pq.top();
		pq.pop();
		j++;
	}
}

void kSmallest(int ar[],int n,int k)
{
	priority_queue<int>pq;
	for(int i=0;i<k;i++)
	{
		pq.push(ar[i]);
	}
	for(int i=k;i<n;i++)
	{
		int ans=pq.top();
		if(ans>ar[i])
		{
			pq.pop();
			pq.push(ar[i]);
		}
	}
	while(pq.size()!=0)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

void kLargest(int ar[],int n,int k)
{
	priority_queue<int>pq;
	for(int i=0;i<n;i++)
	{
		pq.push(ar[i]);
	}
	int j=0;
	while(j<k-1)
	{
		pq.pop();
		j++;
	}
	cout<<pq.top()<<endl;
}

void kLargest1(int ar[],int n,int k)
{
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<k;i++)
	{
		pq.push(ar[i]);
		
	}
	for(int i=k;i<n;i++)
	{
		int ans=pq.top();
		if(ans<ar[i])
		{
			pq.pop();
			pq.push(ar[i]);
		}
	}
	cout<<pq.top()<<endl;
}
int main()
{
	priorityQueue pq;
	pq.insert(12);
	pq.insert(6);
	pq.insert(5);
	pq.insert(100);
	pq.insert(1);
	pq.insert(9);
	pq.insert(0);
	pq.insert(14);
	cout<<pq.getMin()<<endl;
	cout<<pq.getSize()<<endl;
	cout<<pq.isEmpty()<<endl;
	while(pq.getSize()!=0)
	{
		cout<<pq.removeMin()<<" ";
	}
	cout<<endl<<endl;
	cout<<"Sorting using Inplace heap : ";
	int ar[]={3,5,7,1,2,6,4,8,9,0};
	int n=sizeof(ar)/sizeof(ar[0]);
	inplaceHeap(ar,n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;	
	int ar1[]={10,12,5,7,9};
	int n1=5;
	int k=3;
	kSorted(ar1,n1,k);
	cout<<"K sorted array : ";
	for(int i=0;i<n1;i++)
	{
		cout<<ar1[i]<<" ";
	}
	cout<<endl;
	cout<<"K smallest elements: ";
	kSmallest(ar1,n1,3);
	cout<<endl;
	cout<<"Kth Largest element : ";
	kLargest(ar1,n1,2);
	cout<<endl;
	cout<<"Kth Largest element : ";
	kLargest1(ar1,n1,2);
}
