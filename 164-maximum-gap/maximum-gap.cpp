class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        if(n<2) return 0;

        priority_queue<int>pq;

        for(int i:nums){
            pq.push(i);
        }

        while(pq.size()>=2){
            int prev = pq.top();
            pq.pop();

            int curr = pq.top();

            maxi = max(prev-curr,maxi);
        }

        return maxi;
    }
};