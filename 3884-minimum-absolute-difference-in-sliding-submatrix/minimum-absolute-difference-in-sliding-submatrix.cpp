class Solution {
public:
    
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1,0));

        if(k==1) return ans;

        int req = k-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int startx = i;
                int starty = j;

                if(startx+req < n && starty+req<m){
                     vector<int>v;

                    for(int k=startx;k<=startx+req;k++){
                        for(int l=starty;l<=starty+req;l++){
                            v.push_back(grid[k][l]);
                        }
                    }

                    sort(v.begin(),v.end());

                    int temp =INT_MAX;

                    for(int i=1;i<v.size();i++){
                        if(v[i]!=v[i-1]){
                            temp = min(temp , abs(v[i]- v[i-1]));
                        }
                    }

                    ans[i][j]= (temp==INT_MAX)?0:temp;

                }

            }
        }

        return ans;
    }
};