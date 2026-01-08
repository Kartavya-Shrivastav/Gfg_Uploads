#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers and an integer k, count the number of subarrays with exactly k odd numbers.    
// Approach: Two Pointers / Sliding Window

// Steps:
// 1. Use two pointers to maintain a window that contains at most k odd numbers 
// 2. Iterate through the array, expanding the right pointer and counting odd numbers
// 3. When the count of odd numbers exceeds k, move the left pointer to reduce the count
// 4. For each position of the right pointer, count the number of valid subarrays that can be formed with exactly k odd numbers and
//    add to the result
// 5. Return the total count of such subarrays

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(1) as we are using only a constant amount of extra space

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        int n=arr.size(),ans=0,cnt=0,last=0,j=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2){
                cnt++;
                last=0;
            }
            //
            while(j<=i && cnt>=k){
                if(arr[j]%2){
                    cnt--;
                }
                j++;
                last++;
            }
            //
            ans+=last;
        }
        //
        return ans;
    }
};