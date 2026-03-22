class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true;


        int n = mat.size();
        int m = mat[0].size();

        //check 2nd rotation 

        bool ismatch = true;
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]!=target[n-i-1][m-1-j]){
                    ismatch = false;
                    break;
                } 
            }

            if(!ismatch) break;
        }

        if(ismatch) return true;

        //check 1st rotation

        ismatch = true;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=target[j][m-i-1]){
                    ismatch = false;
                    break;
                }
            }

            if(!ismatch) break;
        }
        
        if(ismatch) return true;
        //check 3rd rotation
        
        ismatch = true;
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]!=target[m-1-j][i]){
                    ismatch = false;
                    break;
                }
            }

            if(!ismatch) break;
        }

        return ismatch;
    }
};