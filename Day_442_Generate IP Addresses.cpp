#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order. A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros.
Approach: We can use backtracking to generate all possible combinations of the digits in the string and check if they form valid IP addresses. We will start from the first character of the string and try to create segments of the IP address by adding a dot after every 1 to 3 characters. We will keep track of the number of segments we have created and the current segment value. If we have created 4 segments and we have used all characters in the string, we will add the current combination to our answer list.    

Steps:
1. Create a helper function that takes the current index, the count of segments created, the current combination of the IP address, the current segment value, and the answer list as parameters.
2. If the current index is equal to the length of the string, check if we have created 4 segments. If we have, add the current combination to the answer list and return.
3. Calculate the value of the current segment by adding the current character to the previous segment value.
4. If the current segment value is less than or equal to 255 and does not have leading zeros, we can extend the current segment by calling the helper function recursively with the next index, the same segment count, the current combination plus the current character, and the updated segment value.
5. If we have created less than 3 segments, we can also start a new segment by adding a dot and calling the helper function recursively with the next index, the segment count incremented by 1, the current combination plus a dot and the current character, and the new segment value.
6. Finally, return the answer list.

Time complexity of this approach is O(1) because the number of valid IP addresses that can be generated from a string of digits is limited and does not depend on the length of the string. The space complexity is also O(1) for the same reason, as we are only storing a limited number of valid IP addresses in the answer list.
Complexity is O(1) because the number of valid IP addresses that can be generated from a string of digits is limited and does not depend on the length of the string. The space complexity is also O(1) for the same reason, as we are only storing a limited number of valid IP addresses in the answer list.
*/


class Solution {
    void solve(int i, int cnt, string& s, string t, int num, vector<string>& ans){
        
        if (i == s.size()){
            if (cnt == 3) ans.push_back(t);
            return;
        }

        int val = num * 10 + (s[i] - '0');

        // extend current segment (only if no leading zero)
        if (num != 0 && val <= 255){
            solve(i + 1, cnt, s, t + s[i], val, ans);
        }

        // put dot -> start new segment
        if (cnt < 3){
            solve(i + 1, cnt + 1, s, t + "." + s[i], s[i] - '0', ans);
        }
    }

public:
    vector<string> generateIp(string &s) {
        vector<string> ans;

        if (s.size() < 4 || s.size() > 12) return ans;

        solve(1, 0, s, string(1, s[0]), s[0] - '0', ans);

        return ans;
    }
};