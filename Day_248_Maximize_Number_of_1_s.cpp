#include<bits/stdc++.h>
using namespace std;

// Problem: Maximize the number of 1's in a binary array by flipping at most k 0's
// Approach: Use sliding window to find the longest subarray with at most k 0's

// Steps:
// 1. Initialize two pointers (i, j) for the sliding window
// 2. Expand the window by moving j to the right
// 3. Count the number of 0's in the current window
// 4. If the count of 0's exceeds k, shrink the window from the left
// 5. Update the maximum length of the window found
// 6. Return the maximum length found

// Time Complexity: O(n) 
// Space Complexity: O(1)

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0,j=0,count=0,maxi=0;
        while(j<n){
            if(arr[j]==0) count++;
            while(count>k){
                if(arr[i]==0) count--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
