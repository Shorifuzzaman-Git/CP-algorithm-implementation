// Time complexity O(n)
// Space complexity depends on the computer. Each node stores data and a pointer.
//On a 32-bit system, an int takes 4 bytes and a pointer takes 4 bytes. A node takes a total of 8 bytes.
//On a 64-bit system, an int takes 4 bytes and a pointer takes 8 bytes. A node takes a total of 12 bytes.

// Learn Linked List from "Take you forward" on YouTube.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int value){
        data=value;
        next=nullptr;
    }

    public:
    Node(int value,Node* head){
        data=value;
        next=head;
    }

};

// Time complexity O(n)
Node* convertArrToLL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void traverse(Node* head){
    Node* temp=head;

    while (temp!=nullptr){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}

int lengthOfLL(Node*head){
    Node* temp=head;

    int length=0;
    while (temp){
        length++;
        temp=temp->next;
    }
    return length;
}

int main(){
    vector<int>arr={5,2,3,4,7,10,11,13,6,9};
    Node* head=convertArrToLL(arr);
    traverse(head);
    cout<<'\n';
    cout<<lengthOfLL(head)<<'\n';
}
