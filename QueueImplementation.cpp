#include<iostream>
using namespace std;
#define MAX 20

class Queues{
	private:
		int front;
		int rear;
		int Queue[MAX];
	public:
		Queues(){
			front = -1;
			rear = -1;
		}
		
		void Insert(int item){
			if(rear == MAX-1){
				cout<<"OverFlow";return;
			} 
			if(rear == -1){
				front = 0;
			}
			Queue[++rear] = item;
		}
		
		int Remove(){
			if(front == -1){
				cout<<"UnderFlow";return -1;
			}
			if(front = rear+1){
				cout<<"UnderFlow";
				front = rear = -1;
			}
			return Queue[front++];
		}

		void Display(){
			for(int i=front;i<=rear;i++){
				cout<<Queue[i]<<"\t";
			}
		}
};

int main(){
	Queues queue;
	//Code to use queue object methods 
	return 0;
}
