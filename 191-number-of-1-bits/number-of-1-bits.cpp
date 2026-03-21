class Solution {
public:
    int hammingWeight(int n) {
        int cnt = __builtin_popcount(n);
        return cnt;
    }
};