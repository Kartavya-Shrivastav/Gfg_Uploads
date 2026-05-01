#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers and a target sum, find the total number of ways to assign '+' or '-' signs to the integers in the array such that their sum equals the target.  
Approach: We can use dynamic programming to solve this problem. We will maintain a map that keeps track of the number of ways to achieve a certain sum at each index of the array. We start with the base case for the first element, where we can either add or subtract it from the sum. For each subsequent element, we iterate through the existing sums in the map and update the counts for the new sums that can be achieved by adding or subtracting the current element.       

Steps:
1. Initialize a map to store the number of ways to achieve each sum at each index. Start with the base case for the first element.
2. For each element in the array from the second element to the end:
    a. For each existing sum in the map from the previous index, calculate the new sums by adding and subtracting the current element.
    b. Update the counts for these new sums in the map for the current index.
3. Finally, return the count of ways to achieve the target sum from the map for the last index.

Time Complexity: O(n * m) where n is the number of elements in the array and m is the range of possible sums (which can be up to the sum of absolute values of the elements).
Space Complexity: O(n * m) for the map storing the counts of sums at each index
*/

class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n=arr.size();
        map<int,map<int,int>> mp;
        mp[0][arr[0]]=1;
        mp[0][-arr[0]]=1;
        
        for(int i=1;i<n;i++) {
            for(auto &I:mp[i-1]) {
                mp[i][arr[i]+I.first]+=mp[i-1][I.first];
                mp[i][-arr[i]+I.first]+=mp[i-1][I.first];
            }
        }
        return mp[n-1][target];
    }
};