class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                
                int landEnd = landStartTime[i] + landDuration[i];
                int waterStart = max(landEnd, waterStartTime[j]);
                int finish1 = waterStart + waterDuration[j];

                int waterEnd = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterEnd, landStartTime[i]);
                int finish2 = landStart + landDuration[i];

                ans = min({ans, finish1, finish2});
            }
        }

        return ans;
    }
};