#include <bits/stdc++.h>
using namespace std;

// Steps:
// 1. Use sliding window approach to maintain a window of size k
// 2. Calculate the XOR of elements in the current window
// 3. Update the maximum XOR found so far
// 4. Slide the window by removing the element going out of the window and adding the new element coming into the window
// 5. Return the maximum XOR found

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(1) as we are using only a constant amount of extra space

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
      int answer=INT_MIN;
      int first=0;
      int second=0;
      int temp=0;
      
      while(second<arr.size())
      {   
         temp= temp^arr[second];
         
         if(second-first+1 ==k)
         {
            answer = max(temp,answer);
             
             // ab temp me se use hatana padega 
             temp= temp^arr[first];
             first++;
         }
         second++;
          
          
      }
      return answer;
        
    }
};