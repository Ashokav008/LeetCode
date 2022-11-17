class Solution {
public:
    using vl = vector<long>;
    using vll = vector<vl>;
    int mod = 1e9 + 7;
    int numberOfCombinations(string &num) {
        if (num[0] == '0') return 0;
        int n = num.size();
        vll dp(n, vl(n + 1, 0)), same(n + 1, vl(n + 1));
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                same[i][j] = num[i] == num[j] ? same[i + 1][j + 1] + 1 : 
                             num[i] > num[j] ? 0 :
                             INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                int s = i - j + 1;
                if (num[s] == '0') dp[i][j] = dp[i][j - 1];
                else if (s >= j && same[s - j][s] >= j) 
                    dp[i][j] = (dp[i][j - 1] + dp[s - 1][j]) % mod;
                else
                    dp[i][j] = (dp[i][j - 1] + dp[s - 1][min(j - 1, s)]) % mod;
            }
            dp[i][i + 1] = (dp[i][i] + 1) % mod;
        }
        return dp.back().back();
    }
};

