#include <bits/stdc++.h>
using namespace std;

// Problem: Kth Missing Positive Number in a Sorted Array
// Approach: Binary Search

// Steps:
// 1. Use binary search to find the position where the count of missing numbers is less than k.
// 2. Calculate the kth missing number based on the position found.
// 3. Return the kth missing positive number.

// Time Complexity: O(log N) where N is the size of the array
// Space Complexity: O(1) additional space

class Solution {
  public:
     int kthMissing(vector<int> &arr, int k) {
        int n=arr.size();
        int left=0,right=n-1,mid;
        if(arr[0]>k){
            return k;
        }
        while(left<=right){
            mid=(left+right)/2;
            if((arr[mid]-(mid+1))<k){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        if(right==-1){
            return k;
        }
        return arr[right]+(k-(arr[right]-(right+1)));
    }
};