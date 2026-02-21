#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers representing the number of citations for each paper, find the H-Index. The H-Index is defined as the maximum value of h such that the given author has published h papers that have each been cited at least h times.
// Approach: We can iterate through possible values of h from 1 to the size of the array. For each value of h, we count how many papers have at least h citations. If the count is greater than or equal to h, we can update our answer. Finally, we return the maximum h that satisfies this condition.

// Steps:
// 1. Initialize a variable ans to store the H-Index.
// 2. Iterate through possible values of h from 1 to the size of the input array.
// 3. For each value of h, count how many papers have at least h citations.
// 4. If the count is greater than or equal to h, update ans to h.
// 5. Return ans as the final H-Index.

// Time Complexity: O(n^2) in the worst case, where n is the number of papers. This is because for each value of h, we may need to iterate through the entire array to count the papers.
// Space Complexity: O(1) since we are using only a constant amount of extra space.

class Solution {
  public:
    int hIndex(vector<int>& arr) {
        int ans=0;
        for(int i=1; i<=arr.size(); i++){
            int count=0;
            for(int x: arr){
                if(x >= i) count++;
            }
            
            if(count >= i) ans++;
        }

        return ans;
    }
};