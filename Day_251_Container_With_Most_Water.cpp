#include <bits/stdc++.h>
using namespace std;

// Problem: Container With Most Water
// Approach: Using Two Pointer approach to find maximum area between two heights by moving pointers based on smaller height.

// Steps:
// 1. Initialize two pointers, left and right, at the beginning and end of the array.
// 2. Calculate the area formed between the two heights at the left and right pointers.
// 3. Update the maximum area found so far.
// 4. Move the pointer pointing to the shorter height inward, hoping to find a taller height.
// 5. Repeat steps 2-4 until the two pointers meet.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int res = 0;
        while(left < right) {
            int water = min(arr[left], arr[right]) * (right - left);
            res = max(res, water);
          
            if(arr[left] < arr[right])
                left += 1;
            else
                right -= 1;
        }
      
        return res;
    }
};