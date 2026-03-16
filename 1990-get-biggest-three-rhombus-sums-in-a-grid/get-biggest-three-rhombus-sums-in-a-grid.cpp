class Solution {
public:
    
    
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        set<int>s;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){

               
               s.insert(grid[i][j]); // size 0 rhombus

                int limit = min({i, j, n-i-1, m-j-1});

                for(int d = 1; d <= limit; d++){

                    int sum = 0;

                    int x = i-d, y = j;

                    // upper-right
                    for(int k=0;k<d;k++) sum += grid[x+k][y+k];

                    // lower-right
                    for(int k=0;k<d;k++) sum += grid[i+k][j+d-k];

                    // lower-left
                    for(int k=0;k<d;k++) sum += grid[i+d-k][j-k];

                    // upper-left
                    for(int k=0;k<d;k++) sum += grid[i-k][j-d+k];

                    s.insert(sum);
                }
            }
        }

       if(s.size() < 3)
            return vector<int>(s.rbegin(), s.rend());

       return vector<int>(s.rbegin(), next(s.rbegin(), 3));

    }   
};