#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Find the longest subarray with majority elements greater than K
// Approach: Use a prefix sum technique to track the difference between elements greater than K and those less than or equal to K. 
//           Use a hash map to store the first occurrence of each prefix sum.

// Steps:
// 1. Create a difference array where elements greater than K are marked as +1 and elements less than or equal to K are marked as -1.
// 2. Iterate through the difference array, maintaining a prefix sum.
// 3. If the prefix sum is positive, it means there are more elements greater than K.
// 4. If the prefix sum has been seen before, calculate the length of the sub
//    array from the first occurrence of that prefix sum to the current index.
// 5. Keep track of the maximum length of such subarrays.
// 6. Return the maximum length found.

// Time Complexity: O(N), where N is the size of the input array, as we traverse the array once.
// Space Complexity: O(N), for storing the prefix sums in the hash map.

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            if(arr[i]>k){
                diff[i]=1;
            }
            else{
                diff[i]=-1;
            }
        }
        unordered_map<int,int>mp;
        int prefix=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            prefix+=diff[i];
            if(prefix>0){
                maxlen=i+1;
            }
            else{
                if(mp.find(prefix-1)!=mp.end()){
                    maxlen=max(maxlen,i-mp[prefix-1]);
                }
            }
            if(mp.find(prefix)==mp.end()){
                mp[prefix]=i;
            }
        }
        return maxlen;
    }
};