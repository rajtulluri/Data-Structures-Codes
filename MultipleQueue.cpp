#include<iostream>
#define MAX 20
using namespace std;

class MultipleQueue{
	private:
		int front[MAX];
		int rear[MAX];
		int temp[MAX];
		int Queue[MAX];
	public:
		MultipleQueue(int n){
			for(int i=0;i<=n;i++){
				front[i] = rear[i] = temp[i] = (MAX/n)*i-1;
			}
		}
		
		void Insert(int item, int idx){
			if(rear[idx-1] == front[idx]){
				cout<<"Overflow";
				return;
			}
			else if(rear[idx-1] == temp[idx-1]){
				front[idx-1]++;
			}
			else{
				rear[idx-1]++;
				Queue[rear[idx-1]] = item;
			}
		}
		
		int Remove(int idx){
			if(front[idx-1] == temp[idx-1]){
				cout<<"Underflow";return 0;
			}
			else if(front[idx-1] = rear[idx-1]+1){
				cout<<"Underflow";
				front[idx-1]=rear[idx-1]=temp[idx-1];
			}
			else{
				return Queue[front[idx-1]++];				
			}
		}

		void Display(int idx){
			for(int j=front[idx-1]; j<= rear[idx-1]; j++){
				cout<<Queue[j]<<"\t";
			}
		}

};

int main(){

	int n;
	cout<<"Enter Number of Queues: ";cin>>n;
	MultipleQueue Queue(n);
	cout<<"\n1.Insert\n2.Remove\n3.Display\n";
	int choice;	
	char ch='y';
	do{
	cout<<"Enter Choice ";
	cin>>choice;
	switch(choice){
		case 1: cout<<"Enter index: ";
			int i;cin>>i;
			cout<<"Enter element: ";
			int item;cin>>item;
			Queue.Insert(item,i);
			break;
		case 2: cout<<"Enter index: ";
			cin>>i;
			cout<<Queue.Remove(i);
			break;
		case 3: cout<<"Enter index: ";
			cin>>i;
			Queue.Display(i);
			break;
	}
	cout<<"Do more y/n: ";cin>>ch;
	}while(ch == 'y');
return 0;
}
