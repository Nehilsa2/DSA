class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;

        for(int i:n){
            maxi = max(maxi , i-'0');
        }
        return maxi;
    }
};