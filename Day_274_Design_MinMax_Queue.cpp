#include <bits/stdc++.h>
using namespace std;

// Problem: Design a queue that supports enqueue, dequeue, getFront, getMin, and getMax operations in O(1) time.
// Approach: Use a standard queue to maintain the order of elements and a map to keep track of the frequency of each element. 
//           The map will allow us to efficiently retrieve the minimum and maximum elements.

// Steps:
// 1. Initialize a queue to maintain FIFO order and a map to track element frequencies
// 2. For enqueue: add element to queue back and increment its frequency in map
// 3. For dequeue: remove front element from queue and decrement its frequency, erase if count becomes 0
// 4. For getFront: return the front element of the queue without removing it
// 5. For getMin: return the first key from map (smallest due to automatic sorting)
// 6. For getMax: return the last key from map (largest due to automatic sorting)

// Time Complexity: O(1) for each operation
// Space Complexity: O(n) where n is the number of elements in the queue

class SpecialQueue {
  public:
    map<int,int>mp;
    queue<int>q;
    
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        mp[x]++;
    }

    void dequeue() {
        // Remove element from the queue
        int fr=q.front();q.pop();
        mp[fr]--;
        if(mp[fr] == 0) mp.erase(fr);
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return mp.begin()->first;
    }

    int getMax() {
        // Get maximum element
        return (--mp.end())->first;
    }
};  