#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array `arr`, count the number of indices such that removing the element at that index results in the sum of elements at even indices being equal to the sum of elements at odd indices.
// Approach: Prefix Sum Arrays for Even and Odd Indices

// Steps:
// 1. Create two prefix sum arrays: one for sums at even indices and another for sums at odd indices.
// 2. For each index, calculate the new sums of even and odd indices after removing the element at that index.
// 3. Count how many times the sums are equal after the removal.    
// 4. Return the count.

// Complexity Analysis:
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n=(int)arr.size();
        vector<int>prefixOdd(n+1,0);
        vector<int>prefixEven(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            prefixOdd[i] = prefixOdd[i-1];
            prefixEven[i] = prefixEven[i-1];
            
            if((i-1)%2)
            {
                prefixOdd[i]+=arr[i-1];
            }
            else
            {
                prefixEven[i]+=arr[i-1];
            }
        }
        
        int count =0;
        for(int i=0;i<n;i++)
        {
            int sumOdd = prefixOdd[i];
            int sumEven = prefixEven[i];
            
            
            sumEven+=prefixOdd[n] - prefixOdd[i+1];
            sumOdd+=prefixEven[n] - prefixEven[i+1];
            
            if(sumOdd == sumEven)
            count++;
        }
        return count ;
    }
};