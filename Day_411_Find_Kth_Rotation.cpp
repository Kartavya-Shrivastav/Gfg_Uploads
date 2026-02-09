#include <bits/stdc++.h>
using namespace std;

// Problem: Given a sorted and rotated array, find the number of times it has been rotated.
// Approach: We can iterate through the array and count the number of times the current element is greater than the next element. The count will give us the number of rotations. If we find such a case, we can break out of the loop as we only need to count until the first occurrence of this condition.

// Steps:
// 1. Initialize count to 0 and flag to 0.
// 2. Iterate through the array from the first element to the second last element.
// 3. For each element, compare it with the next element. If the current element is greater than the next element, increment the count and set the flag to 1, then break out of the loop.
// 4. If the flag is still 0 after the loop, it means the array is not rotated, so return 0. Otherwise, return the count.
// 5. Return the count of rotations found after iterating through the array.

// Time Complexity: O(n) for iterating through the array once.
// Space Complexity: O(1) as we are using only a constant amount of extra space

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int count = 0, flag=0;
        
        for(int i=0; i<n-1; i++){
            count++;
            if(arr[i] > arr[i+1]){
                flag = 1;
                break;
            }   
        }
        
        return flag==1? count: 0;
    }
};