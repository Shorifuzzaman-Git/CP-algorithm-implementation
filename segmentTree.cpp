//segment tree algorithm
//tutorial bangla + safyet blog 
//time complexity : for 1) segment tree O(n log(n)) / O(n)
                      //2) for any query O(log(n))
                

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=1e3+5;
typedef long long ll;
int arr[N],tree[N*3];

void makeTree(int node,int begin,int end){
    if(begin==end){
        tree[node]=arr[begin];
        return;
    }
    
    int left=2*node;
    int right=2*node+1;
    int mid=(begin+end)/2;

    makeTree(left,begin,mid);
    makeTree(right,mid+1,end);
    tree[node]=tree[left]+tree[right];
    //tree[node]=max(tree[left],tree[right]);  // for find max element in a rang 
}

int query(int node,int begin,int end,int i,int j){
    if(i>end||j<begin)return 0;
    if(begin>=i&&end<=j)return tree[node];

    int left=2*node;
    int right=2*node+1;
    int mid=(begin+end)/2;

    int p1=query(left,begin,mid,i,j);
    int p2=query(right,mid+1,end,i,j);
    return p1+p2;
}

void updat(int node,int begin,int end,int i,int newValue){
    if(i>end||i<begin)return;
    if(begin==end){
        tree[node]=newValue;
        return;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(begin+end)/2;

    updat(left,begin,mid,i,newValue);
    updat(right,mid+1,end,i,newValue);
    tree[node]=tree[left]+tree[right];
}

int maxNumber(int node,int begin,int end,int i,int j){
    if(i>end||j<begin)return INT_MIN;
    if(begin>=i&&end<=j)return tree[node];

    int left=2*node;
    int right=2*node+1;
    int mid=(begin+end)/2;

    int p1=maxNumber(left,begin,mid,i,j);
    int p2=maxNumber(right,mid+1,end,i,j);
    return max(p1,p2);
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    makeTree(1,1,n);
    int sum=query(1,1,n,2,6);
    cout<<sum<<endl;
    updat(1,1,n,5,5);
    cout<<query(1,1,n,2,6)<<endl;
    //cout<<maxNumber(1,1,n,2,6)<<endl;
}

// 7
// 4 -9 3 7 1 0 2