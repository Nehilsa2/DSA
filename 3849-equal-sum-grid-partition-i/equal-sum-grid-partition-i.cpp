class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long>verticalSum(n,0);
        vector<long long>horizontalSum(m,0);
        

        for(int j=0;j<m;j++){  //(m)
            verticalSum[0] += 1LL*grid[0][j];
            verticalSum[n-1]+= 1LL*grid[n-1][j];
        }

        for(int i=0;i<n;i++){  //(n)
            horizontalSum[0] +=1LL*grid[i][0];
            horizontalSum[m-1] +=1LL*grid[i][m-1];

        }


        for(int i=1;i<n-1;i++){  // (m*n)
            for(int j=0;j<m;j++){
                verticalSum[i]+=1LL*grid[i][j];
            }

            verticalSum[i]+=verticalSum[i-1];
        }

        

        for(int j=1;j<m-1;j++){   //(m*n)
            for(int i=0;i<n;i++){
                horizontalSum[j]+=1LL*grid[i][j];
            }

            horizontalSum[j]+=horizontalSum[j-1];
        }

        //check horizontal cuts
        int horcuts = n-1;

        for(int cut=0;cut<n-1;cut++){  // o(cuts)
            long long toCompare = verticalSum[n-1] + verticalSum[n-2] - verticalSum[cut];
            if(verticalSum[cut] == toCompare){
                return true;
            }
        }


        //check vertical cuts
        int vertcuts = m-1;

        for(int cut=0;cut<m-1;cut++){  // o(cuts)
            long long toCompare = horizontalSum[m-1] + horizontalSum[m-2] - horizontalSum[cut];
            if(horizontalSum[cut] == toCompare){
                return true;
            }
        }

        return false;

    }
};