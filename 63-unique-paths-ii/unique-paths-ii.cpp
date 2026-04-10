class Solution {
public:
    int dp[101][101];

    // int solve(int i, int j,vector<vector<int>>& obstacleGrid){
        
    //     if(i==0 && j==0){
    //         if(obstacleGrid[i][j]==1){
    //             return 0;
    //         }
    //         return 1;
    //     }

    //     if(i<0 || j<0 || obstacleGrid[i][j]==1){
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     int up = solve(i-1,j,obstacleGrid);
    //     int left = solve(i,j-1,obstacleGrid);

    //     return dp[i][j] = up+left;

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        memset(dp,0,sizeof(dp));

        if(obstacleGrid[0][0]==1) return 0;
        dp[0][0] = 1;

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=0,left=0;

                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }

                if(i==0 && j==0) continue;


                if(i-1>=0){
                    up = dp[i-1][j];
                }
                if(j-1>=0){
                    left = dp[i][j-1];
                }

                dp[i][j] = left+up;
            }
        }

        // return solve(n-1,m-1,obstacleGrid);
        return dp[n-1][m-1];
    }
};