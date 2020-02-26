#include <iostream>
#include <string.h>
#define MAX 20
using namespace std;

class Prefix{
private:
    int top;
    char Stack[MAX];
    char Infix[MAX];
    char PrefixExp[MAX];
public:
    Prefix(){
        top = -1;
    }

    void Push(char item){
        Stack[++top] = item;
    }

    char Pop(){
        return Stack[top--];
    }

    int isEmpty(){
        if(top == -1){
            return 1;
        }
        return 0;
    }

    void Read(){
        cout<<"\nEnter Infix expression: ";
        cin>>Infix;
    }

    void PrefixGenerator(){
        char element;
        char element_s;
        int j=0;
        for(int i = strlen(Infix)-1;i>= 0;i--){
            element = Infix[i];
            switch (element){
                case ')':
                    Push(element);
                    break;
                case '(':
                    while((element_s=Pop()) != ')'){
                        PrefixExp[j++] = element_s;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '$':
                case '/':
                    if(!isEmpty()){
                        int prec = Precedence(element);
                        element_s = Pop();
                        while(prec <= Precedence(element_s)){
                            PrefixExp[j++] = element_s;
                            if(!isEmpty()){
                                element_s = Pop();
                            }
                            else break;
                        }
                        if(prec > Precedence(element_s)){
                            Push(element_s);
                        }
                    }
                    Push(element);
                    break;
                default:
                    PrefixExp[j++] = element;
                    break;
            }
        }
        PrefixExp[j++] = Pop();
        PrefixExp[j] = '\0';
        Display();
    }

    void Display(){
        cout<<"\nThe Prefix of the Infix Expression is: ";
        for(int i = strlen(PrefixExp)-1; i>= 0;i--){
            cout<<  PrefixExp[i];
        }
        cout<<endl;
    }

    int Precedence(char ele){
        switch (ele){
            case ')':
                return 0;
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '$':
                return 3;
        }
    }

};

int main(){
    Prefix Pfix;
    Pfix.Read();
    Pfix.PrefixGenerator();
    return 0;
}
