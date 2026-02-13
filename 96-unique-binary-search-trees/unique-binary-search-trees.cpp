class Solution {
public:
    int numTrees(int n) {
        // vector<int>dp(n+1,0);

        // dp[0] = 1;
        // dp[1] = 1;

        // if(n<=1) return 1; // number of nodes 

        // int ans = 0;

        // for(int i=1;i<=n;i++){  // think each i as the root of the BST
        //     int left = numTrees(i-1); //no of trees can be formed on the left of the current root
        //     int right = numTrees(n-i); //no of trees can be formed on the right of the current root 
        //     ans+=left*right;
        
        // }

        // return ans;

        return solveTab(n);
    }

    int solveTab(int n){
        vector<int>dp(n+1,0);
        //if number of nodes are 0 or 1 then only one tree is possible
        dp[0] = dp[1] = 1;
        //need to know that for more number of nodes what will be the answer

        for(int nodes = 2;nodes<=n;nodes++){
            //treat nodes as the root
            for(int root = 1;root<=nodes;root++){
                int left = root - 1;
                int right = nodes-root;

                dp[nodes]+=dp[left] * dp[right];
            }
        }

        return dp[n];
    }
};