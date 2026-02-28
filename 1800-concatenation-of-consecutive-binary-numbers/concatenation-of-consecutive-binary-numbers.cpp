class Solution {
public:
    int findlen(int n){
        int len = 0;
        while(n!=0){
            n = n>>1;
            len++;
        }
        return len;
    }
    const int mod = 1000000007;
    int concatenatedBinary(int n) {
        long long ans = 0;
        
        for(int i = 1;i<=n;i++){
            int length = findlen(i);

            ans = ((ans<<length)%mod + i)%mod;
            
        }

        return ans%mod;
    }
};