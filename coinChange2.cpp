//Time Complexity: O(N*T)
//Space Complexity: O(N*T) + O(N)
//HackerRank coin-change problem

#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    if (ind == 0) {
        return (T % arr[0] == 0);
    }
    
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);
    
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
        
    return dp[ind][T] = notTaken + taken;
}

int main() {
    int n;
    int t;
    cin>>t>>n;
    vector<int> arr(n+1);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    vector<vector<long>> dp(n, vector<long>(t + 1, -1));
    
    cout << countWaysToMakeChangeUtil(arr, n - 1, t, dp) << endl;
}

