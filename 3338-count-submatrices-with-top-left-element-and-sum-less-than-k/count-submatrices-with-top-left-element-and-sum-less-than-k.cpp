class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

     
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j] = grid[i][j-1] + grid[i][j];
            }
        }
        

        for(int j=0;j<m;j++){
            int sum= 0;
            for(int i=0;i<n;i++){
                sum+=grid[i][j];

                if(sum<=k){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }

        return cnt;
    }
};