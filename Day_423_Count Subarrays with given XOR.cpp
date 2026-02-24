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