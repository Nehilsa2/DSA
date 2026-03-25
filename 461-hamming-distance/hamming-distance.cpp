class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x^y;
        int cnt = 0;

        while(temp!=0){
            temp = temp & (temp-1);
            cnt++;
        }

        return cnt;
    }
};