// 1) Delete head
// 2) Delete tail
// 3) Delete K th element
// 4) Delete any given value


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

Node* DeleteHead(Node* head){
    if(head==nullptr)return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* DeleteTail(Node* head){
    if(head==nullptr || head->next==nullptr)return nullptr;
    Node* temp=head;
    while (temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;

    return head;
}

// Time complexity O(k)
Node* deleteK(Node* head,int k){
    if(head==nullptr)return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;
    Node* previous;
    int count=0;

    while (temp){
        count++;
        if(count==k){
            previous->next=previous->next->next;
            delete temp;
            break;
        }

        previous=temp;
        temp=temp->next;
    }

    return head;
}

Node* DeleteValue(Node* head,int value){
    if(head==nullptr)return head;
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;
    Node* previous;

    while (temp){
        if(temp->data==value){
            previous->next=previous->next->next;
            delete temp;
            break;
        }
        previous=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>arr={5,2,3,4,7,10,11,13,6,9};
    Node* head=convertArrToLL(arr);
    traverse(head);
    cout<<'\n';

    head=DeleteHead(head);
    traverse(head);
    cout<<'\n';
    head=deleteK(head,3);
    traverse(head);
    cout<<'\n';
    head=DeleteValue(head,11);
    traverse(head);
}

