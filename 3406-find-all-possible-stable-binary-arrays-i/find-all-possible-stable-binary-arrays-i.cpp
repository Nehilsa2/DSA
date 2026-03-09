class Solution {
public:
    const int MOD = 1e9+7;
    int dp[201][201][2];

    int solve(int zerosleft,int onesleft,int lastwasone,int limit){
        if(zerosleft==0 && onesleft==0){
            return 1;
        }

        if(dp[zerosleft][onesleft][lastwasone]!=-1){
            return dp[zerosleft][onesleft][lastwasone];
        }

        int ans  = 0;

        if(lastwasone){  // we have explored all the possibilites with one now explore zeros
                for(int len=1;len<=min(zerosleft,limit);len++){
                    ans  = (ans + solve(zerosleft-len,onesleft,false,limit))%MOD;

                }
        }
        else{
                for(int len=1;len<=min(onesleft,limit);len++){
                    ans  = (ans + solve(zerosleft,onesleft-len,true,limit))%MOD;

                }
        }

        return dp[zerosleft][onesleft][lastwasone] = ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int startwithzero = solve(zero,one,false,limit);
        int startwithone = solve(zero,one,true,limit);


        return (startwithzero + startwithone) %MOD;
        
    }
};