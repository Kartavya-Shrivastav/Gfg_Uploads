#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers, determine if there exists a Pythagorean triplet in the array. A Pythagorean triplet is a set of three integers (a, b, c) such that a^2 + b^2 = c^2.
Approach: We can use a brute-force approach to check for all possible combinations of three integers in the array and verify if they satisfy the Pythagorean condition. However, this approach has a time complexity of O(n^3). A more efficient approach is to first find the maximum value in the array and create a frequency array to keep track of which integers are present. Then, we can iterate through all pairs of integers (a, b) and check if c = sqrt(a^2 + b^2) is an integer and is present in the frequency array. This approach has a time complexity of O(n^2) and space complexity of O(maxVal), where maxVal is the maximum integer in the array.

Steps:
1. Find the maximum value in the array to determine the size of the frequency array.
2. Create a frequency array of size maxVal + 1 and mark the presence of each integer in the input array.
3. Iterate through all pairs of integers (a, b) in the input array:
    a. For each pair, calculate c^2 = a^2 + b^2.
    b. Calculate c = sqrt(c^2) and check if c is an integer and is present in the frequency array.
    c. If such a triplet (a, b, c) is found, return true.
4. If no triplet is found after checking all pairs, return false.

Time Complexity: O(n^2) for iterating through all pairs of integers.
Space Complexity: O(maxVal) for the frequency array, where maxVal is the maximum integer in the input array.
*/

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int maxVal = 0;
        for(int num : arr)
            maxVal = max(maxVal, num);
        
        vector<bool> freq(maxVal + 1, false);

        for(int num : arr)
            freq[num] = true;        

        for(int a = 1; a <= maxVal; a++) {
            if(!freq[a]) continue;
            for(int b = a; b <= maxVal; b++) {
                if(!freq[b]) continue;
                int c2 = a*a + b*b;
                int c = sqrt(c2);

                if(c <= maxVal && c*c == c2 && freq[c])
                    return true;
            }
        }
        return false;
    }
};