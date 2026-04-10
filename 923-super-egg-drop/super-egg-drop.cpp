class Solution {
public:
    int superEggDrop(int k, int n) {

        int dp[101][10001];
        memset(dp,0,sizeof(dp));

        //base case 
        // if floor = 1 or floor = 0

        for(int e=1;e<=k;e++){
            dp[e][0]=0;
            dp[e][1]=1;
        }

        //if egg==1

        for(int f=1;f<=n;f++){
            dp[1][f]=f;
        }
        
        for(int e=2;e<=k;e++){
            for(int f=2;f<=n;f++){
                dp[e][f] = INT_MAX;

                int low = 1;
                int high = f;

                while(low<=high){
                    int mid = low + (high-low)/2;

                    int breakcase = dp[e-1][mid-1];
                    int survivecase = dp[e][f-mid];

                    int temp = 1 + max(breakcase , survivecase);
                    dp[e][f] = min(dp[e][f],temp);


                    if(breakcase > survivecase){
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }

                }
            }
        }

        return dp[k][n];
        //check all the floor for the optimal starting floor
    }
};