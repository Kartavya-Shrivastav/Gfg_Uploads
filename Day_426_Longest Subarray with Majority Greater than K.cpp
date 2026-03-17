#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers arr and an integer k, return the length of the longest subarray where the majority of elements are greater than k.
A majority of elements in a subarray means that more than half of the elements in the subarray are greater than k.

Approach: We can use a prefix sum approach to solve this problem. We will create a new array where each element is 1 if the corresponding element in the original array is greater than k, and -1 otherwise. Then, we will compute the prefix sum of this new array. The longest subarray with a positive prefix sum will be our answer.  

Steps:
1. Create a new array `cal` where `cal[i]` is 1 if `arr[i] > k`, and -1 otherwise.
2. Compute the prefix sum array `psumCal` from the `cal` array.
3. Use an unordered map to store the first occurrence of each prefix sum value.
4. Iterate through the prefix sum array:  
    - If the current prefix sum is greater than 0, update the answer with the length of the subarray from the start to the current index.
    - If the current prefix sum is not greater than 0, check if there is a previous prefix sum that is one less than the current prefix sum. If it exists, update the answer with the length of the subarray from that index to the current index.
    - If the current prefix sum has not been seen before, store its index in the unordered map.
5. Return the maximum length found.

Time Complexity: O(n), where n is the length of the input array.
Space Complexity: O(n), due to the additional arrays and unordered map used for prefix sums and their indices.
*/

class Solution {
public:
  virtual int longestSubarray(vector<int> &arr, int k) {
    int n=arr.size();
    vector<int> cal(n, 0);

    for(int i=0; i<n; i++){
      if(arr[i]>k) cal[i]=1;
      else cal[i]=-1;
    }
  
    vector<int> psumCal(n, 0);
    psumCal[0]=cal[0];
    for(int i=1; i<n; i++){
      psumCal[i]=psumCal[i-1]+cal[i];   
    }

    unordered_map<int, int> um;
    int ans=0;

    for(int i=0; i<n; i++){
      if(psumCal[i]>0) ans=max(ans, i+1);
      else{
        if(um.find(psumCal[i]-1) != um.end()){
          ans=max(ans, i-um[psumCal[i]-1]);  
        }
        if(um.find(psumCal[i]) != um.end()){
          continue;  
        }

        um[psumCal[i]]=i;
      }
    }    

    return ans;
  }
};