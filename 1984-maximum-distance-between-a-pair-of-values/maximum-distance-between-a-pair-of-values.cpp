class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxdist = INT_MIN;

        int n1 = nums1.size();
        int n2 = nums2.size();
        int j = n2-1;

        if(n1>n2){
            n1=n2;
        }

        for(int i=n1-1;i>=0;i--){
        
            while(j>=i && nums2[j]<nums1[i]){
                j--;
            }

            if(j>=i){
                maxdist = max(maxdist,j-i);
            }
        }

        return (maxdist==INT_MIN) ? 0:maxdist;
    }
};