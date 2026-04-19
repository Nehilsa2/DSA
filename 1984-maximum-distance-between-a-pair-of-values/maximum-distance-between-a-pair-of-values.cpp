class Solution {
public:
    int bs(int num1 ,vector<int>& nums2,int i){
        int low = i;
        int high = nums2.size()-1;
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums2[mid]>=num1){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxdist = INT_MIN;

        int n1 = nums1.size();
        int n2 = nums2.size();


        for(int i=0;i<n1 && i<n2;i++){
            int justGreater = bs(nums1[i],nums2,i);
            
            if(justGreater!=-1){
                maxdist = max(maxdist,justGreater-i);
            }

        }

        return (maxdist==INT_MIN)? 0 : maxdist;
    }
};