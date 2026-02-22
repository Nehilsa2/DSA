class Solution {
public:
    int binaryGap(int n) {
        int maxdist =0;
        int dist = 0;

        if(n==0) return 0;

        while ((n & 1) == 0) n >>= 1;

        n >>= 1;


        while(n){
            dist++;

            if (n&1) {
                maxdist = max(maxdist, dist);
                dist = 0;
            }
            n >>= 1;
        }

        return maxdist;
    }
};