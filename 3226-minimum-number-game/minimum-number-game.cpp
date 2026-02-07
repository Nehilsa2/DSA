class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int j = 1;
        vector<int>ans;
        while(j<n){
            ans.push_back(nums[j]);
            ans.push_back(nums[i]);
            i+=2;
            j+=2;
        }

        return ans;
    }
};