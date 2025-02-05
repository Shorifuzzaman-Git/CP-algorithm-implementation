//AtCoder dp problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int value[105], weight[105];
ll dp[105][100005];

ll solve(int index,int v){
    if(v==0)return 0;
    if(index<0)return 1e10;
    if(dp[index][v]!=-1)return dp[index][v];

    ll ans=solve(index-1,v);
    if(v-value[index]>=0){
        ans=min(ans,solve(index-1,v-value[index])+weight[index]);
    }
    
    return dp[index][v]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;
 
    for(ll i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }

    int max_val=1e5;
    for(ll i=max_val;i>=0;--i){
        if(solve(n-1,i)<=w){
            cout<<i;
            break;
        }
    }
}
