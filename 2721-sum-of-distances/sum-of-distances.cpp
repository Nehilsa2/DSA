class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,pair<int,int>>lastseen;
        vector<long long>pre(n,0),suf(n,0);

        for(int i=0;i<n;i++){
            long long sum = 0;
            int cnt = lastseen[nums[i]].second;
            int ind = lastseen[nums[i]].first;
            if(lastseen.find(nums[i])!=lastseen.end()){
                sum+= pre[ind] + cnt*abs(i-ind);
                
            }
            lastseen[nums[i]] = {i,cnt+1};
            pre[i] = sum;
        }
       
        lastseen.clear();
        for(int i=n-1;i>=0;i--){
            long long sum = 0;
            int cnt = lastseen[nums[i]].second;
            int ind = lastseen[nums[i]].first;
            if(lastseen.find(nums[i])!=lastseen.end()){
                sum+= suf[ind] + cnt*abs(i-ind);
            }
            lastseen[nums[i]] = {i,cnt+1};
            suf[i] = sum;
        }
        
        for(int i=0;i<n;i++){
            pre[i]+=suf[i];
        }
        return pre;
    }
};