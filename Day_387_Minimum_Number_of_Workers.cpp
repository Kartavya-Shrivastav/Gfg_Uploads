#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array where each element represents the maximum distance a worker can cover from their position, determine the minimum number of workers needed to cover the entire area from start to end. If it's not possible to cover the entire area, return -1.
// Approach: We use a greedy strategy to always extend our coverage as far as possible with the available workers. We maintain the farthest point we can reach at each step and count the number of workers used.

// Steps:
// 1. Create an auxiliary array to store the farthest reach for each starting position. 
// 2. Iterate through the input array to fill this auxiliary array.
// 3. Use a greedy approach to count the minimum number of workers needed to cover the entire area.
// 4. If at any point we cannot extend our coverage, return -1.

// Time Complexity: O(N) where N is the number of positions.
// Space Complexity: O(N) for the auxiliary array.

class Solution {
  public:
    int minMen(vector<int>& arr) {
        vector<int>v(100010 , -1);
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] == -1)
                continue;
            int l = max(0 , i - arr[i]);
            int r = min(n - 1 , i + arr[i]);
            v[l] = max(v[l] , r);
        }
        if(v[0] == -1)
            return -1;
        int curr = v[0] , cnt = 1;
        int j = 1;
        while(curr < n - 1){
            int maxi = v[curr + 1];
            while(j <= curr)
                maxi = max(maxi , v[j++]);
            if(maxi <= curr)
                return -1;
            curr = maxi;
            cnt++;
        }
        return cnt;
    }
};