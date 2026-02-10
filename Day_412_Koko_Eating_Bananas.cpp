#include <bits/stdc++.h>
using namespace std;

// Problem: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours. Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead, and won't eat any more bananas during that hour. Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Approach: We can use binary search to find the minimum eating speed k. The minimum speed can be 1 banana per hour and the maximum speed can be the maximum number of bananas in any pile. We will check for each mid value of k if it is feasible to eat all bananas within h hours. If it is feasible, we will try to find a smaller k by moving the right pointer to mid. If it is not feasible, we will move the left pointer to mid + 1. Finally, the left pointer will point to the minimum k that allows Koko to eat all bananas within h hours.

// Steps:
// 1. Initialize left pointer to 1 and right pointer to the maximum number of bananas in any pile.
// 2. While left pointer is less than right pointer, calculate mid as the average of left and right pointers.
// 3. Check if it is feasible to eat all bananas with speed mid using the isfeasible function.
// 4. If it is feasible, move the right pointer to mid to try to find a smaller k.
// 5. If it is not feasible, move the left pointer to mid + 1 to try to find a larger k.
// 6. Return the left pointer as the minimum k that allows Koko to eat all bananas within h hours.

// Time Complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in any pile.
// Space Complexity: O(1) as we are using only a constant amount of extra space

class Solution {
  public:
    bool isfeasible(int mid,vector<int>&arr,int k){
        if(mid==0){
            return false;
        }
        int count=0;
        for(int i=0;i<arr.size();i++){
            count=count+(arr[i]/mid);
            if(arr[i]%mid){
                count++;
            }
        }
        if(count>k){
            return false;
        }
        return true;
    }
    int kokoEat(vector<int>& arr, int k) {
        const int n=arr.size();
        int j=0;
        
        for(int i=0;i<n;i++){
            j=max(j,arr[i]);
        }
        int i=0; 
        while(i<j){
            int mid=i+(j-i)/2;
            
            if(isfeasible(mid,arr,k)){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return j;
    }
};