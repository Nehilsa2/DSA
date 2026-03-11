class Solution {
public:
    int bitwiseComplement(int n) {
       

        if(n==0) return 1;
        int len = floor(log2(n)) + 1;
        int mask = (1<<len) - 1;

        int ans = n^mask;

        return ans;
    }
};