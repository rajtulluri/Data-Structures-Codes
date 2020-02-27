#include <iostream>
using namespace std;

class Node{
    int info;
    Node* right;
    Node* left;
public:
    Node* Create(int n){
        Node* Temp = new Node;
        temp->info = n;
        temp->right = NULL;
        temp_>left = NULL;
        return temp;
    }

    void Insert(int n,Node* root){
        if(root == NULL){
            Node* temp = Create(n);
            root = temp;
            return;
        }
        if(n < root->info){
            Insert(n,root->left);
            return;
        }
        if(n > root->info){
            Insert(n,root->right);
            return;
        }
        if(n == root->info){
            cout<<"Already in the tree";
        }
    }

    Node* Search(int n, Node* root){
        if(root->info == n){
            return root;
        }
        if(n < root->info){
            root = Search(n,root->left);
            return root;
        }
        if(n > root->info) {
            root = Search(n, root->right);
            return root;
        }
    }

    void Traverse(Node* root){
        if(root == NULL){
            return;
        }
        Traverse(root->left);
        cout<<root->data;
        Traverse(root->right);
        return;
    }

    Node* Delete(Node* Search, int n){

    }

};
