class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<bool>row(m,true),col(n,true);

        for(int i=0;i<m;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
                if(cnt>1) break;  
            }
            if(cnt>1 || cnt==0) row[i] = false;
        }

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(mat[j][i]==1){
                    cnt++;
                }
                if(cnt>1) break;  
            }
            if(cnt>1 || cnt==0) col[i] = false;
        }

        int ans =0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    if(row[i] && col[j]){
                        ans++;
                    }
                }
            }
            
        }

        return ans;
        
    }
};