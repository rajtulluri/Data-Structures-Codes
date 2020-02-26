#include<iostream>
using namespace std;

class Node{
    int Coeff;
    int Pow;
    Node* next;
    Node* prev;

public:

    Node* Create(int n, int p){
        Node* temp = new Node;
        temp->Coeff = n;
        temp->Pow = p;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }

    Node* Insert(int n , int p, Node* Head){
        Node* temp = Create(n,p);
        Node* Current = Head;

        if(Head == NULL){
            Head = temp;
            temp->next = Head;
            temp->prev = Head;
            return Head;
        }

        while(Current->next != Head){
            Current = Current->next;
        }
        Current->next = temp;
        temp->prev = Current;
        temp->next = Head;
        return Head;
    }

    Node* Addition(Node* Head1, Node* Head2, Node* Head3){
        Node* Eq1 = Head1;
        Node* Eq2 = Head2;

        if(Head1 == NULL){
            Head3 = Head2;
            return Head3;
        }
        if(Head2 == NULL){
            Head3 = Head1;
            return Head3;
        }
        int flag1 = 1,flag2=1;
        while((Eq1 != Head1||flag1) && (Eq2 != Head2||flag2)) {
            if (Eq1->Pow == Eq2->Pow) {
                Head3 = Insert((Eq1->Coeff + Eq2->Coeff), Eq1->Pow, Head3);
                Eq1 = Eq1->next;
                Eq2 = Eq2->next;
                flag1 = flag2 = 0;
            } else if (Eq1->Pow > Eq2->Pow) {
                Head3 = Insert(Eq1->Coeff, Eq1->Pow, Head3);
                Eq1 = Eq1->next;
                flag1 = 0;
            } else if (Eq1->Pow < Eq2->Pow) {
                Head3 = Insert(Eq2->Coeff, Eq2->Pow, Head3);
                Eq2 = Eq2->next;
                flag2 = 0;
            }
        }
        while(Eq1 != Head1){
            Head3 = Insert(Eq1->Coeff,Eq1->Pow,Head3);
            Eq1 = Eq1->next;
        }
        while(Eq2 != Head2){
            Head3 = Insert(Eq2->Coeff,Eq2->Pow,Head3);
            Eq2 = Eq2->next;
        }

        return Head3;
    }

    Node* Multiplication(Node* Head1, Node* Head2, Node* Head3){
        Node* Eq1 = Head1;
        Node* Eq2 = Head2;

        if(Head1 == NULL){
            Head3 = Head2;
            return Head3;
        }
        if(Head2 == NULL){
            Head3 = Head1;
            return Head3;
        }
        int flag1=1,flag2=1;
        while(Eq1 != Head1||flag1){
            while(Eq2 != Head2||flag2){
                Head3 = Insert((Eq1->Coeff*Eq2->Coeff),(Eq1->Pow+Eq2->Pow),Head3);
                Eq2 = Eq2->next;flag2=0;
            }
            Eq1 = Eq1->next;flag1=0;flag2=1;
        }

        Node* temp = Head3;
        while(temp->next != Head3){
            Node* Inter = new Node;
            Inter = temp->next;
            while(Inter->next != Head3){
                if(temp->Pow == Inter->Pow){
                    temp->Coeff = temp->Coeff+Inter->Coeff;
                    Node* t1 = new Node;Node* t2 = new Node;
                    t1 = Inter->next;
                    t2 = Inter->prev;
                    t1->prev = t2;
                    t2->next = t1;
                    delete Inter;
                }
                Inter = Inter->next;
            }
            temp = temp->next;
        }
        return Head3;
    }

    void Display(Node* Head){
        Node* Current = Head;
        while(Current->next != Head){
            cout<<Current->Coeff<<"x^"<<Current->Pow<<" + ";
            Current = Current->next;
        }
        cout<<(Current->Coeff)<<"x^"<<Current->Pow<<endl;
    }
};

int main(){
    Node* Head1 = new Node;
    Node* Head2 = new Node;
    Node* Head3 = new Node;
    Node* Head4 = new Node;
    Head1 = Head2 = Head3 = Head4 = NULL;
    Node Poly;
    int t1, t2,c,p;
    cout<<"Terms in Eq 1 ";cin>>t1;
    cout<<"Terms in Eq 2 ";cin>>t2;
    for(int i=0;i<t1;i++){
        cout<<"Enter coeff: ";cin>>c;
        cout<<"Enter power: ";cin>>p;
        Head1 = Poly.Insert(c,p,Head1);
    }
    Poly.Display(Head1);
    for(int i=0;i<t2;i++){
        cout<<"Enter coeff: ";cin>>c;
        cout<<"Enter power: ";cin>>p;
        Head2 = Poly.Insert(c,p,Head2);
    }
    Poly.Display(Head2);
		cout<<"\nThe Addition and Multiplication respectively: "<<endl;
    Head3 = Poly.Addition(Head1,Head2,Head3);
    Poly.Display(Head3);
    Head4 = Poly.Multiplication(Head1,Head2,Head4);
    Poly.Display(Head4);
    return 0;
}
