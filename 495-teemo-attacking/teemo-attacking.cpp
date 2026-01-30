class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        int n = timeSeries.size();
        int start = timeSeries[0];
        int end = start + duration-1;

        for(int i = 1; i < n; i++){
           int newtime = timeSeries[i];

           if(newtime>end){
                total+= end - start + 1;
           }
           else{
                total +=newtime - start; 
           }

           start = newtime;
           end = start + duration - 1;
        }

        total += end-start + 1;
    
        return total;
    }

    // when duration not end -> attack again-> timer reset -> posison end after the    duration

     
};