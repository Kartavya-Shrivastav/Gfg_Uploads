#include <bits/stdc++.h>
using namespace std;

// Problem: Given a non-negative integer represented as a string, remove k digits from the number so that the new number is the smallest possible.
// Approach: We can use a stack-like approach to build the smallest number by iterating through the digits. For each digit, we compare it with the top of the stack (the last digit added to our result). If the current digit is smaller than the top of the stack and we still have digits to remove (k > 0), we pop the stack. This process continues until we can no longer pop or we have processed all digits. Finally, if there are still digits to remove, we remove them from the end of the result. We also need to handle leading zeros in the final result.

// Steps:
// 1. Initialize an empty string to act as a stack.
// 2. Iterate through each character in the input string:
//    - While the stack is not empty, k > 0, and the last character in the stack is greater than the current character, pop the stack and decrement k.
//    - Push the current character onto the stack.
// 3. If there are still digits to remove after processing all characters, remove them from the end of the stack.
// 4. Remove leading zeros from the result.
// 5. If the result is empty after removing leading zeros, return "0". Otherwise, return the result.

// Time Complexity: O(N) where N is the length of the input string.    
// Space Complexity: O(N) for the stack used to build the result.


class Solution {
public:
    string removeKdig(string s, int k) {
        string st;  // works as stack

        for (char c : s) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // If still need to remove digits
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') i++;

        string ans = st.substr(i);

        if (ans.empty()) return "0";
        return ans;
    }
};