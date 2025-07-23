#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Convert a fraction a/b into its decimal representation, with repeating decimals enclosed in parentheses.
// Approach: Use long division to calculate the decimal representation and track remainders to identify repeating sequences.

// Steps:
// 1. Perform integer division to get the whole number part of the fraction.
// 2. Use a map to track the position of each remainder to identify when a repeating decimal starts.
// 3. Multiply the remainder by 10 to get the next digit in the decimal representation.
// 4. If a remainder repeats, it indicates the start of a repeating decimal sequence.
// 5. Format the result by enclosing the repeating part in parentheses.

// Time Complexity: O(n) — where `n` is the number of digits in the decimal representation.
// Space Complexity: O(n) — for storing the positions of remainders.

class Solution {
  public:
    string calculateFraction(int a, int b) {
        string beforeDot = "";
	    
	    int newa = a/b;
	    int remainder = a % b;
	    
	    if(remainder == 0) return to_string(newa);
	    
	    beforeDot += to_string(newa);
	    newa = remainder;
	    unordered_map<int,int> mp;
	    string afterDot = "";
	    
	    while(newa != 0 and mp.find(newa) ==  mp.end()){
	        
	        mp[newa] = afterDot.length();
	        newa *= 10;
	        afterDot += to_string(newa/b);
	        newa %= b;
	        
	    }
	    
	    if(newa == 0){
	        return beforeDot + "." +   afterDot ;
	    }
	    
	    afterDot.insert(mp[newa], "(");
	    afterDot += ")";
	    return beforeDot + "." + afterDot;
    }
};