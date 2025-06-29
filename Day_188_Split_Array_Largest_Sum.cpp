#include <bits/stdc++.h>
using namespace std;

// Problem: Split Array Largest Sum
// Approach: Use binary search to find the minimum largest sum possible when splitting the array into k subarrays.

// Steps:
// 1. Define a helper function `f` that checks if it is possible to split the array into k subarrays with a maximum sum of `sum`.
// 2. Initialize the search range for the binary search: `s` as the maximum element in the array and `e` as the sum of all elements.
// 3. Perform binary search:
//    - Calculate the mid-point of the current range.
//    - If it is possible to split the array with the current mid as the maximum sum, update the answer and search in the left half (to minimize the largest sum).
//    - If it is not possible, search in the right half (to increase the largest sum).
// 4. Return the answer which is the minimum largest sum possible.

// Time Complexity: O(n log(sum)), where n is the number of elements in the array and sum is the total sum of the array.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
    public:
        // Helper function to check if it's possible to split the array into k or fewer subarrays
        // such that the largest sum among these subarrays is less than or equal to 'sum'.
        bool f(int sum , vector<int>& arr, int k){
             int s = 0 ; 
             for(int i : arr){
                     s += i ;
                     // If adding the current element exceeds 'sum', start a new subarray
                     if(s > sum){
                             k -- ; // Use one split
                             s = i ; // Start new subarray with current element
                     }
             }
             // Return true if we can split into k or fewer subarrays and the last subarray sum is valid
             return (k > 0 && s <= sum) ;
        }
        
        // Main function to find the minimum largest sum when splitting the array into k subarrays
        int splitArray(vector<int>& arr, int k) {
                // The minimum possible largest sum is the max element
                int s = *max_element(arr.begin(), arr.end()) ; 
                // The maximum possible largest sum is the sum of all elements
                int e = accumulate(arr.begin() , arr.end() , 0) ;
                int ans = -1 ;
                // Binary search to find the minimum largest sum
                while(s <= e){
                        int mid = s + (e-s) / 2 ;
                        // If it's possible to split with 'mid' as the largest sum, try for a smaller value
                        if(f(mid , arr , k)){
                                ans = mid ;
                                e = mid - 1 ;
                        }
                        // Otherwise, try for a larger value
                        else{
                                s = mid + 1 ;
                        }
                }
                return ans ;
        }
};
