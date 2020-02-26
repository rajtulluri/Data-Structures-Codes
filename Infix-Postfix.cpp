#include<iostream>
#include<string.h>
#include<stdio.h>
#define MAX 20
using namespace std;
class Stack{
private:
    int top;
    char infix[MAX];
    char Postfix[MAX];
    char Stacks[MAX];
public:
    Stack(){
        top = -1;
    }

    void Push(char symbol){
        if(top == MAX-1){cout<<"OverFlow";return;}
        Stacks[++top] = symbol;
    }

    char Pop(){
        if(top == -1){cout<<"UnderFlow";return '#';}
        else
            return(Stacks[top--]);
    }

    void Read(){
        cout<<"Enter infix Expression: ";
        cin>>infix;
    }

    int isempty(){
        if(top == -1) return 1;
        else return 0;
    }

    void ContoPfix(){
        int precedence,p=0;
        char op1,op2;
        for(int i =0;infix[i] != '\0'; i++){
            op1 = infix[i];
            switch(op1){
                case '(':
                       Push(op1);
                       break;
                case ')':
                    while((op2 = Pop()) != '('){
                            Postfix[p++] = op2;
                          }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    if(!isempty()){
                        precedence = prec(op1);
                        op2 = Pop();
                        while(precedence <= prec(op2)){
                            Postfix[p++] = op2;
                            if(!isempty()){
                                op2 = Pop();
                            }
                            else
                                break;
                        }
                        if(precedence > prec(op2))
                            Push(op2);
                    }
                    Push(op1);
                    break;
                default:
                    Postfix[p++] = op1;
                    break;
            }
        }
        while(!isempty()){
            Postfix[p++] = Pop();
        }
        Postfix[p] = '\0';
        cout<<"The Postfix Expression: "<<Postfix<<endl;
    }

    int prec(char op){
    switch(op){
    case '(':
           return 0;
           break;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '$':
        return 3;
    default:
        return -1;
    }
    }
};

int main(){
    char ch ='y';
    Stack Stack_;
    while(ch == 'y'){
        Stack_.Read();
        Stack_.ContoPfix();
        cout<<"Want to continue: ";cin>>ch;
    }
return 0;
}
