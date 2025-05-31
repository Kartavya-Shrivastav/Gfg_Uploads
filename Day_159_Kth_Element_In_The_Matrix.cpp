#include<bits/stdc++.h>
using namespace std;

/*
This code defines a Solution class with a method to find the kth smallest element in a sorted matrix.
The matrix is sorted row-wise and column-wise.
The algorithm uses binary search on the value range between the smallest and largest elements in the matrix.
For each mid value, it counts how many elements in the matrix are less than or equal to mid using upper_bound.
If the count is at least k, it narrows the search to the left half; otherwise, to the right half.
The answer is updated accordingly.
*/
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
         int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        int ans = -1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            int cnt = 0;
            
            for(vector <int>& arr: matrix){
                cnt += upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            }
            
            if(cnt >= k){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return ans;
    }
};