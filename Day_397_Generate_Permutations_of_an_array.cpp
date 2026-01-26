#include <bits/stdc++.h>
using namespace std;

// Problem: Generate Permutations of an Array
// Given an array of distinct integers, write a function to generate all possible permutations of the array.
// Approach: Use backtracking to generate permutations by swapping elements.    

// Steps:
// 1. Define a helper function that takes the current index and the array.  
// 2. If the current index equals the size of the array, add the current permutation to the result list.
// 3. Iterate through the array, swapping the current index with each subsequent index to generate new permutations.
// 4. Recursively call the helper function with the next index.
// 5. Backtrack by swapping the elements back to their original positions.
// 6. Return the list of all permutations.

// Time Complexity: O(N * N!) where N is the number of elements in the array. There are N! permutations and generating each permutation takes O(N) time.
// Space Complexity: O(N!) to store all the permutations.

class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> ans; 
        backtrack(arr, 0, ans); 
        return ans;
    }
    
    void backtrack(vector<int>& arr, int idx, vector<vector<int>>& ans) { 
        if (idx == arr.size()) { 
            ans.push_back(arr); 
            return; 
        } 
        for (int i = idx; i < arr.size(); i++) { 
            swap(arr[idx], arr[i]); 
            backtrack(arr, idx + 1, ans); 
            swap(arr[idx], arr[i]); 
        } 
    }
};