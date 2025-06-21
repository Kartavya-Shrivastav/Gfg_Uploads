#include <bits/stdc++.h>
using namespace std;

// Problem: Police and Thieves
// Approach: Use two-pointer technique to match each police with the nearest thief within distance k.

// Steps:
// 1. Create two vectors to store the indices of police and thieves.
// 2. Iterate through the array and fill the vectors.
// 3. Use two pointers to match police with thieves within the given distance k.
// 4. Count the number of successful catches and return the result.

// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(n) for storing indices of police and thieves.

class Solution {
    public:
        int catchThieves(vector<char> &arr, int k) {
                // Vectors to store indices of police and thieves
                vector<int> p, t;
                for(int i = 0; i < arr.size(); i++) {
                        if(arr[i] == 'P')
                                p.push_back(i); // Store police index
                        else
                                t.push_back(i); // Store thief index
                }
                
                int ans = 0; // Count of caught thieves
                int st = 0;  // Pointer for police vector
                // Iterate through each thief
                for(int i = 0; i < t.size(); i++) {
                        // Try to find a police for the current thief
                        while(st < p.size()) {
                                int low = t[i] - k;   // Minimum index police can be at
                                int high = t[i] + k;  // Maximum index police can be at
                                if(p[st] <= high && p[st] >= low) {
                                        // Police is within range, catch the thief
                                        ans++;
                                        st++; // Move to next police
                                        break;
                                }
                                else if(p[st] < low) {
                                        // Police is too far left, move to next police
                                        st++;
                                }
                                else {
                                        // Police is too far right, can't catch this thief
                                        break;
                                }
                        }
                }
                return ans; // Return total caught thieves
        }
};