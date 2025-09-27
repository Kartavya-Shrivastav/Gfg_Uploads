#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum K Consecutive Bit Flips
// Approach: We can use a queue to keep track of the indices where we perform the flips.

// Steps:
// 1. Initialize a queue to keep track of the indices where flips are performed.
// 2. Iterate through the array and for each element, check if it needs to be flipped based on the current state of the queue.
// 3. If the current bit is 0 (after considering the flips), we need to perform a flip operation starting from this index.
// 4. If we perform a flip, we add the index of the end of the flip operation to the queue.
// 5. If at any point we cannot perform a flip (i.e., if the remaining elements are less than k), return -1.
// 6. Finally, return the total number of flip operations performed.

// Time Complexity: O(n)
// Space Complexity: O(k)
class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n=arr.size();
        queue<int> q;
        int operation=0;
        for(int i=0;i<n;i++){
           if(!q.empty() && i==q.front())q.pop();
           int bit=arr[i];
           if(!q.empty() && q.size()%2==1)bit^=1;//if odd size->change the bit
           if(bit==0){
               if(i+k>n)return -1;
               operation++;
               q.push(i+k);
           }
        }
        return operation;
    }
};