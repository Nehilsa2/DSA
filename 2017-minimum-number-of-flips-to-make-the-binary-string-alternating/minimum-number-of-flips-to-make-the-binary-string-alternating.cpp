class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string t = s+s;

        string alt0 = "" , alt1 = "";
        for(int i=0;i<2*n;i++){
            alt0+= (i%2==0) ? '0' : '1';
            alt1+= (i%2==0) ? '1' : '0';
        }


        int diff1 = 0 , diff0 = 0;
        int ans = INT_MAX;

        int l = 0;

        for(int r = 0;r<2*n;r++){
            // for each window count the mismatch for both starting with 1 and 0 strings
                if(alt0[r]!=t[r]) diff0++;
                if(alt1[r]!=t[r]) diff1++;


                if(r-l+1 > n){
                    if(alt0[l]!=t[l]) diff0--;
                    if(alt1[l]!=t[l]) diff1--;
                    l++;
                }

                if(r-l+1==n){
                    ans = min(ans,min(diff1,diff0));
                }


        }
                return ans;

    }
};