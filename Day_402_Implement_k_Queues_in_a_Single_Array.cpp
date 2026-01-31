#include <bits/stdc++.h>
using namespace std;

// Problem: Implement k Queues in a Single Array
// Given an array of size n, implement k queues in it such that no queue overflows unless the entire array is full.
// Approach: Use an array of queues to manage multiple queues within a single array structure.  

// Steps:
// 1. Initialize an array of k queues.
// 2. Maintain a count of total elements across all queues to check for overflow.
// 3. Implement enqueue and dequeue operations for each queue.
// Time Complexity: O(1) for both enqueue and dequeue operations.
// Space Complexity: O(n) for storing the elements in the array.

class kQueues {
  public:
  int cnt, nn;
  vector<queue<int>>vq;
    kQueues(int n, int k) {
        cnt=0; nn=n;
        vq.resize(k);
    }

    void enqueue(int x, int i) {
        vq[i].push(x);
        cnt++;
    }

    int dequeue(int i) {
        if(vq[i].size()){
            int xx=vq[i].front(); vq[i].pop();
            cnt--; return xx;
        }
        return -1;
    }

    bool isEmpty(int i) {
       return !vq[i].size();
    }

    bool isFull() {
        return cnt==nn;
    }
};