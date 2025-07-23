#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers and an integer k, partition the array into k subarrays such that the maximum sum of any subarray is minimized.
// Approach: Use binary search to find the minimum possible maximum sum of subarrays by checking if a given maximum sum can be achieved with k partitions.
// Steps:
// 1. Calculate the total sum of the array to set the upper bound for binary search
// 2. Set the lower bound as the maximum element in the array (since no subarray can have a sum less than the largest element).
// 3. Use binary search between the lower and upper bounds to find the minimum possible maximum sum.
// 4. For each mid value in the binary search, check if it is possible to partition the array into k subarrays without exceeding this mid value.
// 5. If it is possible, adjust the upper bound; otherwise, adjust the lower bound.

// Time Complexity: O(n log(sum)), where n is the number of elements in the array and sum is the total sum of the array.
// Space Complexity: O(1) — no additional space is used apart from a few variables.

class Solution {
  public:
    bool ispossible(vector<int>& arr, int k,int mid){
        int s=0;
        for(auto i:arr){
            s+=i;
            if(s>mid){
                k--; s=i;
                if(s>mid)return false;
            }
        }
        return k>0? true:false;
    }
  
    int minTime(vector<int>& arr, int k) {
        int sum=0;
        for(auto i:arr)sum+=i;
        int start=0,end=sum,mid;
        while(start<end){
             mid=(start+end)/2;
            
            if(ispossible(arr,k,mid)){
                end=mid;
            }
            else start=mid+1;
        }
        return end;
    }
};