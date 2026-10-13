class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int l = 0;
        int r = n-1;

        int need = (n+1)/2;

        while(need!=0){
            if(abs(nums[l])>abs(nums[r])){
                sum+= 1LL*(nums[l]*nums[l]);
                l++;
                need--;
            }
            else{
                sum+= 1LL*(nums[r]*nums[r]);
                r--;
                need--;
            }
        }


        while(l<r){
            sum-= 1LL*(nums[l]*nums[l]);
            sum-= 1LL*(nums[r]*nums[r]);
            l++;
            r--;
        }
        if(l==r){
            sum-= 1LL*(nums[l]*nums[l]);

        }

        return sum;
    }

//     ex: [3,2,4,1]  => []

//     ex: [8,2,5,6,1,4,9,7,0] 
//     0 1 2 4 5 6 7 8 9

// 9 0 8 1 7 2 6 4 5
};

// basically: the approach should be like we need to subtract the minimjm number square from the 
// sum

// [1,-1,2,-2,3,-3] 
// [-3,-2,-1,1,2,3]


// if n=6 we need 3 elements to add
// if n=7 we need 4 elements to add 