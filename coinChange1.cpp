//Time Complexity: O(N*T)
//Space Complexity: O(N*T) + O(N)
//CSES problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6+10;
int dp[N];
int func(int arr[], int n, int m) {
    int ans = INT_MAX;
    if (m == 0)return 0;
    if (dp[m] != -1)return dp[m];
    for (int i = 0; i <= n; i++) {
        if (m - arr[i] >= 0) {
            ans = min(ans + 0ll, func(arr,n, m - arr[i]) + 1ll);
        }
    }
    return dp[m] = ans;
}

int main()
{
    fill(dp, dp+N, -1);
    int n,x;
    cin>>n>>x;
    int arr[n+10];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int ans = func(arr, n-1, x);
    if (ans != INT_MAX)cout<<ans;
    else cout<<-1;
}