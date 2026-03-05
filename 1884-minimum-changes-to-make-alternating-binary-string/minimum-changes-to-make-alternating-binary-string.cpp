class Solution {
public:
    int minOperations(string s) {
        
        int n = s.length();

        if(n==1) return 0;

        //start with 1
        
        //all even places should be one and all odds should be zero
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='1'){
                    cnt++;
                }
            }
            else{
                if(s[i]=='0'){
                    cnt++;
                }
            }
        }


        //start with 0
        int cnt1 = 0;
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='0'){
                    cnt1++;
                }
            }
            else{
                if(s[i]=='1'){
                    cnt1++;
                }
            }
        }

        return min(cnt,cnt1);
    }

    // 0101
    // 0101 || 1010
};