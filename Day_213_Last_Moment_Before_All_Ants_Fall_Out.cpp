#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a plank of length n, and two arrays representing the positions of ants moving left and right, find the last moment before all ants fall off the plank.
// Approach: The last moment before all ants fall off the plank is determined by the furthest distance any ant has to travel to fall off, either from the left or right end of the plank.

// Steps:
// 1. For ants moving left, find the maximum position of any ant.
// 2. For ants moving right, find the maximum distance from the right end of the plank.
// 3. The last moment is the maximum of these two values.
// 4. Return the maximum of the two values as the result.

// Time Complexity: O(n), where n is the number of ants.
// Space Complexity: O(1) — no additional space is used apart from a few variables.

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