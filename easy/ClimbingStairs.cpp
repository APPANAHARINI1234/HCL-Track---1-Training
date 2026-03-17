class Solution {
public:
    int noofways(int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = noofways(n - 1, dp) + noofways(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return noofways(n, dp);
    }
};