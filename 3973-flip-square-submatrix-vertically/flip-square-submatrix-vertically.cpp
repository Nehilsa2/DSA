class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int endx = x+k-1;
        int endy = y+k-1;

        int starti = x;
        int endi = endx;

        while(starti<endi){
            for(int i=y;i<=endy;i++){
                swap(grid[starti][i],grid[endi][i]);
            }
            starti++;
            endi--;
        }

        return grid;
    }
};