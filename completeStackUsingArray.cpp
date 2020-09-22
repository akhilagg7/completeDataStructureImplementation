#include<iostream>
using namespace std;

template <typename T>
class stackUsingArray
{
	T *data;
	int nextIndex;
	int capacity;
	
	public:
		
		//stack of fixed size
//		stackUsingArray(int totalElement)
//		{
//			data=new int[totalElement];
//			nextIndex=0;
//			capacity=totalElement;
//		}
		
		//stack of unlimited size
		stackUsingArray()
		{
			data=new T[4];
			nextIndex=0;
			capacity=4;
		}
		
		//to check size of stack
		int getSize()
		{
			return nextIndex;
		}
		
		//to check whether stack is empty or not
		bool isEmpty()
		{
			return nextIndex==0;
		}
		
		//to insert elements in stack
//		void push(T element)
//		{
//			if(nextIndex==capacity)
//			{
//				cout<<"stack full "<<endl;
//				return ;
//			}
//			data[nextIndex]=element;
//			nextIndex++;
//		}

		//to insert element in unlimited size stack
		void push(T element)
		{
			if(nextIndex==capacity)
			{
				T *newdata=new T[2*capacity];
				for(int i=0;i<capacity;i++)
				{
					newdata[i]=data[i];
				}
				capacity*=2;
				delete [] data;
				data=newdata;
			}
			data[nextIndex]=element;
			nextIndex++;
		}
		
		//to get topmost element in stack
		T top()
		{
			if(nextIndex==0)
			{
				cout<<"stack empty "<<endl;
				return 0;
			}
			return data[nextIndex-1];
		}
		
		//to pop topmost element in stack
		T pop()
		{
			if(nextIndex==0)
			{
				cout<<"stack empty "<<endl;
				return 0;
			}
			nextIndex--;
			return data[nextIndex];			
		}
};

int main()
{
//	stackUsingArray<int> s(4);
	stackUsingArray<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.top()<<endl;
	cout<<s.getSize()<<endl;
	cout<<s.isEmpty()<<endl;
	
	cout<<endl;
	stackUsingArray<char>s1;
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s1.push('d');
	s1.push('e');
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.top()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.top()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.top()<<endl;
	cout<<s1.getSize()<<endl;
	cout<<s1.isEmpty()<<endl;
	
}
