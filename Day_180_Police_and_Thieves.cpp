#include <bits/stdc++.h>
using namespace std;

// Problem: Police and Thieves
// Approach: Use two-pointer technique to match each police with the nearest thief within distance k.

// Steps:
// 1. Create two vectors to store the indices of police and thieves.
// 2. Iterate through the array and fill the vectors.
// 3. Use two pointers to match police with thieves within the given distance k.
// 4. Count the number of successful catches and return the result.

// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(n) for storing indices of police and thieves.

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int>p, t;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 'P') p.push_back(i);
            else t.push_back(i);
        }
        
        int ans  = 0;
        int st = 0;
        for(int i=0; i<t.size(); i++){
            while(st < p.size()){
                int low = t[i] - k;
                int high = t[i] + k;
                if(p[st] <= high && p[st] >= low){
                    ans++;
                    st++;
                    break;
                }
                else if(p[st] < low){
                    st++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};