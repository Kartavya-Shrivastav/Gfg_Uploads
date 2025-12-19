#include <bits/stdc++.h>
using namespace std;

// Problem: Given the positions of chairs and passengers, find the minimum number of moves required to seat all passengers.
// Approach: Sort both the chairs and passengers positions, then calculate the sum of absolute differences between corresponding positions.

// Steps:
// 1. Sort the array of chair positions.
// 2. Sort the array of passenger positions.
// 3. Initialize a result variable to store the total moves.
// 4. Iterate through both arrays, calculating the absolute difference between each pair of positions and adding it to the result.
// 5. Return the total moves required.

// Complexity Analysis:
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) if sorting in place

class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        
        int res = 0;
        
        for(int i=0;i<chairs.size();i++){
            res += abs(chairs[i]-passengers[i]);
        }
        
        return res;
    }
};