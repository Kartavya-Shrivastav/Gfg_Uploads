#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Count the number of pairs (i, j) such that gcd(arr[i], arr[j]) = 1 for all i < j in the array `arr`.
// Approach: Use the Möbius function and inclusion-exclusion principle to count coprime pairs efficiently.

// Stpes:
// 1. Calculate the maximum value `m` in the array `arr`.
// 2. Create a frequency array `f` to count occurrences of each number up to `m`.
// 3. Use the Sieve of Eratosthenes to compute the Möbius function `mu` for each integer up to `m`.
// 4. For each divisor `d`, count how many numbers in `arr` are divisible by `d` using the frequency array `f`.
// 5. Use the Möbius function to apply the inclusion-exclusion principle to count coprime pairs.

// Time Complexity: O(m log log m + n log n) — where `m` is the maximum element in `arr` and `n` is the size of `arr`.
// Space Complexity: O(m) — for the frequency and Möbius function arrays.

class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        // code here
         int n = arr.size(), m = *max_element(arr.begin(), arr.end());
        vector<int> f(m+1);
        for (auto& x : arr) 
            f[x]++;

        vector<int> mu(m+1), pr, isp(m+1);
        mu[1] = 1;
        for (int i=2; i<=m; i++) {
            if (!isp[i]) {
                pr.push_back(i);
                mu[i] = -1;
            }
            for (auto& p : pr) {
                long long v = 1LL * i * p;
                if (v > m) break;
                isp[v] = 1;
                if (i % p == 0) {
                    mu[v] = 0;
                    break;
                }
                mu[v] = -mu[i];
            }
        }

        vector<long long> cnt(m+1);
        for (int d=1; d<=m; d++)
            for (int k=d; k<=m; k+=d)
                cnt[d] += f[k];

        long long ans = 0;
        for (int d=1; d<=m; d++) {
            long long c = cnt[d];
            ans += mu[d] * (c * (c-1) / 2);
        }
        return ans;
    }
};