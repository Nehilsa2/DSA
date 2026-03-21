class Solution {
public:
    int countbits(int x){ 
        int cnt = 0;
        while(x!=0){
            if(x&1!=0) cnt++;;

            x>>=1;
        }

        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countbits(i));
        }

        return ans;
    }
};