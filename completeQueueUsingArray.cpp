//implemented by: Akhil Aggarwal
//contact : akhilagg123@gmail.com

#include<iostream>
using namespace std;

class queue
{
	int *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;
	
	public:
		queue(int totalElement)
		{
			data=new int[totalElement];
			nextIndex=0;
			firstIndex=-1;
			size=0;
			capacity=totalElement;
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
//			if(size==capacity)
//			{
//				cout<<"queue is full "<<endl;
//				return ;
//			}
			if(size==capacity)
			{
				int *newdata=new int[2*capacity];
				int j=0;
				for(int i=firstIndex;i<capacity;i++)
				{
					newdata[j]=data[i];
					j++;
				}
				for(int i=0;i<firstIndex;i++)
				{
					newdata[j]=data[i];
					j++;
				}
				delete [] data;
				data=newdata;
				firstIndex=0;
				nextIndex=capacity;
				capacity=2*capacity;
			}
			
			data[nextIndex]=element;
			nextIndex++;
			nextIndex=nextIndex%capacity;
			if(firstIndex==-1)
			{
				firstIndex=0;
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
			return data[firstIndex];
		}
		
		int pop()
		{
			if(size==0)
			{
				cout<<"queue is empty "<<endl;
				return 0;
			}
			int ans=data[firstIndex];
			firstIndex++;
			firstIndex%=capacity;
			size--;
			return ans;
		}
};
int main()
{
	queue q(5);
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
