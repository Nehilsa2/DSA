class Solution {
public:
    void rightShift(vector<int>&v,int m,int k){
        for(int i=0;i<k;i++){
            reverse(v.begin(),v.begin() + (v.size()-1));
            reverse(v.begin(),v.end());
        }
    }

    void leftShift(vector<int>&v,int m,int k){
        for(int i=0;i<k;i++){
            reverse(v.begin()+1,v.end());
            reverse(v.begin(),v.end());
        }
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>temp = mat;
        
        for(int i=0;i<n;i++){ //(n)
            if(i&1){
                rightShift(temp[i],m,k%m); // o(k*m)
            }
            else{
                leftShift(temp[i],m,k%m);
            }
        }

        return (temp==mat);
    }
};