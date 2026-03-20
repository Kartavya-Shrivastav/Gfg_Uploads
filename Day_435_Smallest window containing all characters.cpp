#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two strings S and P, find the smallest window in S that contains all the characters of P. If there is no such window in S that covers all characters in P, return an empty string "".
Approach: We can use a sliding window approach to solve this problem. We maintain a window defined by two pointers, `start` and `end`, which represent the start and end of the current substring in S. We also use two frequency arrays (or hash maps) to keep track of the frequency of characters in the current window and the frequency of characters in P. As we expand the window by moving the `end` pointer, we update the frequency of characters in the current window. If the current window contains all characters of P (i.e., the frequency of each character in the current window is at least as much as in P), we try to shrink the window from the left by moving the `start` pointer while still maintaining all characters of P in the window. During this process, we keep track of the minimum length of a valid window that contains all characters of P.

Steps:
1. Initialize two frequency arrays (or hash maps) `count1` and `count2` to store the frequency of characters in the current window and in P, respectively. Also, initialize a boolean array `v` to check if a character is present in P.
2. Populate the frequency array `count2` and the boolean array `v` based on the characters in P.
3. Initialize two pointers, `start` and `end`, to represent the start and end of the current window, and variables `a`, `b`, and `ans` to keep track of the starting index, ending index, and length of the minimum window found, respectively.
4. Iterate through the string S using the `end` pointer:
    a. If the current character at `end` is present in P (checked using the boolean array `v`), update the frequency of that character in `count1`. If the frequency of that character in the current window is less than or equal to its frequency in P, increment a counter `k` that keeps track of how many characters of P are currently present in the window.
    b. If `k` is equal to the length of P, it means the current window contains all characters of P. Now, try to shrink the window from the left by moving the `start` pointer while still maintaining all characters of P in the window:
        i. Update the minimum window length and starting/ending indices if the current window is smaller than the previously found minimum.
        ii. If the character at `start` is present in P, update its frequency in `count1`. If after decrementing, the frequency of that character in the current window becomes less than its frequency in P, decrement `k`.
        iii. Move the `start` pointer to the right to continue shrinking the window.
5. After the loop, if `ans` is still `INT_MAX`, it means no valid window was found, so return an empty string. Otherwise, return the substring of S from index `a` to `b` as the smallest window containing all characters of P.

Time Complexity: O(n), where n is the length of the input string S. We traverse the string once with the `end` pointer, and the `start` pointer also moves at most n times.
Space Complexity: O(1), as we are using fixed-size frequency arrays (or hash maps) to store the frequency of characters, and the size of these arrays is constant (26 for lowercase letters).
*/

class Solution {
  public:
    string minWindow(string &s, string &p) {
        int n1=s.size();
        int n2=p.size();
        if(n2>n1)return "";
        
        vector<bool>v(26,0); // use to check char is in p or not
        vector<int>count1(26,0);// help us to determine all char present in substring or not
        vector<int>count2(26,0);// number of each char in p
        
        for(int i=0;i<p.size();i++){
           v[p[i]-'a']=1;
           count1[p[i]-'a']++;
           count2[p[i]-'a']++;
        }
        
        int a=0,b=0;
        int start=0;
        int end=-1;
        int ans=INT_MAX;
        int k = 0; // how many char till present in substring
        
        
        while(end<n1){
            
            if(k==n2){ // all char present update ans.
                
                int size = end-start+1;
                if(size<ans){
                    a=start;
                    b=end;
                    ans=size;
                }
                
                if(v[s[start]-'a']){ // remove first char of substring
                    
                    count1[s[start]-'a']++;
                    int temp = count2[s[start]-'a']-count1[s[start]-'a'];// count of start index char present in substring
                    if(temp<count2[s[start]-'a'])k--;
                       
                }
                
                start++;
                
            }
            else{ // increase the lenght and check
                
                end++;
                if(end>=n1)break;
                
                if(v[s[end]-'a']){
                    
                    if(count1[s[end]-'a']>0){ // help for duplication
                        count1[s[end]-'a']--;
                        k++;
                    }
                    else count1[s[end]-'a']--;
                }
                
            }
        }
        
        if(ans==INT_MAX)return "";
        
        return s.substr(a,b-a+1);
        
        
    }
};