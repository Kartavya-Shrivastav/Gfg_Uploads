#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given two binary arrays of same size, find the length of longest span (i, j) where j >= i such that the sum of elements from i to j is same in both arrays.  
Approach: We can use a hash map to store the cumulative difference of the sums of the two arrays. We iterate through both arrays simultaneously, calculating the cumulative difference at each index. If we encounter the same cumulative difference again, it means that the sum of elements from the previous index to the current index is the same in both arrays. We can then calculate the length of this span and update our maximum length accordingly.

// Steps:
1. Initialize a hash map to store the cumulative differences and their corresponding indices.
2. Initialize a variable to keep track of the cumulative difference and a variable to store the maximum length of the span.
3. Iterate through both arrays simultaneously:
   a. Update the cumulative difference by adding the difference of the current elements from both arrays.
   b. If the cumulative difference is already in the hash map, calculate the length of the span from the previous index to the current index and update the maximum length if necessary.
   c. If the cumulative difference is not in the hash map, add it with the current index.
4. Return the maximum length of the span found.

// Time Complexity: O(n) where n is the size of the input arrays.
// Space Complexity: O(n) in the worst case, if all cumulative differences are unique and

*/

class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // Code here.
         int n=a1.size();
        unordered_map<int, int>mpp;
        int sum=0;
        int maxi=0;
        
        mpp[0]=-1;
        
        for(int i=0; i<n; i++){
            sum+=(a1[i]-a2[i]);
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi, i-mpp[sum]);
            }else mpp[sum]=i;
        }
        
        return maxi;
    }
};