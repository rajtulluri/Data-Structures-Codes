#include<iostream>
using namespace std;
#define MAX 100
class Stack
{
	int A[MAX];
	int top[MAX],boundary[MAX];
	public:
	Stack(int n)
	{
		int i;
		for(i=0;i<n;i++)
		{
			top[i]=boundary[i]=(MAX/n*i)-1;
		}
	}
	void push(int i, int item)
	{
		if(top[i-1]==boundary[i])
		{
			cout<<"\nOverflow";
			return;
		}
		top[i-1]++;
		A[top[i-1]]=item;
	}
	int pop(int i)
	{
		if(top[i-1]==boundary[i-1])
		{
			cout<<"\nUnderflow";
			return 0;
		}
		return A[top[i-1]--];
	}
	
	void Display(int i){
		for(int j=boundary[i-1]+1;j<=top[i-1];j++){
			cout<<A[j]<<"\t";
		}	
	}
};
int main()
{
	int n,i,el,choice;
	char res='y';
	cout<<"\nEnter number of stacks: ";
	cin>>n;
	Stack s(n);
	cout<<"\n1. Push\n2. Pop\n3. Display";
	do
	{	
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"\nEnter stack index and element to insert: ";
					cin>>i>>el;
					s.push(i,el);
					break;
			case 2:	cout<<"\nEnter stack index to pop from: ";
					cin>>i;
					cout<<s.pop(i);
			case 3: cout<<"\nEnter stack index to Display: ";
					cin>>i;
					s.Display(i);
		}
		cout<<"\nDo more (y/n)?";
		cin>>res;
	}while(res=='y');
return 0;
}





