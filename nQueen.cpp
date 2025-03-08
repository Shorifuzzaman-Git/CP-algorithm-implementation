//Time complexity O(n*n!)

#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>&board,int row,int col,int n){
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q')return false;
    }
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q')return false;
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q')return false;
    }
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q')return false;
    }
    return true;
}
void nQueen(vector<string>&board,int row,int n,vector<vector<string>> &ans){
    if(row==n){
        ans.push_back({board});
        return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            nQueen(board,row+1,n,ans);
            board[row][col]='.';
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<string> board(n,string(n,'.'));
    vector<vector<string>>ans;
    
    nQueen(board,0,n,ans);


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    
}
