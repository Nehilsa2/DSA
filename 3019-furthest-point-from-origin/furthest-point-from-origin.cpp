class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int dist = 0;
        int l = 0;
        int r = 0;

        for(auto i :moves){
            if(i=='L'){
                l++;
            }
            else if(i=='R'){
                r++;
            }
        }

        if(l>=r){
            dist = r - l  - (n - (l+r));
        }
        else{
            dist = r - l + (n- (l+r));  
        }

        return abs(dist);
    }

   
};