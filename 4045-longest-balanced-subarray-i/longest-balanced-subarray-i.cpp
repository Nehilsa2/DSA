class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxlen = 0;
        int n = nums.size();
        
        for(int i =0;i<n;i++){
            int even = 0;
            int odd = 0;
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                if(mp.find(nums[j])==mp.end()){
                    if(nums[j]%2==0){
                        even++;
                    }
                    else{
                        odd++;
                    }
                    mp[nums[j]]++;
                }


                if(even == odd) maxlen = max(j-i+1,maxlen);
            }   
        }

        return maxlen;
                
    }   
    //[2,5,4,3]
    // 1 1 2 2  
};