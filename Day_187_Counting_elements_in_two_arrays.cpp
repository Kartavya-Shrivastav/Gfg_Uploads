#include <bits/stdc++.h>
using namespace std;

// Problem: Counting Elements in Two Arrays
// Approach: Use a frequency array to count occurrences of elements in the second array,
// then compute the cumulative counts to answer queries for elements in the first array.

// Steps:
// 1. Create a frequency array to count occurrences of each element in the second array.
// 2. Compute cumulative counts in the frequency array.
// 3. For each element in the first array, retrieve the count of elements less than or equal to it.
// 4. If the element is greater than the maximum element in the second array, return the count for the maximum element.
// 5. Return the results as a vector.

// Time Complexity: O(n + m), where n is the size of the first array and m is the size of the second array.
// Space Complexity: O(m), for the frequency array.

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int mx=*max_element(begin(b),end(b));
        vector<int>arr(mx+1);
        for(int i:b){
            arr[i]++;
        }
        for(int i=0;i<mx+1;i++){
            arr[i]+=arr[i-1];
        }
        vector<int>ans;
        for(int i:a){
           int x=i>=mx?arr[mx]:arr[i];
           ans.push_back(x);
        }
        return ans;
    }
};