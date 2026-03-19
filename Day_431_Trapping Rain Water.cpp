#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers representing the height of bars, compute how much water can be trapped between the bars after it rains.
Approach: We can use two pointers, one starting from the left and the other from the right. We keep track of the maximum height of bars seen so far from both ends. If the left bar is shorter than the right bar, we check if the left bar can trap water by comparing it with the maximum height seen from the left. If it can trap water, we add the difference to our total. Otherwise, we update the maximum height from the left. We then move the left pointer to the right. If the right bar is shorter than or equal to the left bar, we do a similar process for the right side and move the right pointer to the left. We continue this process until the two pointers meet.

Steps:
1. Initialize two pointers, `l` and `r`, to the start and end of the array, respectively.
2. Initialize two variables, `lmax` and `rmax`, to keep track of the maximum height of bars seen so far from the left and right, respectively.
3. Initialize a variable `total` to store the total amount of water trapped.
4. While `l` is less than `r`:
   a. If the height of the left bar is less than the height of the right bar:
      i. If `lmax` is greater than the height of the left bar, add the difference to `total`.
      ii. Otherwise, update `lmax` to the height of the left bar.
      iii. Move the left pointer to the right.
   b. Else:
      i. If `rmax` is greater than the height of the right bar, add the difference to `total`.
      ii. Otherwise, update `rmax` to the height of the right bar.
      iii. Move the right pointer to the left.
5. Return the total amount of water trapped.

Time Complexity: O(n), where n is the number of bars in the input array. We traverse the array at most once.
Space Complexity: O(1), as we are using only a constant amount of extra space for variables to keep track of the maximum heights and total water trapped.
*/

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        int lmax=0, rmax=0, total=0;
        int l=0, r=n-1;

        while(l<r){
          if(arr[l]<arr[r]){
            if(lmax>arr[l]){
              total+=lmax-arr[l];
            }else{
              lmax=arr[l];
            }
            l++;
          }else{
            if(rmax>arr[r]){
              total+=rmax-arr[r];
            }else{
              rmax=arr[r];
            }
            r--;
          }
        }

        return total;        
    }
};