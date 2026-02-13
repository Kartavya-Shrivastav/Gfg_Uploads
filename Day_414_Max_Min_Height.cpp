#include <bits/stdtr1c++.h>
using namespace std; 

/* Problem Statement: Given an array a[] of size n, you can water the plants for k days. Each day, you can choose a contiguous segment of w plants and water them, which increases their height by 1. You want to maximize the minimum height of the plants after watering for k days. The task is to find the maximum possible minimum height. 
Approach: We can use binary search to find the maximum minimum height. The idea is to check if it's possible to achieve a certain minimum height (mid) with the given number of watering days (k). We can simulate the watering process using a difference array to efficiently apply the increments to the heights of the plants. If we can achieve the desired minimum height within k days, we move our search range up; otherwise, we move it down. 

Steps: 
1. Initialize the search range for the minimum height from the minimum height in the array to that minimum plus k plus one. 
2. Use binary search to find the optimal minimum height.
3. For each mid value, simulate the watering process: 
    - Use a difference array to track how much each plant's height is increased. 
    - Iterate through the plants and calculate how many days are needed to reach at least mid height for each plant. 
    - If at any point we exceed k days, it means mid is not achievable. 
4. Adjust the search range based on whether mid is achievable or not until we find the maximum minimum height. 

Time Complexity: O(n log M), where M is the range of possible heights (from min height to min height + k). Each check involves iterating through all plants, which takes O(n). 

Space Complexity: O(n), due to the difference array used for simulating watering. */

class Solution {
public:
    int maxMinHeight(vector<int> &a, int k, int w) {
        int n = a.size();
        int mn = *min_element(a.begin(), a.end());
        int mx = mn + k + 1;
        
        auto f = [&](int ht) {
            long long days = 0;
            vector<int> flower(n + 1);
            int diff = max(0, ht - a[0]);
            flower[0] += diff;
            days += diff;
            flower[w] -= diff;
            
            for (int i = 1; i < n; i++) {
                flower[i] += flower[i - 1];
                int curr_ht = a[i] + flower[i];
                diff = max(0, ht - curr_ht);
                flower[i] += diff;
                days += diff;
                if (i + w < n) flower[i + w] -= diff;
            }
            return days <= k;
        };
        
        while (mn < mx) {
            int ht = (mn + mx) / 2;
            if (!f(ht)) mx = ht;
            else mn = ht + 1;
        }
        return mn - 1;
    }
};