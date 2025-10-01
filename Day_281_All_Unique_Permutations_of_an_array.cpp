#include <bits/stdc++.h>
using namespace std;

// Problem: All Unique Permutations of an array
// Approach: We can use backtracking to generate all permutations and a set to store only unique ones.

// Steps:
// 1. Define a recursive function that generates permutations by swapping elements.
// 2. When a permutation is formed (i.e., when the current index reaches the size of the array), insert it into a set to ensure uniqueness.
// 3. After generating all permutations, convert the set to a vector and return it.
// 4. Use swapping to backtrack and explore other permutations.
// 5. Finally, return the vector of unique permutations.

// Time Complexity: O(n! * n) in the worst case (for generating all permutations and copying them)
// Space Complexity: O(n! * n) for storing all unique permutations

class Solution {
  public:
    set<vector<int>> res;
    void recur(int i,vector<int> &arr){
        if(i == arr.size()){
            res.insert(arr);
            return;
        }
        for(int j =i;j< arr.size();j++){
            swap(arr[i],arr[j]);
            recur(i+1,arr);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        recur(0,arr);
        return vector<vector<int>> (res.begin(),res.end());
    }
};