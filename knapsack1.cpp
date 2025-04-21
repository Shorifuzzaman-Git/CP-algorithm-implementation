//AtCoder dp problem
complexity O(n*w)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> value, weight;
vector< vector<ll> > dp;
int n,w;

ll solve(int index,int w){
    if(index==n)return 0;
    if(dp[index][w]!=-1)return dp[index][w];

    ll max_val=0;
    if(w-weight[index]>=0){
        max_val=max(max_val,value[index]+solve(index+1,w-weight[index]));
    }
    max_val=max(max_val,solve(index+1,w));
    return dp[index][w]=max_val;
}

int main(){
    cin>>n>>w;
    dp.resize(n+1,vector<ll>(w+1,-1));
    value.resize(n,0);
    weight.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    cout<<solve(0,w);
}
