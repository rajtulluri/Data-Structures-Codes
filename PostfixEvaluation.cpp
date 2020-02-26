#include<iostream>
#define MAX 20
using namespace std;

class PostFix{
private:
    int Stack[MAX];
    char P_Eval[MAX];
    int top;

public:
    PostFix(){
        top = -1;
    }

    void Push(int item){
        Stack[++top] = item;
    }

    int Pop(){
        return Stack[top--];
    }

    void Read(){
        cout<<"\nEnter the Postfix expression: ";
        cin>>P_Eval;
    }

    int PostfixEval(){
        char element;
        int opr1, opr2;
        int result;
        for(int i=0;P_Eval[i] != '\0';i++){
            element = P_Eval[i];
            switch (element) {
                case '+':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr1 + opr2;
                    Push(result);
                    break;
                case '-':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr1 - opr2;
                    Push(result);
                    break;
                case '*':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr1 * opr2;
                    Push(result);
                    break;
                case '/':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr1 / opr2;
                    Push(result);
                    break;
                case '$':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = (opr1 ^ opr2);
                    Push(result);
                    break;
                default:
                    Push((element-48));
                    break;
            }
        }
       return (Pop());
    }

};

int main(){
    int Result = 0;
    PostFix Pfix;
    Pfix.Read();
    Result = Pfix.PostfixEval();
    cout<<"\nThe Evaluated expression is: "<<Result<<endl;
    return 0;
}
