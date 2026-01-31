class Solution {
public:
    bool binarysearch(int low,int high,vector<int>&nums,int ele,bool find){

        while(low<=high){
            int mid = low + (high-low)/2;
            if(find){
                if(nums[mid]<ele){
                    return true;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                if(nums[mid]>ele){
                    return true;
                }
                else{
                    low = mid+1;
                }
            }   
        }

        return false;
    }
    int countElements(vector<int>& nums) {
        // sort and apply binary search nlogn

        sort(nums.begin(),nums.end());
        int n = nums.size();

        if(n<=2){
            return 0;
        }

        int cnt = 0;
        for(int i=1;i<n-1;i++){
            int cur = nums[i];

            bool issmall = binarysearch(0,i-1,nums,cur,true);
            bool islarge = binarysearch(i+1,n-1,nums,cur,false);

            if(issmall && islarge){
                cnt++;
            }
        }

        return cnt;
    }

    // [2,7,11,15]
};