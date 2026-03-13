class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        priority_queue<pair<pair<long long,long long>,long long>,
        vector<pair<pair<long long,long long>,long long>>,
        greater<>> pq;

        for(auto t : workerTimes){
            pq.push({{t,1},t});
        }

        long long totaltime = 0;

        while(mountainHeight--){
            auto top = pq.top();
            pq.pop();

            long long time = top.first.first;
            long long turn = top.first.second;
            long long t = top.second;

            totaltime = max(totaltime,time);

            pq.push({{time + t*(turn+1),turn+1},t});
        }

        return totaltime;
    }
};