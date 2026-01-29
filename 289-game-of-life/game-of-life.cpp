class Solution {
public:
    int n,m;         
    vector<int>dx = {1,-1,0,0,1,1,-1,-1};
    vector<int>dy = {0,0,1,-1,-1,1,1,-1};
    int interactNeighbours(int x, int y ,vector<vector<int>>&board){
        int cnt = 0;
        for(int d=0;d<8;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx>=0 && ny>=0 && ny<m && nx<n){
                if(board[nx][ny]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>newboard = board;
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++){
            int livecells = 0;
            for(int j=0;j<m;j++){
                livecells = interactNeighbours(i,j,newboard);

                if(board[i][j]){
                    if(livecells==2 || livecells==3){
                        board[i][j] = 1;
                    }
                    else{
                        board[i][j] = 0;
                    }
                }
                else{
                    if(livecells==3){
                        board[i][j]=1;
                    }
                }
            }
        }
    }

    //each cell have exactly eight choices 
    //for each cell look for all its eight neighbours 
};