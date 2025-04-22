//complexity O(n log(n))

#include <bits/stdc++.h>
using namespace std;

// Function to compute the length of LIS
int lengthOfLIS(vector<int>& nums) {
    vector<int> tail; // Stores the smallest tail of all increasing subsequences

    for (int num : nums) {
        // Find the first element in tail >= num
        auto it = lower_bound(tail.begin(), tail.end(), num);

        if (it == tail.end()) {
            // If num is larger than all tails, extend the LIS
            tail.push_back(num);
        } else {
            // Replace the first larger or equal element to maintain smallest tails
            *it = num;
        }
    }

    return tail.size(); // The size of tail is the LIS length
}

// Function to reconstruct and return the actual LIS
vector<int> reconstructLIS(vector<int>& nums) {
    vector<int> tail;
    vector<int> parent(nums.size(), -1); // To keep track of previous indices
    vector<int> tailIndices(nums.size()); // Stores indices of elements in 'tail'

    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        auto it = lower_bound(tail.begin(), tail.end(), num);
        int idx = it - tail.begin();

        if (it == tail.end()) {
            tail.push_back(num);
        } else {
            *it = num;
        }

        tailIndices[idx] = i; // Store the index where this num is placed
        parent[i] = (idx > 0) ? tailIndices[idx - 1] : -1; // Link to previous element
    }

    // Backtrack to reconstruct the LIS
    vector<int> lis;
    int curr = tailIndices[tail.size() - 1]; // Start from the last element in LIS
    while (curr != -1) {
        lis.push_back(nums[curr]);
        curr = parent[curr]; // Move to the previous element
    }

    reverse(lis.begin(), lis.end()); // Reverse to get the correct order
    return lis;
}

int main() {
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=0;i<n;i++)cin>>nums[i];

    // Compute the length of LIS
    int lisLength = lengthOfLIS(nums);
    cout << "Length of LIS: " << lisLength << endl; // Output: 3

    // Reconstruct and print the actual LIS
    vector<int> lis = reconstructLIS(nums);
    cout << "One possible LIS: ";
    for (int num : lis) {
        cout << num << " ";
    }
    // Output: 9 21 50 (or 10 33 50, depending on implementation)

    return 0;
}

// 8
// 10 9 2 5 3 7 101 18