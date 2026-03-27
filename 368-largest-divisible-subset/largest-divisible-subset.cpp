class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans;

        sort(nums.begin(),nums.end());

        vector<int>dp(n,1);  // gives the maxlength subset following divisible rule at index i
        vector<int>parent(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        int lastindex = 0;

        int maxvalue = 1;

        for(int i=1;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[i]%nums[prev]==0){
                    if(dp[prev]+1 > dp[i]){
                        dp[i] = dp[prev] + 1;
                        parent[i] = prev;
                    }

                    if(dp[i]>maxvalue){
                        maxvalue = dp[i];
                        lastindex = i;
                    }
                }
            }
        }

        while(lastindex!=parent[lastindex]){
            ans.push_back(nums[lastindex]);
            lastindex = parent[lastindex];
        }

        ans.push_back(nums[lastindex]);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};