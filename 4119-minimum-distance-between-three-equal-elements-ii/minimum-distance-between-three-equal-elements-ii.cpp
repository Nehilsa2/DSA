class Solution {
public:
    int findmin(vector<int>nums){
        int n = nums.size();
        int i=0;
        int j=0;
        int mindiff = INT_MAX;

        while(j<n){

            if(j-i+1>3){
                i++;
            }

            if(j-i+1==3){
                int diff = abs(nums[i+1]-nums[i]) + abs(nums[i+1]-nums[j]) + abs(nums[i]-nums[j]);
                mindiff = min(diff,mindiff);
            }

            j++;
        }

        return mindiff;
    }
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        int ans =INT_MAX;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto i:mp){
            if(i.second.size()>=3){
                ans = min(findmin(i.second),ans);
            }
        }

        return (ans==INT_MAX) ? -1 : ans;
    }
};