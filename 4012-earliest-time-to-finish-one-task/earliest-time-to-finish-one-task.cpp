class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int earliest = INT_MAX;

        for(auto i:tasks){
            earliest = min(earliest,i[0] + i[1]);
        }

        return earliest;
    }
};