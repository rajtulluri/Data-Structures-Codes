#include <iostream>
#include <string.h>
#define MAX 20
using namespace std;

class Postfix_In{
private:
    int top;
    char Stack[MAX][MAX];
    char Postfix[MAX];
public:
    Postfix_In(){
        top = -1;
    }

    void Push(char item[]){
        strcpy(Stack[++top],item);
    }

    char* Pop(){
        return Stack[top--];
    }

    void Read(){
        cout<<"\nEnter the Postfix expression: ";
        cin>>Postfix;
    }


    char* InfixGenerator(){
        char element[2];
        char result[MAX], opr2[10],opr1[10];
        for(int i =0 ; Postfix[i] != '\0'; i++){
            element[0] = Postfix[i];
            element[1] = '\0';
            switch (element[0]){
                case '+':
                case '-':
                case '*':
                case '/':
                case '$':
                    strcpy(opr2,Pop());
                    strcpy(opr1,Pop());
                    strcpy(result,"(");
                    strcat(result,opr1);
                    strcat(result,element);
                    strcat(result,opr2);
                    strcat(result,")");
                    Push(result);
                    break;
                default:
                    Push(element);
                    break;
            }
        }
        return Pop();
    }
};

int main(){
    char* Result;
    Postfix_In PostFix;
    PostFix.Read();
    Result = PostFix.InfixGenerator();
    cout<<"The Infix Expression of the Postfix is: "<<Result<<endl;
    return 0;
}