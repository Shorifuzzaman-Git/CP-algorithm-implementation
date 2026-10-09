#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

Node* insert(Node* root,int value){
    if(root==nullptr)return new Node(value);

    if(root->data>value)root->left=insert(root->left,value);
    else if(root->data<value)root->right=insert(root->right,value);

    return root;
}

bool search(Node* root,int value){
    if(root==nullptr)return false;

    if(root->data==value)return true;
    if(root->data>value)return search(root->left,value);
    return search(root->right,value);
}

// Inorder successor=Find smallest value in right subtree
Node* getSuccessor(Node* curr){
    curr=curr->right;
    while (curr!=nullptr && curr->left!=nullptr){
        curr=curr->left;
    }
    return curr;
}

Node* Delete(Node* root,int x){
    if(root==nullptr)return root;

    if(root->data>x)root->left=Delete(root->left,x);
    else if(root->data<x)root->right=Delete(root->right,x);
    
    // Root->data == x, then delete root data
    else{
        // Node with 0 or 1 child
        if(root->left==nullptr){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==nullptr){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // Node with 2 children
        Node* succ=getSuccessor(root);
        root->data=succ->data;
        root->right=Delete(root->right,succ->data);
    }
    return root;
}

void inorder(Node* root){
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

void preorder(Node* root){
    if(root==nullptr)return;
    cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<' ';
}


int main(){
    Node* root=nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    cout<<"Inorder :";
    inorder(root);
    cout<<'\n';

    cout<<"Preorder :";
    preorder(root);
    cout<<'\n';

    cout<<"Postorder :";
    postorder(root);
    cout<<'\n';

    int x=10;
    if(search(root,x))cout<<"Found value\n";
    else cout<<"Not found\n";

    root=Delete(root,13);
    inorder(root);
 
}

/*
Complexity: 
If the tree is balanced:
        50
       /  \
     30    70
    / \    / \
   20 40  60 80

Therefore:

Search → O(log n)
Insert → O(log n)
Delete → O(log n)

Worst case:
The BST becomes:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
           \
            7

Therefore:

Search → O(n)
Insert → O(n)
Delete → O(n)

*/

