class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt = 0;

        for (int x : nums) {
            int rem = k - x;

            if (mp[rem] > 0) {
                cnt++;
                mp[rem]--;
            } else {
                mp[x]++;
            }
        }

        return cnt;
    }
        //  i   j
    //[1,3,3,3,4]
};