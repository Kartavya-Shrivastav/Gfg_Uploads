#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers, find the length of the longest subarray that contains at most two distinct integers.
Approach: We can use the sliding window technique to solve this problem. We maintain a window defined by two pointers, `first` and `second`, which represent the start and end of the current subarray. We also use an unordered map to keep track of the count of each integer in the current window. As we expand the window by moving the `second` pointer, we add the current integer to the map and check if the size of the map exceeds 2. If it does, we need to shrink the window from the left by moving the `first` pointer until we have at most two distinct integers in the window. During this process, we update our maximum length whenever we have a valid window.

Steps:
1. Initialize two pointers, `first` and `second`, to the start of the array.
2. Initialize a variable `MAX` to store the maximum length of the valid subarray found so far.
3. Create an unordered map `m` to keep track of the count of each integer in the current window.
4. While `second` is less than the size of the array:
    a. Add the current integer at `second` to the map and increment its count.
    b. If the size of the map exceeds 2, it means we have more than two distinct integers in the window. In this case, we need to shrink the window from the left:
        i. Decrement the count of the integer at `first` in the map.
        ii. If the count of that integer becomes 0, remove it from the map.
        iii. Move the `first` pointer to the right.
    c. If the size of the map is less than or equal to 2, update `MAX` with the maximum length of the current valid window (which is `second - first + 1`).
    d. Move the `second` pointer to the right.
5. Return the value of `MAX` as the length of the longest subarray with at most two distinct integers.

Time Complexity: O(n), where n is the number of elements in the input array. We traverse the array at most once with the `second` pointer, and the `first` pointer also moves at most n times.
Space Complexity: O(1), as the unordered map will contain at most 3 distinct integers (when we exceed the limit of 2, we remove one), so it uses constant space.
*/

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int first=0,second=0;
        int MAX=0;
        unordered_map<int,int>m;
        while(second<arr.size()){
            m[arr[second]]++;
            if(m.size()>2){
                m[arr[first]]--;
                if(m[arr[first]]==0)m.erase(arr[first]);
                first++;
            }
            if(m.size()<=2)MAX=max(MAX,second-first+1);
        
            second++;
        }
        return MAX;
    }
};