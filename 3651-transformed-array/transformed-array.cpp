class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                int newindex = (i-abs(nums[i])%n +n)%n;
                ans[i] = nums[newindex];
            }
            else if(nums[i]>0){
               int newindex =  (i+nums[i])%n;
                ans[i] = nums[newindex];
            }
            else{
                ans[i] = nums[i];
            }
        }

        return ans;
    }
};