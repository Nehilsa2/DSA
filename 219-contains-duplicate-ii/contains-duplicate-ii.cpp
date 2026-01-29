class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>lastindex;
        int n = nums.size();

        for(int i=0;i<n;i++){  //n
            if(lastindex.count(nums[i])){
                if(i-lastindex[nums[i]]<=k){
                    return true;
                }
            }
            lastindex[nums[i]] = i;
        }

        // for(auto v:mp){  // n -> worst case
        //     vector<int>temp = v.second;
        //     if(temp.size()>1){
                
        //         int n = temp.size();

        //         for(int i=1;i<n;i++){ // n-1
        //             if (abs(temp[i] - temp[i - 1]) <= k)
        //                 return true;
        //         }
                
        //     }
        // }

        return false;


    }
};