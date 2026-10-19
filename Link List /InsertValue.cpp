// 1) Insert value in head
// 2) Insert value in tail
// 3) Insert value in k th index
// 4) Insert value before element x

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


Node* insertHead(Node* head,int value){
    // Node* temp;
    // temp->data=value;
    // temp->next=head;
    // return temp;

    return new Node(value,head);
}

Node* insertTail(Node* head,int value){
    if(head==nullptr)return new Node(value);
    Node* temp=head;
    while (temp){
        if(temp->next==nullptr){
            temp->next=new Node(value);
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* InsertK(Node* head, int k,int value){
    if(head==nullptr){
        if(k==1)return new Node(value);
        else return head;
    }

    if(k==1){
        return new Node(value,head);
    }

    Node* temp=head;
    int count=0;
    while(temp){
        count++;
        if(count==k-1){
            temp->next=new Node(value,temp->next);
            break;
        }
        temp=temp->next;
    }

    return head;
}

//Insert value before the element x
Node* InsertBeforeValue(Node* head, int value,int x){
    if(head==nullptr){
        return head;
    }

    if(head->data==x){
        return new Node(value,head);
    }

    Node* temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==x){
            temp->next=new Node(value,temp->next);
            break;
        }
        temp=temp->next;
    }

    return head;
}

int main(){
    vector<int>arr={5,2,3,4,7,10,11,13,6,9};
    Node* head=convertArrToLL(arr);
    traverse(head);
    cout<<'\n';
    
    head=InsertBeforeValue(head,9,13);
    traverse(head);
}


