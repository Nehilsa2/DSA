class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());


        int i=0;
        int j=0;

        int lastone = -1;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j] && nums1[i]!=lastone){
                ans.push_back(nums1[i]);
                lastone = nums1[i];

                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};