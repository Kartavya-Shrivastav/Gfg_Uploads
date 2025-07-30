#include <bits/stdc++.h>
using namespace std;
// Problem: Count the number of subarrays with a given sum k.
// Approach: Use a hashmap to store the cumulative sum and its frequency.
// Steps:
// 1. Initialize a hashmap to store the cumulative sum and its frequency.
// 2. Traverse the array while maintaining a cumulative sum.
// 3. For each element, check if the cumulative sum minus k exists in the hashmap
//    and if it does, add its frequency to the result.
// 4. Update the hashmap with the current cumulative sum.
// Time Complexity: O(n) where n is the length of the array, as we traverse the array once.
// Space Complexity: O(n) for the hashmap to store cumulative sums.
class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
         unordered_map<int,int> mp; 
        mp[0]=1;
        int size=arr.size();
        int res=0;
        int sum=0;
        for(int i=0;i<size;i++){ 
          sum+=arr[i];
          int rem = sum-k;
         if(mp.find(rem)!=mp.end()){
             res+=mp[rem];
         }
         mp[sum]++;
        }
        return res;
    }
};