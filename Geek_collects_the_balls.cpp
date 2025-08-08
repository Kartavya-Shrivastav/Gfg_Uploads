#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum number of balls that can be collected from two arrays
// Approach: Use two pointers to traverse both arrays and collect balls while handling duplicates.

// Steps:
// 1. Initialize two pointers for the two arrays and two sums to keep track of collected balls.
// 2. Compare the current elements of both arrays.
// 3. If the elements are equal, collect balls from both arrays, handling duplicates.
// 4. If the elements are not equal, add the smaller element's value to the corresponding sum and move the pointer.
// 5. Continue until one of the arrays is fully traversed.
// 6. Add any remaining elements from the non-empty array to its sum.
// 7. Return the maximum of the two sums.

// Time Complexity: O(n + m), where n and m are the lengths of the two arrays
// Space Complexity: O(1), as we are using only a few variables for sums and

class Solution {
  public:
    long long maxBalls(int n, int m, vector<int> a, vector<int> b) {
        int i = 0, j = 0;
        long long aSum = 0, bSum = 0, result = 0;
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                aSum += a[i++];
            } else if (a[i] > b[j]) {
                bSum += b[j++];
            } else {
                long long currSumA = 0,currSumB = 0,currVal = a[i];
                long long countA =0 ,countB=0;
                while (i < n-1 && a[i] == a[i + 1])
                {
                    countA++;
                    currSumA += a[i++];
                }
                while (j < m-1 && b[j] == b[j + 1]){
                    countB++;
                    currSumB += b[j++];
                }
                long long e1 = aSum+currSumA+currVal;
                if(countA>0) e1 = max(e1,aSum+currSumA+currSumB);
                e1 = max(e1,bSum+currSumA+currSumB+currVal);
                long long e2 = bSum+currSumB+currVal;
                if(countB>0) e2 = max(e2,bSum+currSumA+currSumB);
                e2 = max(e2,aSum+currSumA+currSumB+currVal);
                aSum = e1; bSum = e2;
                i++; j++;
            }
        }
        while (i < n) aSum += a[i++];
        while (j < m) bSum += b[j++];
        return max(aSum, bSum);
    }
};