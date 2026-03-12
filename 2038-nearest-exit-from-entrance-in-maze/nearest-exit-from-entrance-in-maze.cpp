class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};

        while(!q.empty()){
            int size = q.size();
            steps++;

            while(size--){
                auto [x,y] = q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]=='.'){

                        if(nx==0 || nx==n-1 || ny==0 || ny==m-1)
                            return steps;

                        maze[nx][ny] = '+';
                        q.push({nx,ny});
                    }
                }
            }
        }

        return -1;
    }
};