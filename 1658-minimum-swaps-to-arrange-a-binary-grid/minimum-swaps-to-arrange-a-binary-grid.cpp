class Solution {
public:

    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>trailingzeros(n);
        int swaps = 0;


        for(int i=0;i<n;i++){
            int zeros = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0){
                    zeros++;
                }
                else{
                    break;
                }
            }
            trailingzeros[i] = zeros;  
        }


        for(int i=0;i<n;i++){
            int required = n-1-i; 
            int j=i;

            while(j<n && required>trailingzeros[j]){
                j++;
            }

            if(j == n) return -1;

            while(j>i){
                swap(trailingzeros[j],trailingzeros[j-1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};