class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int mindiff = INT_MAX;
        int ans = 0;

        for(int ind=0;ind<n-2;ind++){
            int start = ind+1;
            int end = n-1;

            int sum = nums[ind];

            while(start<end){
                sum += (nums[start]+nums[end]);
                int diff = abs(sum - target);
                if(sum>target){
                    if(diff < mindiff){
                        ans = sum;
                        mindiff = diff;
                    }
                    end--;
                }
                else if(sum< target){
                    if(diff<mindiff){
                        ans = sum;
                        mindiff = diff;
                    }
                    start++;
                }
                else{
                    return sum;
                }
                sum = nums[ind];
            }
        }

        return ans;

    }
};