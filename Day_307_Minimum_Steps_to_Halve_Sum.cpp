#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of positive integers, determine the minimum number of operations required to reduce the sum of the array by at least half.
// In each operation, you can choose any element from the array and halve its value.

// Approach: Use a max-heap (priority queue) to always halve the largest element in the array, as this will yield the maximum reduction in sum per operation.

// Steps:
// 1. Calculate the initial sum of the array.
// 2. Initialize a max-heap and insert all elements of the array into it.   
// 3. Set a target sum which is half of the initial sum.
// 4. While the current sum is greater than the target sum:
//    - Extract the largest element from the max-heap.
//    - Halve this element and update the current sum.
//    - Push the halved element back into the max-heap.
//    - Increment the operation count.
// 5. Return the operation count once the sum is reduced to the target or below.

// Time Complexity: O(n log n) due to the heap operations for n elements.
// Space Complexity: O(n) for storing elements in the max-heap.

class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq;
        double sum = 0;
        for (int it : arr) {
            pq.push(it);
            sum += it;
        }
        double req = sum / 2.0;
        int cnt = 0;
        while (sum > req) {
            double top = pq.top();
            pq.pop();
            sum -= top;
            top /= 2.0;
            sum += top;
            pq.push(top);
            cnt++;
        }
        return cnt;
    }
};