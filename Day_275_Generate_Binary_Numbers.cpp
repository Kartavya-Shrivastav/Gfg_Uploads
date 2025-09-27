#include <bits/stdc++.h>
using namespace std;    

// Problem: Generate Binary Numbers
// Approach: Using a queue to generate binary numbers in sequence

// Steps:
// 1. Initialize a queue to store the binary numbers as strings.
// 2. Start with the first binary number "1" and push it into the queue.
// 3. Use a loop to generate binary numbers until we reach the desired count n.
// 4. In each iteration, pop the front element from the queue, add it to the result list,
//    and then generate the next two binary numbers by appending "0" and "1" to the current number.
// 5. Push these new binary numbers back into the queue.
// 6. Continue this process until we have generated n binary numbers.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    vector<string> generateBinary(int n) {
           vector<string> v={"1"};
        for(int i=1,j=0,x=0;i<n;i++){
            v.push_back(v[j] + to_string(x));
            x^=1;
            if(x==0) j++;
        }
        return v;
    }
};