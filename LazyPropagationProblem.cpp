// spare online judge "Horrible Queries" safayet blog 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N=1e5+10;
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
    int left=2*node;
    int right=2*node+1;
    int mid=(begin+end)/2;

    update(left,begin,mid,i,j,x);
    update(right,mid+1,end,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(end-begin+1)*tree[node].prop;
}

int query(int node,int begin,int end,int i,int j,int carry=0){
    if(i>end||j<begin)return 0;
    if(begin>=i&&end<=j){
        return tree[node].sum+(end-begin+1)*carry;
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(begin+end)/2;

    int p1=query(left,begin,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,end,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,c;
        cin>>n>>c;
        fill(arr,arr+N,0);
        memset(tree,0,sizeof(tree));
        makeTree(1,1,n);
        while (c--)
        {
            int flag;
            int p,q,v;
            cin>>flag;
            if(flag==0){
                cin>>p>>q>>v;
                update(1,1,n,p,q,v);
            }
            if(flag==1){
                cin>>p>>q;
                cout<<query(1,1,n,p,q)<<endl;
            }
        } 
    } 
}

// 2
// 8 6
// 0 2 4 26
// 0 4 8 80
// 0 4 5 20
// 1 8 8 
// 0 5 7 14
// 1 4 8