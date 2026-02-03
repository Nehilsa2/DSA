class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        bool isodd = true;

        if(n%2==0){
            isodd = false;
        }

            for(int i=1;i<=n/2;i++){
                ans.push_back(i);

            }
            if(isodd){
                ans.push_back(0);
            }
            for(int i=n/2;i>=1;i--){
                ans.push_back(-i);
            }
        
        return ans;
        
    }
};