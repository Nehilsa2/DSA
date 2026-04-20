class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int maxdist = INT_MIN;
        for(int i=0;i<n;i++){
           //left
           int l = i-1;

           while(l>=0){
            if(colors[i]!=colors[l]){
                maxdist = max(maxdist,i-l);
            }
            l--;
           }
            int r = i+1;
            while(r<n){
                if(colors[i]!=colors[r]){
                    maxdist = max(maxdist,r-i);
                }
                r++;
            }
        }

        return maxdist;
    }
};