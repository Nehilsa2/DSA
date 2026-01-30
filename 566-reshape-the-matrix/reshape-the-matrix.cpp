class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>newmat(r,vector<int>(c,0));

        int n = mat.size();
        int m = mat[0].size();

        if(m*n != r*c){
            return mat;
        }

        int ni = 0;
        int nj = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nj<c){
                    newmat[ni][nj] = mat[i][j];
                    nj++;
                }
                
                if(nj>=c){
                    ni++;
                    nj=0;
                }
            }
        }

        return newmat;
    }
    // c=1 , nj = 0 , ni = 0
    // []
    // []
    // []
    // []
};