class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long  maxi =  LLONG_MIN;
        long long  secondmaxi = LLONG_MIN;
        long long thirdmaxi = LLONG_MIN;


        for(int i=0;i<nums.size();i++){
            if(1LL*nums[i]>maxi){
                thirdmaxi = secondmaxi;
                secondmaxi = maxi;
                maxi = 1LL*nums[i];
            }
            else if(1LL*nums[i]>secondmaxi && 1LL*nums[i]<maxi){
                thirdmaxi = secondmaxi;
                secondmaxi = 1LL*nums[i];
            }
            else if(1LL*nums[i]>thirdmaxi && 1LL*nums[i]<secondmaxi){
                thirdmaxi = 1LL*nums[i];
            }
        }

        return (thirdmaxi==LLONG_MIN) ? int(maxi) : int(thirdmaxi);
    }
};