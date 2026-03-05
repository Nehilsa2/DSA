class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(j==i+1){
                    dp1[i][j] = arr[i];
                }
                else{
                    dp1[i][j] = dp1[i][j-1] ^ arr[j-1];
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=i;j<n;j++){
                if(j==i){
                    dp2[i][j] = arr[i];
                }
                else{
                    dp2[i][j] = dp2[i][j-1] ^ arr[j];
                }
            }
        }

        int cnt = 0;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    int a = dp1[i][j];
                    int b = dp2[j][k];

                    if(a==b) cnt++;
                }
            }
        }

        return cnt;

        
    }

    //[]
};