class Solution {
public:
    int n;

    void backtrack(vector<int>&curr,vector<int>&used,set<vector<int>>&s,vector<int>&nums){

        if(curr.size()==n){
            s.insert(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(used[i]==1){
                continue;
            }   

            curr.push_back(nums[i]);
            used[i]=1;

            backtrack(curr,used,s,nums);
            curr.pop_back();

            used[i] = 0;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>curr,used(n,0);

        backtrack(curr,used,s,nums);

        for(auto &i:s){
            ans.push_back(i);
        }

        return ans;

    }

    // [1,2,3,4,5] 
    // [1,2,3,5,4]
    // [1,2,4,3,5]

};