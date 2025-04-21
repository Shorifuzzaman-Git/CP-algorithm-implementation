//time complexity is O( n log(n) + (n*max_deadline) )

#include <bits/stdc++.h>
using namespace std;

struct job
{
    int id;
    int deadline;
    int profite;
};

int comparator(job a,job b){
    return a.profite>b.profite;
}

void func(job arr[],int n,int max_deadline){
    vector<int>solution(max_deadline+1,-1);
    int count=0,profitSum=0;
    for(int i=0;i<n;i++){  // complexity O(n*max_deadline)
        if(solution[arr[i].deadline]==-1){
            solution[arr[i].deadline]=arr[i].profite;
            profitSum+=arr[i].profite;
            count++;
        }
        else{
            for(int j=arr[i].deadline;j>0;j--){
                if(solution[j]==-1){
                    solution[j]=arr[i].profite;
                    profitSum+=arr[i].profite;
                    count++;
                    break;
                }
            }
        }
    }
    cout<<count<<endl;
    cout<<profitSum<<endl;
}


int main() {
    int n;
    cin>>n;
    vector<int>id(n),deadline(n),profite(n);

    for(int i=0;i<n;i++)cin>>id[i];
    for(int i=0;i<n;i++)cin>>deadline[i];
    for(int i=0;i<n;i++)cin>>profite[i];

    job arr[n];
    for(int i=0;i<n;i++){
        arr[i]={id[i],deadline[i],profite[i]};
    }

    int max_deadline=*max_element(deadline.begin(),deadline.end());

    sort(arr,arr+n,comparator); // complexity O(n log(n))
    func(arr,n,max_deadline);   // complexity O(n*max_deadline)
    // Final time complexity is O( n log(n) + (n*max_deadline) )
}


// 4
// 1 2 3 4
// 4 1 1 1
// 20 1 40 30

// 5
// 1 2 3 4 5
// 2 1 2 1 1
// 100 19 27 25 15
