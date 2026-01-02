#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array consisting of only 0s, 1s, and 2s, sort the array in ascending order.
// Approach: Count the number of 0s, 1s, and 2s, then overwrite the array based on these counts.

// Steps:
// 1. Initialize three counters for 0s, 1s, and 2s.
// 2. Traverse the array and update the counters based on the elements.
// 3. Overwrite the original array using the counts of 0s, 1s, and 2s.
// 4. Return the sorted array.

// Time Complexity: O(N), where N is the size of the array.
// Space Complexity: O(1)

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero=0;
        int one=0;
        int two=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)zero++;
            else if(arr[i]==1)one++;
            else if(arr[i]==2)two++;
        } 
        for(int i=0;i<arr.size();i++){
            if(zero){
                arr[i]=0;
                zero--;
            }
            else if(one){
                arr[i]=1;
                one--;
            }
            else if(two){
                arr[i]=2;
                two--;
            }
        }
        
    }
};