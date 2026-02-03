class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
        int n = nums.size();

        
        if(nums[0]>=nums[1] || nums[n-2] >= nums[n-1]){
            return false;
        }

        int i=2;

        while(i<n){
            if(nums[i]<=nums[i-1]){
                break;
            }
            i++;
        }

        // cout << i << endl;
        bool isdec = false;

        while(i<n){
            if(nums[i-1]<=nums[i]){
                break;
            }
            isdec = true;
            i++;
        }
        // cout << i << endl;


        while(i<n){
            if(nums[i-1]>=nums[i]){
                return false;
            }
            i++;
        }
        // cout << i << endl;

        return isdec;
    }
};