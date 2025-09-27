#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate Deque By K
// Approach: Using Deque operations to rotate elements

// Steps:
// 1. Check the type of rotation (1 for right, 0 for left).
// 2. For right rotation, repeatedly remove the last element and add it to the front.
// 3. For left rotation, repeatedly remove the first element and add it to the back.
// 4. Continue this process k times to achieve the desired rotation.
// 5. The deque is modified in place, so no need to return anything.
// 6. Ensure to handle edge cases where k is greater than the size of the deque.

// Time Complexity: O(k)
// Space Complexity: O(1)


class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        if(type == 1) {
            while (k != 0) {
                dq.addFirst(dq.removeLast());
                k--;
            }
        }else {
            while (k != 0){
                dq.addLast(dq.removeFirst());
                k--;
            }
        }
        
    }
}