#include <bits/stdc++.h>
using namespace std;

// Problem: Given a number line from 0 to n, with ants moving left and right, find the last moment before all ants fall off the line. 
// Approach: Calculate the maximum time taken for ants moving left to fall off from the left end (0) and for ants moving right to fall off from the right end (n). The answer is the maximum of these two times.

// Steps:
// 1. Initialize two variables l and r to store the maximum time for ants moving left and right respectively.
// 2. Iterate through the left array to find the maximum position of ants moving left (l).  
// 3. Iterate through the right array to find the maximum time for ants moving right to fall off (r) by calculating n - position for each ant.
// 4. Return the maximum of l and r as the result.

// Time Complexity: 
// Space Complexity: 

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l =0, r=0;
        
        for(int i=0;i<left.size();i++)
            l = max(l,left[i]);
            
        
        for(int i=0;i<right.size();i++)
            r = max(r,n-right[i]);
        
        
        return max(l,r);
    }
};