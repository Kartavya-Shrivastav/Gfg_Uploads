#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array consisting of only 0s, 1s, and 2s, sort the array in ascending order.
// Approach: Sorting an Array of 0s, 1s, and 2s Using the Dutch National Flag Algorithm | One Traversal Code.

// Steps:
// 1. Initialize three pointers: low, mid, and high.
// 2. Traverse the array with the mid pointer.
// 3. Depending on the value at arr[mid], swap elements to their correct positions: 
//    - If arr[mid] is 0, swap it with arr[low] and increment both low and mid.
//    - If arr[mid] is 1, just increment mid.
//    - If arr[mid] is 2, swap it with arr[high] and decrement high.
// 4. Continue this process until mid exceeds high.

// Time Complexity: O(n) as we traverse the array only once.
// Space Complexity: O(1) as we use only a constant amount of extra space.

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        
        // Initialize pointers
        int low = 0, mid = 0, high = n - 1;
        
        // Traverse the array using the Dutch National Flag Algorithm
        while (mid <= high) {
            switch(arr[mid]) {
                // Case when the element is 0
                case 0: 
                    swap(arr[low++], arr[mid++]);  // Swap 0 to the low region and move both pointers
                    break;
                
                // Case when the element is 1
                case 1: 
                    mid++;  // 1 is already in the correct region, so just move mid forward
                    break;
                
                // Case when the element is 2
                case 2: 
                    swap(arr[mid], arr[high--]);  // Swap 2 to the high region and move high backward
                    break;
            }
        }
    }
};