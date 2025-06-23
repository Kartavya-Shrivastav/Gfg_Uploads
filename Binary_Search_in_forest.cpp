#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of tree heights and a target amount of wood, find the maximum height to cut the trees such that the collected wood equals the target amount.
// Approach: We can use binary search to find the maximum height at which we can cut the trees to collect exactly k units of wood.

// Steps:
// 1. Sort the array of tree heights.
// 2. Initialize binary search bounds: start as the minimum height and end as the maximum height.
// 3. While start is less than or equal to end, calculate the mid height.
// 4. Calculate the total wood collected if trees are cut at mid height.
// 5. If the collected wood equals k, return mid.
// 6. If the collected wood is less than k, move the end pointer to mid - 1.
// 7. If the collected wood is greater than k, move the start pointer to mid + 1.

// Time Complexity: O(n log m), where n is the number of trees and m is the range of heights.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        if(n==1)return tree[0]-k; // tree[0]>K given in the question
        sort(tree,tree+n);
        int start = tree[0],end = tree[n-1],mid = start + (end-start)/2;
        
        while(start<=end){
            
            int wood_collection = 0;
            for(int i=0;i<n;i++){
                if(tree[i]>mid){
                    wood_collection+=tree[i]-mid;
                }
            }
            
          if(wood_collection==k){
            return mid;
         }
            else if(wood_collection<k){
                 end = mid -1;
            }
            else{
            start = mid +1;
        }
            
            mid = start + (end-start)/2;
        }
        return -1;
    }
};