#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define ll long long

vector<ll> arr(N);
int dp[N];

ll lis(int n){
    int ans = 1;
    if (dp[n] != -1)return dp[n];

    for (int i = 0; i < n; i++){
        int x;
        if (arr[n] > arr[i]){
            x=lis(i)+1;
            if(ans<x){
                ans=x;
            }
        }
    }
    return dp[n] = ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = 0,x;
    for (int i = 0; i <n; i++){
        //x=lis(i);
        //if(ans<x)ans=x;
        ans = max(ans+0ll, lis(i));
    }
    cout<<ans<<endl;
}