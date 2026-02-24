#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an array of integers and an integer k, find the count of subarrays having XOR of their elements as k.
Approach: We can use a hash map to store the cumulative XOR of the elements up to the current index. We iterate through the array, calculating the cumulative XOR at each index. If we encounter a cumulative XOR that, when XORed with k, gives us a previously seen cumulative XOR, it means that the subarray between those two indices has an XOR of k. We can then count how many times this condition is met to get our answer.

Steps:
1. Initialize a hash map to store the cumulative XOR and their corresponding counts.
2. Initialize a variable to keep track of the cumulative XOR and a variable to store the count of subarrays.
3. Iterate through the array:
   a. Update the cumulative XOR by XORing it with the current element.
   b. If the cumulative XOR is equal to k, increment the count by 1 (this means that the subarray from the start to the current index has an XOR of k).
   c. If the cumulative XOR XORed with k is found in the hash map, it means there are some subarrays that end at the current index and have an XOR of k. Increment the count by the number of times this condition is met.
   d. Update the hash map with the current cumulative XOR.
4. Return the count of subarrays found.

Time Complexity: O(n) where n is the size of the input array.
Space Complexity: O(n) in the worst case, if all cumulative XORs are unique
*/
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long long n = arr.size(), ans = 0;
        map<long long, long long> mp;
        mp[0] = 1;
        long long pref = 0;
        for (long long i = 0; i < n; i++){
            pref = pref^arr[i];
            if (mp.count(pref^k)) ans += mp[pref^k]; // a^b == c <=> c^b == a
            mp[pref]++;
        }
        return ans;
    }
};