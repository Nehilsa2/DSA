class Solution {
public:
    int findmin(vector<int>&v){
        int i=0;
        int j=0;
        int n = v.size();
        int mini = INT_MAX;

        while(j<n){
            if(j-i+1>3){
                i++;
            }

            if(j-i+1==3){
                mini = min(mini,abs(v[i]-v[i+1])+abs(v[i+1]-v[j])+abs(v[j]-v[i]));
            }
            j++;
        }

        return mini;
    }
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto i:mp){
            mini = min(mini,findmin(i.second));
        }

        return (mini==INT_MAX) ? -1:mini;
    }
};