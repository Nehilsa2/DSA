class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i=0,j=n-1;
        int maxdist = INT_MIN;
        while(i<j){
            if(colors[i]==colors[j]){
                j--;
            }
            else{
                maxdist = max(maxdist,abs(i-j));
                i++;
            }
        }
        i=0,j=n-1;
        
        while(i<j){
            if(colors[i]==colors[j]){
                i++;
            }
            else{
                maxdist = max(maxdist,abs(i-j));
                j--;
            }
        }
        return maxdist;
    }
};