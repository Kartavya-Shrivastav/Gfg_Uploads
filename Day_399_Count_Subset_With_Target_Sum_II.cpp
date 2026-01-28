#include <bits/stdc++.h>    
using namespace std;

// Problem: Count of subsets with given sum K
// Given an array of integers and a target sum K, count the number of subsets of the array that sum up to K.    
// Approach: Use Meet in the Middle technique to split the array into two halves, calculate all possible subset sums for each half, and then use binary search to find complementary sums that add up to K.

// Steps:
// 1. Split the array into two halves.
// 2. Use a recursive function to find all possible subset sums for each half and store them in two separate vectors.
// 3. Sort the vector containing subset sums of the second half.
// 4. For each subset sum in the first half, calculate the required complementary sum to reach K.
// 5. Use binary search (lower_bound and upper_bound) to count how many times the complementary sum appears in the second half's subset sums.   
// 6. Accumulate the counts to get the final answer.

// Time Complexity: O(2^(N/2) * log(2^(N/2))) due to generating subset sums and binary searching.
// Space Complexity: O(2^(N/2)) for storing subset sums of each half


class Solution {
  public:
    
    void find(int index,int end,vector<int> &temp,vector<int> &arr,int sum){
        if(index==end){
            temp.push_back(sum);
            return;
        }
        
        find(index+1,end,temp,arr,sum+arr[index]);
        find(index+1,end,temp,arr,sum);
        
        return;
        
    }
    
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        vector<int>L,R;
        int mid = n/2;
        
        
        find(0,mid,L,arr,0);
        find(mid,n,R,arr,0);
        
        sort(R.begin(),R.end());
        
        int ans = 0;

        for(int x:L){
            int need = k-x;

            // count occurrences of need in rightSums
            auto lo = lower_bound(R.begin(), R.end(), need);
            auto hi = upper_bound(R.begin(), R.end(), need);

            ans += (hi - lo);
        }

        return ans;
        
    }
};