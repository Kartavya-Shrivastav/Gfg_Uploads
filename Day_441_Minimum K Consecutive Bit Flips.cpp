#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary array arr and an integer k, return the minimum number of K-bit flips required to flip all bits in the array to 1. If it is not possible, return -1. A K-bit flip is defined as choosing a subarray of length K and simultaneously flipping all bits in the subarray (i.e., changing 0 to 1 and 1 to 0).
Approach: We can use a queue to keep track of the indices of the K-bit flips. We will iterate through the array and for each element, we will check if it is 0 or 1. If it is 0, we will check if we can perform a K-bit flip starting from that index. If we can, we will increment the operation count and push the index of the end of the K-bit flip into the queue. If we cannot perform a K-bit flip, we will return -1. If the element is 1, we will check if there are any K-bit flips in the queue that have ended before the current index. If there are, we will pop them from the queue.

Steps:
1. Initialize a queue to keep track of the indices of the K-bit flips and a variable to count the number of operations.
2. Iterate through the array and for each element, check if it is 0 or 1.
3. If the element is 0, check if we can perform a K-bit flip starting from that index. If we can, increment the operation count and push the index of the end of the K-bit flip into the queue. If we cannot perform a K-bit flip, return -1.
4. If the element is 1, check if there are any K-bit flips in the queue that have ended before the current index. If there are, pop them from the queue.
5. Finally, return the operation count.

Time complexity of this approach is O(n) and the space complexity is O(k) because we are using a queue to store the indices of the K-bit flips, and at most, there can be k indices in the queue at any time.
Space complexity is O(k) because we are using a queue to store the indices of the K-bit flips, and at most, there can be k indices in the queue at any time.
*/
class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n=arr.size();
        queue<int> q;

        int operation=0;
        for(int i=0;i<n;i++){
           if(!q.empty() && i==q.front()) q.pop();
           
           int bit=arr[i];
           if(!q.empty() && q.size()%2==1) bit^=1;  //if odd size->change the bit
           
           if(bit==0){
               if(i+k>n)return -1;
               operation++;
               q.push(i+k);
           }
        }

        return operation;
    }
};