#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers and a range [low, high], return a list of all the integers in the range that are not present in the array.
// Approach: We can create a boolean array of size (high - low + 1) to keep track of which integers in the range are present in the input array. We will iterate through the input array and mark the corresponding indices in the boolean array for each integer that falls within the range. Finally, we will iterate through the boolean array and collect all the integers that are not marked as present, which will be our answer.

// Steps:
// 1. Create a boolean array of size (high - low + 1) initialized to false.
// 2. Iterate through the input array and for each integer that falls within the range [low, high], mark the corresponding index in the boolean 
//    array as true.
// 3. Iterate through the boolean array and collect all the integers that are still false, which means they are missing from the input array, and 
//    add them to the answer list.  
// 4. Return the answer list.

// Time Complexity: O(n + m) where n is the size of the input array and m is the size of the range (high - low + 1). The iteration through the input array takes O(n) and iterating through the boolean array takes O(m).
// Space Complexity: O(m) where m is the size of the range (high - low

class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
           int n =arr.size();
           vector<int> s(high-low+1,0);

           for(int i:arr){
                if(i<low || i>high) continue;                
                int idx =i-low;
                s[idx]=1;
           }
           
           vector<int> ans;
           for(int i=0;i<s.size();i++){
                 if(s[i]==0){
                      ans.push_back(low+i);
                 }
           }
           
           return ans;
               
    }
};