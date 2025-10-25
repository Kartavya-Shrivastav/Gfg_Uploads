#include <bits/stdc++.h>
using namespace std;

// Problem: Determine if it's possible to split the array into subsequences of at least length k, where each subsequence consists of consecutive integers.

// Approach: Use a frequency map to count occurrences of each integer. Then, iterate through the sorted keys of the map to check if we can form 
//           subsequences of at least length k by ensuring that consecutive integers have sufficient counts to extend the subsequences.

// Steps:
// 1. Create a frequency map of the integers in the array.
// 2. Initialize variables to track the previous integer and its count, as well as the current length of consecutive subsequences.
// 3. Iterate through the sorted keys of the frequency map: 
//    - If the current integer is consecutive to the previous one and has the same count, increment the length of the current subsequence.
//    - Otherwise, reset the length to 1.
// 4. If at any point the length of the current subsequence reaches k, return true.
// 5. If the loop completes without finding a valid subsequence of length k, return false.

// Time Complexity: O(n log n) due to the sorting of unique elements in the map.
// Space Complexity: O(n) for the frequency map.

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        if(arr.size() < 2){
            return 1;
        }
        
        map<int,int>mp;
        
        for(auto&it:arr){
            mp[it]++;
        }
        
        
        int a = -1;
        int b = -1;
        
        int len = 1;
        
        for(auto&[f,s]:mp){
            if((a != -1) && (f - a == 1) && (s == b)){
                len++;
            }else{
                len = 1;
            }
            
            a = f;
            b = s;
            
            if(len >= k){
                return 1;
            }
        }
        
        return 0;
    }
};
D