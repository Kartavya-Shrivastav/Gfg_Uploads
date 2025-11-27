#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, return the sum of all XOR totals for every subset of the array.
// Approach: The XOR of all subsets can be derived from the OR of all elements in the array.

// Steps:   
// 1. Initialize a variable s to store the OR of all elements.
// 2. Iterate through each element in the array and update s using the bitwise OR operation.
// 3. The total number of subsets of an array of size n is 2^n.
// 4. The sum of all XOR totals for every subset is given by s multiplied by 2^(n-1).
// 5. Return the computed sum.

// Time Complexity: O(n) where n is the number of elements in the array, as we need to iterate through the array once.
// Space Complexity: O(1) since we are using a constant amount of extra space.

class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n=arr.size();
        int s=0;
        for(auto it:arr){
            s|=it;
        }
        return s*pow(2,n-1);
    }
};