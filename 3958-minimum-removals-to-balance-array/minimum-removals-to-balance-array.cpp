class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int mindel = INT_MAX;

        if(n<=1) return 0;

        int i = 0;
        int j = 1;

        int mini = 0;

        while(j<n){
           if(1LL*nums[i]*k>=1LL*nums[j]){
                mindel = min(mindel , i+ n-(j+1));
                j++;
           }
           else{
              i++;
           }
        }

        return mindel;

    }
            // ij
    // [1,2,5,6]


};