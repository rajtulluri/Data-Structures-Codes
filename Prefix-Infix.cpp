#include<iostream>
#include <string.h>
using namespace std;
#define MAX 20

class Prefix_In {
private:
    char Stack[MAX][MAX];
    char Prefix[MAX];
    int top;
public:
    Prefix_In(){
        top = -1;
    }

    void Push(char* item){
        strcpy(Stack[++top],item);
    }

    char* Pop(){
        return Stack[top--];
    }

    void Read(){
        cout<<"Enter the Prefix Expression: ";
        cin>>Prefix;
    }

    char* InfixGenerator(){
        char element[2];
        char opr1[10],opr2[10], result[MAX];
        for(int i=strlen(Prefix)-1; i>=0;i--){
            element[0] = Prefix[i];
            element[1] = '\0';
            switch (element[0]){
                case '+':
                case '*':
                case '-':
                case '$':
                case '/':
                    strcpy(opr2,Pop());
                    strcpy(opr1,Pop());
                    strcpy(result,")");
                    strcat(result,opr1);
                    strcat(result,element);
                    strcat(result,opr2);
                    strcat(result,"(");
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

int  main(){
    char* Result;
    Prefix_In PreFix;
    PreFix.Read();
    Result = PreFix.InfixGenerator();
    for(int i=strlen(Result)-1;i>=0;i--){
        cout<<Result[i];
    }
    return 0;
}