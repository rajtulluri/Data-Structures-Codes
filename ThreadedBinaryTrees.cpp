#include <iostream>
using namespace std;

class Node{
    int info;
    Node* left;
    Node* right;
    bool isThreaded;

public:

    Node* Create(int n){}
    Node* Insert(int n,Node* root){}
    Node* Delete(Node* root){}

    Node* Threaded(Node* root){
        if(!root)
            return root;
        if(!root->left && !root->right)
            return root;

        if(root->left){
            Node* temp = Threaded(root->left);
            temp->right = root;
            temp->isThreaded = true;
        }

        if(!root->right)
            return root;
        return Threaded(root->right);
    }

    Node* Leftmost(Node* root){
        if(root) {
            while (root->left) {
                root = root->left;
            }
        }
        return root;
    }

    void InOrder(Node* root){
        if(!root)
            return;

        Node* Current = Leftmost(root);
        while (Current){
            cout<<Current->info<<"-->"<<'\t';
            if(Current->isThreaded)
                Current = Current->right;
            else
                Current = Leftmost(Current->right);
        }
    }
};


