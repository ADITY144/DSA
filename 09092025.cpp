class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0); // dp[i] = people who learn secret on day i
        dp[1] = 1;

        int sharing = 0; // total people who can share on day i

        for (int day = 2; day <= n; ++day) {
            // People who start sharing today
            if (day - delay >= 1)
                sharing = (sharing + dp[day - delay]) % MOD;

            // People who forget today
            if (day - forget >= 1)
                sharing = (sharing - dp[day - forget] + MOD) % MOD;

            dp[day] = sharing;
        }

        // Count people who still remember the secret on day n
        int result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            result = (result + dp[day]) % MOD;
        }

        return result;
    }
};