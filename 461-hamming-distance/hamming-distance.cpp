class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x^y;
        int cnt = 0;

        while(temp!=0){
            if(temp&1==1) cnt++;

            temp = temp>>1;
        }

        return cnt;
    }
};