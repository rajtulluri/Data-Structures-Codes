#include<iostream>
using namespace std;

class Node{
    int info;
    Node* left;
    Node* right;

public:

    Node* Create(int n){
        Node* temp = new Node;
        temp->info = n;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    Node* Insert(int n,Node* root,char* c){
        if(root == NULL){
            Node* temp = Create(n);
            root = temp;
            return;
        }

        if(*c == 'R'){
            root->right = Insert(n,root->right,++c);
        }
        if(*c == 'L'){
            root->left = Insert(n,root->left,++c);
        }
        return;
    }

    void Equal(Node* root1, Node* root2){
        if(root1 == NULL && root2 == NULL){
            return;
        }
        bool flag = true;
        if(root1->info == root2->info){
            Equal(root1->left,root2->left);
            Equal(root2->right,root2->right);
        }
        else
        {	return;
		flag=false;
	}
        return;
    }
};
