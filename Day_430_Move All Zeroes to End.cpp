#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers, move all the zeroes to the end of the array while maintaining the relative order of the non-zero elements. The operation should be done in-place without using extra space for another array.
Approach: We can use a two-pointer technique to solve this problem efficiently. We will maintain a pointer l that keeps track of the position where the next non-zero element should be placed. We will iterate through the array with another pointer i, and whenever we encounter a non-zero element, we will swap it with the element at pointer l and then increment l. This way, all non-zero elements will be moved to the front of the array in their original order, and all zeroes will be moved to the end.   

Steps:
1. Initialize a pointer l to 0, which will keep track of the position for the next non-zero element.
2. Iterate through the array with a pointer i from 0 to the end of the array:
    - If the current element arr[i] is non-zero, swap it with the element at pointer l (arr[l]) and increment l by 1.   
3. After the loop, all non-zero elements will be at the beginning of the array in their original order, and all zeroes will be at the end.  

Time Complexity: O(n), where n is the length of the array, since we are traversing the array once.
Space Complexity: O(1), since we are doing the operation in-place without using extra space for another array.
*/

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int l = 0, sizeOfArr = arr.size();
        for (int i = 0; i < sizeOfArr; i++) {
            if (arr[i]) {
                swap(arr[i], arr[l++]);
            }
        }
    }
};