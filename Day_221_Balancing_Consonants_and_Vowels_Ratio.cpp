#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Count the number of balanced strings in an array
// A balanced string is defined as one where the number of consonants and vowels are equal.
// Approach: Use a map to keep track of the difference between the number of vowels and consonants.

// Steps:
// 1. For each string, count the number of vowels and consonants.
// 2. Calculate the difference between the number of vowels and consonants for each string.
// 3. Use a map to count how many times each difference occurs.
// 4. For each string, if the difference has been seen before, it means there are balanced strings that can be formed with the current string.
// 5. The total count of balanced strings is the sum of all occurrences of each difference.
// 6. Return the total count.

// Time Complexity: O(n * m), where n is the number of strings and m is the average length of the strings, due to counting vowels and consonants.
// Space Complexity: O(n), for storing the differences in the map.



class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
          auto getCount = [&] (string s) {
            int ans = 0;
            string txt = "aeiou";
            for(char c :s){
                if(txt.find(string(1,c)) != string::npos) ans++;
            }
            return ans;
        };
        int n = arr.size();
        vector<int>vc(n);
        for(int i = 0;i<n;i++){
            vc[i] = getCount(arr[i]);
            vc[i] -= (arr[i].length() - vc[i]);
        }
        int ans = 0;
        map<int,int>mp;
        mp[0] = 1;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += vc[i];
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};