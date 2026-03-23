class Solution {
public:

    // int solve(vector<int>& coins, int amount, int index){
        
    //     if(amount == 0) return 0;

    //     if(index < 0) return 1e9;  
        
    //     if(dp[index][amount]!=-1){
    //         return dp[index][amount];
    //     }

    //     if(coins[index] <= amount){
    //         return dp[index][amount] =min(1 + solve(coins, amount - coins[index], index),solve(coins, amount, index - 1));
    //     }

    //     return dp[index][amount] = solve(coins, amount, index - 1);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        // base case
        for(int i = 0; i < n; i++) dp[i][0] = 0;

        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0] == 0)
                dp[0][amt] = amt / coins[0];
        }

    // dp fill
    for(int index = 1; index < n; index++){
        for(int amt = 0; amt <= amount; amt++){

            int notTake = dp[index-1][amt];

            int take = 1e9;
            if(coins[index] <= amt && dp[index][amt - coins[index]] != 1e9){
                take = 1 + dp[index][amt - coins[index]];
            }

            dp[index][amt] = min(take, notTake);
        }
    }

        int ans = dp[n-1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};