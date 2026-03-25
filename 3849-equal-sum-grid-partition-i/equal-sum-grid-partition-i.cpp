class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum  = 0;

        int n = grid.size();
        int m = grid[0].size(); 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                totalSum+=grid[i][j];
            }
        }
        

        int horcuts = n-1;
        long long prevsum = 0;

        for(int i=0;i<n-1;i++){
            long long sum = 0;
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }   

            if(sum+prevsum == totalSum - (sum+prevsum)) return true;
            prevsum = sum+prevsum;
        }

        int vercuts = m-1;
        prevsum = 0;
        for(int j=0;j<m-1;j++){
            long long  sum = 0;
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
            }   

            if(sum+prevsum==totalSum-(sum+prevsum)) return true;

            prevsum = sum+prevsum;
        }

        return false;
    }
};