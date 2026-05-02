#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers, count the number of increasing subarrays in the array. An increasing subarray is a contiguous subarray where each element is greater than the previous one.
Approach: We can use a two-pointer approach to count the increasing subarrays. We can maintain two pointers, left and right, to represent the current subarray. We can iterate through the array and whenever we find an increasing pair of elements, we can calculate the number of increasing subarrays that can be formed with the current right pointer and add it to the count. If we find a non-increasing pair, we can move the left pointer to the right of the current right pointer.

Steps:
1. Initialize two pointers, left and right, to 0, and a variable count to 0.
2. Iterate through the array with the right pointer:
    a. If arr[right] is greater than arr[right - 1], it means we can form increasing subarrays with the current right pointer. The number of such subarrays is (right - left), so we add this to the count.
    b. If arr[right] is not greater than arr[right - 1], it means the increasing sequence has been broken, so we move the left pointer to right.
3. Return the count of increasing subarrays.

Time Complexity: O(n) - We traverse the array once with the right pointer, and the left pointer only moves forward, so the overall time complexity is linear.
Space Complexity: O(1) - We use only a constant amount of extra space for the pointers and the count variable.
*/

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n=arr.size();
        if(n<2) return 0;
        int left=0, right=1, cnt=0;
        while(right<n){
            if(arr[right-1]<arr[right])
                cnt+=(right-left);
            else
                left=right;
            right++;
        }
        return cnt;
    }
};