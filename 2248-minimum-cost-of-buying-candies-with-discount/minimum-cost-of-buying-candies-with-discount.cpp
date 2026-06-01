class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n = cost.size();

        for(int i=0;i<n;i++){
            cout << cost[i] << " "  ;
        }

        int cst = 0;
        int cand = 0;

        for(int i=n-1;i>=0;i--){
            if(cand%2==0 && cand!=0){
                cand=0;
                continue;
            }
            cand++;
            cst+=cost[i];
        }

        return cst;

    }

    
};