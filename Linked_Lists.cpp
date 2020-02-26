#include <iostream>
using namespace std;
class Node{
    int Info;
    Node* next;
public:
    Node* Create(int n){
        Node* temp = new Node;
        temp->Info = n;
        temp->next = NULL;
        return temp;
    }

    Node* Insert_Begn(int n,Node* Head){
        Node* Temp = Create(n);
        if(Head == NULL){
            Head = Temp;
            return Head;
        }

        Temp->next = Head;
        Head = Temp;
        return Head;
    }

    Node* Insert_End(int n,Node* Head){
        Node* Temp = Create(n);
        Node* Current = Head;
        if (Head == NULL){
            Head = Temp;
            return Head;
        }
        while(Current->next != NULL){
            Current = Current->next;
        }
        Current->next = Temp;
        return Head;
    }

    Node* Insert_Pos(int n, Node* Head){
        Node* Temp = Create(n);
        Node* Current = Head;
        Node* Secondary_Temp = new Node;
        if(Head == NULL){
            Head =  Temp;
            return Head;
        }
        int ctr = 0,Pos;
        cout<<"Enter Position: ";cin>>Pos;
        while (ctr <= Pos-2){
            Current = Current->next;
            ctr++;
        }
        Secondary_Temp->next = Current->next;
        Current->next = Temp;
        Temp->next = Secondary_Temp->next;

        return Head;
    }

    Node* Delete_Begn(Node* Head){
        Node* Temp = new Node;
        if(Head == NULL){
            return NULL; //EmptyList
        }
        Temp = Head;
        Head = Head->next;
        delete Temp;
        return Head;
    }

    Node* Delete_End(Node* Head){
        Node* Temp = Head;
        Node* Current = Head;
        Node* Prev = new Node;
        if(Head == NULL){
            return NULL; //EmptyList
        }
        while((Current->next)->next != NULL){
            Current = Current->next;//Current Becomes next Node by Current->next and goes to second last node
        }
        Temp = Current->next;
        Current->next = NULL;
        delete Temp;
        return Head;
    }

    Node* Delete_Pos(Node* Head){
        Node* Temp = new Node;
        Node* Prev = Head;
        Node* Current = new Node;
        int Pos,ctr=0;
        if(Head == NULL){
            return NULL;//EmptyList
        }
        cout<<"Enter Position: ";cin>>Pos;
        while (ctr < Pos-2){
            Prev = Prev->next;
            ctr++;
        }
        if(Prev->next == NULL){
            delete Prev;
            return Head;
        }
        Current = Prev->next;
        Temp = Current->next;
        Prev->next = Temp;
        delete Current;
        return Head;
    }

    void Display(Node* Head){
        Node* Current = new Node;
        Current = Head;
        if(Head == NULL){
            cout<<"EmptyList";
            return;
        }
        while (Current->next != NULL){
            cout<<Current->Info<<" --> ";
            Current = Current->next;
        }
        cout<<Current->Info<<" --> ";
        cout<<"NULL"<<endl;
        return;
    }
};

int main(){
    Node* Head = new Node;
    Head = NULL;
    Node LinkedList;
    int Choice; char ch = 'y';
    do{
        cout<<"1. Insert at Beginning 2. Insert at End 3. Insert at Position"<<endl;
        cout<<"4. Delete at Beginning 5. Delete at End 6. Delete at Position"<<endl;
        cout<<"7. Display"<<endl;
        cout<<"Enter Choice: ";cin>>Choice;
        switch (Choice){
            case 1:
                int Item;
                cout<<"Enter Element to be inserted: ";cin>>Item;
                Head = LinkedList.Insert_Begn(Item,Head);
                break;
            case 2:
                cout<<"Enter element to be inserted: ";cin>>Item;
                Head = LinkedList.Insert_End(Item,Head);
                break;
            case 3:
                cout<<"Enter element to be inserted: ";cin>>Item;
                Head = LinkedList.Insert_Pos(Item,Head);
                break;
            case 4:
                Head = LinkedList.Delete_Begn(Head);
                break;
            case 5:
                Head = LinkedList.Delete_End(Head);
                break;
            case 6:
                Head = LinkedList.Delete_Pos(Head);
                break;
            case 7:
                LinkedList.Display(Head);
        }
        cout<<"Continue y/n ";cin>>ch;
    }while(ch == 'y');
    return 0;
}