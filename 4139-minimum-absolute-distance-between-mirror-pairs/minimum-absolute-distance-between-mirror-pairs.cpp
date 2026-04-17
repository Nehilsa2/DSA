class Solution {
public:
    int findMirror(int nums){
        
        int num = 0;

        while(nums!=0){
            int rem = nums%10;
            num = num*10 + rem;

            nums/=10;
        }

        return num;
        
    }


    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,deque<int>>mp;
        vector<int>mirror;
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            int num = findMirror(nums[i]);
            
            if(mp.find(num)!=mp.end() && !mp[num].empty()){
                deque<int>dq = mp[num];
                

                while(!dq.empty() && dq.front()<=i){
                    dq.pop_front();
                }

                if(!dq.empty()){
                    ans = min(ans,abs(i-dq.front()));
                }

                if(ans==1){
                    return 1;
                }
            }
        }

        return (ans==INT_MAX)? -1:ans;
    }

    //[21,12,54,33,45]
    //[12,21,45,33,54]
};