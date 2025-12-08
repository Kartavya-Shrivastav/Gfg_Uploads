class Solution {
public:
    int mod = 1000000007;

    int distinctSubseq(string &str) {
        int n = str.size();
        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % mod;

            int ch = str[i - 1] - 'a';
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch]] + mod) % mod;
            }

            last[ch] = i - 1;
        }

        return dp[n];
    }
};