class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto v:mp){
            vector<int>temp = v.second;
            if(temp.size()>1){
                
                int n = temp.size();

                for(int i=1;i<n;i++){
                    if (abs(temp[i] - temp[i - 1]) <= k)
                        return true;
                }
                
            }
        }

        return false;


    }
};