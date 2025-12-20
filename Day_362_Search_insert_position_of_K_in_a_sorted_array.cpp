#include <bits/stdc++.h>
using namespace std;

// Problem: Function to find the insert position of K in a sorted array
// Approach: Binary Search

// Steps:
// 1. Initialize two pointers, start and end, to the beginning and end of the array.
// 2. While start is less than or equal to end:
//    a. Calculate mid as the average of start and end.
//    b. If the middle element is less than K, move the start pointer to mid + 1.
//    c. Otherwise, move the end pointer to mid - 1.
// 3. When the loop ends, start will be at the correct insert position for K.
// 4. Return the start index.

// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int start = 0, end = arr.size()-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < k) { 
                start = mid + 1;
            } else { 
                end = mid - 1; 
            }
        }
        return start;
    }
};