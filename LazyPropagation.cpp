//tutorial bangla + safayet blog
//complexity for update od query O(log(n))
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N=1e3;
int arr[N]={0};
struct info{
    ll prop=0,sum=0;
}tree[4*N];

void makeTree(int node,int begin,int end){
    if(begin==end){
        tree[node].sum=arr[begin];
        return;
    }
    
    int left=2*node;
    int right=2*node+1;
    int mid=(begin+end)/2;

    makeTree(left,begin,mid);
    makeTree(right,mid+1,end);
    tree[node].sum=tree[left].sum+tree[right].sum;
}


void update(int node,int begin,int end,int i,int j,int x){
    if(i>end||j<begin)return;
    if(begin>=i&&end<=j){
        tree[node].sum+=((end-begin+1)*x);
        tree[node].prop+=x;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(begin+end)/2;

    update(left,begin,mid,i,j,x);
    update(right,mid+1,end,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+((end-begin+1)*tree[node].prop);
}

int query(int node,int begin,int end,int i,int j,int carry=0){
    if(i>end||j<begin)return 0;
    if(begin>=i&&end<=j){
        return tree[node].sum+(end-begin+1)*carry;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(begin+end)/2;

    int p1=query(left,begin,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,end,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main() {
    int n=8;
    fill(arr,arr+N,0);
    
    makeTree(1,1,n);
    update(1,1,n,2,4,26);
    update(1,1,n,4,8,80);
    update(1,1,n,4,5,20);
    cout<<query(1,1,n,8,8)<<endl;
    cout<<query(1,1,n,1,8)<<endl;
}