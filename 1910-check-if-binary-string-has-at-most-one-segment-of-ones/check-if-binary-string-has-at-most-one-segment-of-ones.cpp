class Solution {
public:
    bool checkOnesSegment(string s) {
        int seg = 0,n = s.length();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }
            else if(cnt>=1){
                seg++;
                cnt = 0;
            }
        }

        if(cnt>=1){
            seg++;
        }


        if(seg>1 || seg==0) return false;
        
        return true;
    }
};