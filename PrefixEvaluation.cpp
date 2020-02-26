#include <iostream>
#include <string.h>
using namespace std;
#define MAX 20

class PrefixClass{
private:
    int top;
    char Prefix[MAX];
    int Stack[MAX];
public:
    PrefixClass(){
        top = -1;
    }

    void Push(int item){
        Stack[++top] = item;
    }

    int Pop(){
        return Stack[top--];
    }

    void Read(){
        cout<<"\nEnter Prefix Expression: ";
        cin>>Prefix;
    }

    int PrefixEval(){
        char element;
        int opr1, opr2;
        int result;
        for(int i = strlen(Prefix); i>=0; i--){
            element = Prefix[i];
            switch (element){
                case '+':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr2 + opr1;
                    Push(result);
                    break;
                case '-':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr2 - opr1;
                    Push(result);
                    break;
                case '*':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr2 * opr1;
                    Push(result);
                    break;
                case '/':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr2 / opr1;
                    Push(result);
                    break;
                case '$':
                    opr2 = Pop();
                    opr1 = Pop();
                    result = opr2 ^ opr1;
                    Push(result);
                    break;
                default:
                    Push((element-48));
                    break;
            }
        }
        return Pop();
    }
};

int main(){
    PrefixClass PrefixExp;
    PrefixExp.Read();
    int Result = PrefixExp.PrefixEval();
    cout<<"\nThe prefix Evaluation is: "<<Result<<endl;
    return 0;
}
