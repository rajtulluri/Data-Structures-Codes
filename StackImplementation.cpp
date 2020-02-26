#include<iostream>
using namespace std;
#define MAX 20

class Stacks{
	private:
		int top;
		int Stack[MAX];
	public:
		Stacks(){
			top = -1;
		}
		void Push(int item){
			if(top == MAX-1){
				cout<<"OverFlow";return;
			}
			top++;
			Stack[top] = item;
		}
		int Pop(){
			if(top == -1){
				cout<<"UnderFlow";
				return 0;
			}
			return Stack[top--];
		}
		void Display(){
			for(int i=0;i<top;i++)
				cout<<Stack[top]<<"\t";
		}
};

int main(){
	Stacks stack;
	//Code to use stack object methods 
	return 0;
}
