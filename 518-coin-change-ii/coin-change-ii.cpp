class Solution {
    int solve(int i, int sum, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(i==coins.size()) return 0;
        if(sum == amount) return 1;
        if(dp[i][sum] != -1)return dp[i][sum];
        int p1=0, p2=0, np = solve(i+1, sum, amount, coins, dp);
        if(coins[i]+sum<=amount) p1 = solve(i, sum+coins[i], amount, coins, dp);
        return dp[i][sum] = np+p1+p2;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount, -1));
        return solve(0, 0, amount, coins, dp);
    }
};