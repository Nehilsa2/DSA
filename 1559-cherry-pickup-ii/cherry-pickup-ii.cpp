class Solution {
public:
    int dy[3] = {-1,0,1}; 
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));


        //base case 
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2){
                    dp[n-1][j1][j2] = grid[n-1][j1];
                }
                else{
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }

        
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){

                    int maxi = -1e8;
                    for(int d1 = 0;d1<3;d1++){
                        for(int d2 = 0; d2<3;d2++){
                            int value = 0;
                            int dj1 = j1 + dy[d1];
                            int dj2 = j2 + dy[d2];

                            if(j1==j2){
                                value+= (grid[i][j1]);
                            }
                            else{
                                value+= (grid[i][j1]+grid[i][j2]);
                            }

                            if(dj1>=0 && dj2>=0 && dj1<m && dj2<m){
                                value+=dp[i+1][dj1][dj2];
                            }
                            

                            maxi = max(value,maxi);

                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }
};