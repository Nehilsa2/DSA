class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = 1;

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        if(x==n-1 && y==m-1) return true;

        int curr = grid[x][y];

        // RIGHT
        if(y+1<m && !vis[x][y+1]){
            int next = grid[x][y+1];
            if((curr==1||curr==4||curr==6) && (next==1||next==3||next==5)){
                vis[x][y+1]=1;
                q.push({x,y+1});
            }
        }

        // LEFT
        if(y-1>=0 && !vis[x][y-1]){
            int next = grid[x][y-1];
            if((curr==1||curr==3||curr==5) && (next==1||next==4||next==6)){
                vis[x][y-1]=1;
                q.push({x,y-1});
            }
        }

        // DOWN
        if(x+1<n && !vis[x+1][y]){
            int next = grid[x+1][y];
            if((curr==2||curr==3||curr==4) && (next==2||next==5||next==6)){
                vis[x+1][y]=1;
                q.push({x+1,y});
            }
        }

        // UP
        if(x-1>=0 && !vis[x-1][y]){
            int next = grid[x-1][y];
            if((curr==2||curr==5||curr==6) && (next==2||next==3||next==4)){
                vis[x-1][y]=1;
                q.push({x-1,y});
            }
        }
    }

    return false;
}
};

// queue {1}