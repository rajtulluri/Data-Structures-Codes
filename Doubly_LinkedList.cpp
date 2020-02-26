#include <iostream>
using namespace std;

class Node{

    int Info;
    Node* next;
    Node* prev;

public:

    Node* Create(int n){
        Node* Temp = new Node;
        Temp->Info = n;
        Temp->next = NULL;
        Temp->prev = NULL;
        return Temp;
    }

    Node* Insert_Begn(int n, Node* Head, Node* Tail){
        Node* Temp = Create(n);
        Node* Current = Head;
        if(Head == NULL){
            Head = Temp;
            Tail = Temp;
            return Head;
        }

        Temp->next = Head;
        Current->prev = Temp;
        Head = Temp;
        return Head;
    }

    Node* Insert_End(int n, Node* Head, Node* Tail){
        Node* Temp = Create(n);
        Node* Current = Head;
        if(Head == NULL){
            Head = Temp;
            Tail = Temp;
            return Head;
        }

        while(Current->next != NULL){
            Current = Current->next;
        }
        Current->next = Temp;
        Temp->prev = Current;
        Tail = Temp;
        return Head;
    }

    Node* Insert_Pos(int n, Node* Head,Node* Tail){
        Node* Temp = Create(n);
        Node* Current = Head;
        Node* Previous = Head;
        int Pos,ctr=0;

        if(Head == NULL){
            Head = Temp;
            Tail = Temp;
            return Head;
        }

        cout<<"Enter Position: ";cin>>Pos;
        while (ctr < Pos-2){
            Previous = Previous->next;
            ctr++;
        }
        Current = Previous->next;
        Previous->next = Temp;
        Current->prev = Temp;
        Temp->next = Current;
        Temp->prev = Previous;
        return Head;
    }

    Node* Delete_Begn(Node* Head, Node* Tail){
        Node* Temp = Head;
        Node* Current = Head;
        Current = Current->next;
        if(Head == NULL){
            return NULL; //EmptyList
        }

        Current->prev = NULL;
        Head = Current;
        delete Temp;
        return Head;
    }

    Node* Delete_End(Node* Head, Node* Tail){
        Node* Current = new Node;
        Node* Previous = Head;
        if(Head == NULL){
            return NULL;//EmptyList
        }

        while ((Previous->next)->next != NULL){
            Previous = Previous->next;
        }
        Current = Previous->next;
        Previous->next = NULL;
        Tail = Previous;
        delete Current;
        return Head;
    }

    Node* Delete_Pos(Node* Head, Node* Tail){
        Node* Current = new Node;
        Node* Temp = new Node;
        Node* Previous = Head;
        int Pos,ctr=0;

        if(Head == NULL){
            return NULL; //EmptyList
        }

        cout<<"Enter Position: ";cin>>Pos;
        while (ctr < Pos-2){
            Previous = Previous->next;
            ctr++;
        }
        Current = Previous->next;
        Temp = Current;
        Current = Current->next;
        Previous->next = Current;
        Current->prev = Previous;
        delete Temp;
        return Head;
    }

    void Display(Node* Head){
        Node* Current = Head;
        if(Head == NULL){
            cout<<"EmptyList";
            return;
        }
        while (Current->next != NULL){
            cout<<Current->Info<<" <--> ";
            Current = Current->next;
        }
        cout<<Current->Info<<" <--> "<<"NULL"<<endl;
        return;
    }

    void Display_Bck(Node* Tail){
        Node* Current = Tail;
        if(Tail == NULL){
            cout<<"EmptyList";
            return;
        }
        while (Current->prev != NULL){
            cout<<Current->Info<<" <--> ";
            Current = Current->prev;
        }
        cout<<Current->Info<<" <--> "<<"NULL"<<endl;
        return;
    }
};

int main(){
    Node* Head = new Node;
    Node* Tail = new Node;
    Head = Tail = NULL;
    Node LinkedList;
    int Choice; char ch = 'y';
    do{
        cout<<"1. Insert at Beginning 2. Insert at End 3. Insert at Position"<<endl;
        cout<<"4. Delete at Beginning 5. Delete at End 6. Delete at Position"<<endl;
        cout<<"7. Display 8. Display Backwards"<<endl;
        cout<<"Enter Choice: ";cin>>Choice;
        switch (Choice){
            case 1:
                int Item;
                cout<<"Enter Element to be inserted: ";cin>>Item;
                Head = LinkedList.Insert_Begn(Item,Head,Tail);
                break;
            case 2:
                cout<<"Enter element to be inserted: ";cin>>Item;
                Head = LinkedList.Insert_End(Item,Head,Tail);
                break;
            case 3:
                cout<<"Enter element to be inserted: ";cin>>Item;
                Head = LinkedList.Insert_Pos(Item,Head,Tail);
                break;
            case 4:
                Head = LinkedList.Delete_Begn(Head,Tail);
                break;
            case 5:
                Head = LinkedList.Delete_End(Head,Tail);
                break;
            case 6:
                Head = LinkedList.Delete_Pos(Head,Tail);
                break;
            case 7:
                LinkedList.Display(Head);
                break;
            case 8:
                LinkedList.Display_Bck(Tail);
                break;
        }
        cout<<"Continue y/n ";cin>>ch;
    }while(ch == 'y');
    return 0;
}
