#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Sum Rectangle in a 2D Matrix
// Approach: Use Kadane's algorithm to find the maximum sum subarray for each column range.

// Steps:
// 1. Iterate over all pairs of columns (left and right).
// 2. For each pair, create a temporary array that sums the values of the rows between these two columns.
// 3. Apply Kadane's algorithm on this temporary array to find the maximum sum subarray.
// 4. Keep track of the maximum sum found across all pairs of columns.
// 5. Return the maximum sum found.

// Time Complexity: O(N^2 * M), where N is the number of rows and M is the number of columns in the matrix.
// Space Complexity: O(N), for the temporary array used in Kadane's algorithm.

class Solution {
    private:
    int kadansAlgorithm(vector<int> &temp){
        int sum=0;
        int maxi= INT_MIN;
        for (int i=0; i<temp.size(); i++){
            sum+= temp[i];
            maxi= max(sum, maxi);
            if(sum<0)
            sum= 0;
        }
        return maxi;
    }

    public:
    int maxRectSum(vector<vector<int>> &mat) {
        int maxRectangle= INT_MIN;
        for (int left=0; left<mat[0].size(); left++){
            vector<int> temp(mat.size(), 0);
            for (int right=left; right<mat[0].size(); right++){
                for (int i=0; i<mat.size(); i++){
                    temp[i]+= mat[i][right];
                }
                
                int currSum= kadansAlgorithm(temp);
                maxRectangle= max(maxRectangle, currSum);
                
            }
        }

        return maxRectangle;    
    }
};