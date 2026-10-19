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

bool search(Node* head,int value){
    Node* temp=head;

    while (temp!=nullptr){
        if(temp->data==value)return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    vector<int>arr={5,2,3,4,7,10,11,13,6,9};
    Node* head=convertArrToLL(arr);
  
    int x=10;
    if(search(head,x))cout<<"Item found."<<'\n';
    else cout<<"Item not found."<<'\n';
    
}


