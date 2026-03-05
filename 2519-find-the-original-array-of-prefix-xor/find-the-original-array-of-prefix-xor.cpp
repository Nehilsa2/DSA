class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>ans(n,0);
        ans[0] = pref[0];

        for(int i=1;i<n;i++){
            ans[i] = pref[i] ^ pref[i-1];
        }

        return ans;

        //ans[i] ^ ans[0] = pref[i]
        //ans[1] = pref[i] ^ ans[0]

        // ans[0]^ans[1]^ans[2] = pref[2];
        // ans[2] = pref[2]^ans[0]^ans[1]
        // ans[2] = pref[2]^pref[1];
    }
};