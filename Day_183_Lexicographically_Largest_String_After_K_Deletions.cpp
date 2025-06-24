#include <bits/stdc++.h>
using namespace std;

// Problem: Lexicographically Largest String After K Deletions
// Approach: Stack-based Greedy Algorithm

// Steps:
// 1. Use a stack to maintain the characters of the resulting string.
// 2. Iterate through the string, and for each character:
// 3. While the stack is not empty and the top character of the stack is less than the current character,
//    and we can still remove characters (i.e., the number of characters in the stack is greater than i - k),
//    pop the top character from the stack.
// 4. If the stack has fewer than n - k characters, push the current character onto the stack.
// 5. After processing all characters, the stack will contain the indices of the characters in the resulting string.
// 6. Construct the result string from the characters in the stack and reverse it.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(n), for the stack and the result string.

class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<int>st;
        int n=s.length();
        int cnt=0;   //To keep track on number of elements present in the stack at any point of time
        for(int i=0;i<n;i++){
            while(cnt>(i-k) && !st.empty() && s[st.top()]<s[i]){
               //cnt>(i-k) ensure that we dont run into shortage of characters
                cnt--;
                st.pop();
            }
            if(cnt<(n-k)){
                st.push(i); //Add current character if stack has less than n-k characters
                cnt++;
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(s[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};