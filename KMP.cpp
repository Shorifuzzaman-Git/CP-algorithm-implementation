//tutorial bangla(main), extra hindi amazon video
//time complexity of KMP is : 
// O(n+m) //where n=text.size(), m=pattern.size()

#include<bits/stdc++.h>
using namespace std;

vector<int> LpsArr(string pattern){
    int n=pattern.size();
    vector<int>lps(n);
    int index=0;
    int i=1;
    while(i<n){
        if(pattern[i]==pattern[index]){
            lps[i]=index+1;
            index++;
            i++;
        }
        else{
            if(index!=0)index=lps[index-1];
            else{
                lps[i]=index;
            }
            i++;
        }
    }
    return lps;
}

void kmp(string text,string pattern){
    vector<int>lps=LpsArr(pattern);
    int i=0,j=0; //i=for text,j=for pattern
    bool found=false;

    while(i<text.size()){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!=0)j=lps[j-1];
            i++;
        }
        if(j==pattern.size()){
            cout<<"Pattern found at index number : "<<(i-pattern.size())+1<<endl; //output one base index
            found=true;
            j=lps[j-1]; //if pattern found more than one time in the text //initialize j for pattern size
            //otherwise use break or return
            //break
        }
    }
    if(found==false)cout<<"pattern not found."<<endl;
}
int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    // vector<int>v=LpsArr(pattern);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<' ';
    // }
    
    kmp(text,pattern); 
}