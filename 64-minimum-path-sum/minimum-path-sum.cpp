class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){

        if(i==0 && j==0){
            return grid[0][0];
        }

        if(i<0 || j<0){
            return INT_MAX;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = solve(i-1,j,grid);
        int left = solve(i,j-1,grid);

        return dp[i][j] = grid[i][j] + min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        memset(dp,0,sizeof(dp));

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[0][0] = grid[0][0];
                    continue;
                }

                int up = INT_MAX;
                int left = INT_MAX;

                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    left = dp[i][j-1];
                }

                dp[i][j] = grid[i][j] + min(left,up);

            }
        }

        // return solve(n-1,m-1,grid);
        return dp[n-1][m-1];
    }
};