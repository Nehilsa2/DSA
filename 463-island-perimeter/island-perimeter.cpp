class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int n = grid.size();
        int m =grid[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    
                    if(i>0){    
                        if(grid[i-1][j]==0){
                            perimeter+=1;
                        }
                    }
                    else{
                        perimeter+=1;
                    }
                    
                    if(j>0){
                        if(grid[i][j-1]==0){
                            perimeter+=1;
                        }
                    }
                    else{
                        perimeter+=1;
                    }

                    if(j<m-1){
                        if(grid[i][j+1]==0){
                            perimeter++;
                        }
                    }
                    else{
                        perimeter++;
                    }

                    if(i<n-1){
                        if(grid[i+1][j]==0){
                            perimeter++;
                        }
                    }
                    else{
                        perimeter++;
                    }
                    cout << perimeter << " ";
                    
                }
            }
        }

        return perimeter;
    }
};