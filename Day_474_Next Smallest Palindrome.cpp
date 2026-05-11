#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of digits representing a number, find the next smallest palindrome larger than the given number.
Approach: 

Steps:
1. Check if all digits are 9. If they are, the next palindrome would be 100...001 (1 followed by n-1 zeros and another 1).
2. If not all digits are 9, we can find the next palindrome by mirroring the left half of the number to the right half.
    - For odd length numbers, we can compare the left half with the right half. If the left half is greater than the right half, we can simply mirror the left half to the right half. If the left half is less than or equal to the right half, we need to increment the middle digit (or the left half) and then mirror it to the right half.
    - For even length numbers, we can compare the left half with the right half. If the left half is greater than the right half, we can simply mirror the left half to the right half. If the left half is less than or equal to the right half, we need to increment the left half and then mirror it to the right half.  
3. Return the resulting palindrome.

Time Complexity: O(n) - We may need to traverse the number a few times (to check for 9s, to mirror, and to increment), but overall it is linear with respect to the number of digits.
Space Complexity: O(n) - We are creating a new array to store the next palindrome, which takes linear space with respect to the number of digits.
*/
