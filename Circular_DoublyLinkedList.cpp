#include<iostream>
using namespace std;

class Node{
    int info;
    Node* next;
    Node* prev;
public:
    Node* Create(int n){
        Node* temp = new Node;
        temp-> info = n;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }

    Node* Insert(int n, Node* Head){
        Node* temp = Create(n);
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

    Node* Delete(Node* Head){
        Node* temp = new Node;
        Node* Current = Head;
        Node* Inter = new Node;

        if(Head==NULL){
            return NULL;
        }

        int item;
        cout<<"Enter the element to be deleted: ";cin>>item;

        if(Head->info == item){
            temp = Head;
            Current = Head->prev;
            Head = Head->next;
            Current->next = Head;
            Head->prev = Current;
            delete temp;
            return Head;
        }

        while((Current->next)->info == item) {
            Current = Current->next;
        }
        if((Current->next)->next == Head){
            temp = Current->next;
            Head->prev = Current;
            Current->next = Head;
            delete temp;
            return Head;
        }

        temp = Current->next;
        Inter = temp->next;
        Current->next = Inter;
        Inter->prev = Current;
        delete temp;
        return Head;
    }

    void Display(Node* Head){
        Node* Current = Head;
        while(Current->next != Head){
            cout<<Current->info<<" -> ";
            Current = Current->next;
        }
        cout<<Current->info;
    }

};

int main(){
    Node CDLinkedList;
    Node* Head = new Node;
    Head = NULL;
    char res = 'y';

    do{
        cout<<"1.Insert   2. Delete  3. Display   \n";
        cout<<"Enter Choice";int Choice;
        cin>>Choice;
        switch(Choice){
            case 1:
                int item;
                cout<<"Enter elment to be inserted ";cin>>item;
                Head = CDLinkedList.Insert(item,Head);
                break;
            case 2:
                Head = CDLinkedList.Delete(Head);
                break;
            case 3:
                CDLinkedList.Display(Head);
        }
        cout<<"Continue y/n";
        cin>>res;
    }while(res == 'y');

    return 0;
}