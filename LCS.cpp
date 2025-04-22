//Complexity O(n^2)

#include <bits/stdc++.h>
using namespace std;
const int N= 1e6;
int dp[1005][1005];

//Complexity analysis : No loop into the function,
//but its 2D DP because changes i and j.
//For this resones the time complexity is i*j 
//that means overall time complexity is O(n^2). 

int LCS(int i,int j,string s1,string s2){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=LCS(i-1,j,s1,s2);
    ans=max(ans,LCS(i,j-1,s1,s2));
    ans=max(ans,LCS(i-1,j-1,s1,s2)+(s1[i]==s2[j]));
    return dp[i][j]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    string s1,s2;
    cin>>s1>>s2;
    cout<<LCS(s1.size()-1,s2.size()-1,s1,s2)<<endl;
}