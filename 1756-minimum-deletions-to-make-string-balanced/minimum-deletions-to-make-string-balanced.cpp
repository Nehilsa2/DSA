class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
    
        vector<int>acount(n,0);

        
        int acnt = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                acount[i] = acnt;
                acnt++;
            }
            else{
                acount[i] = acnt;
            }
        }

        int mindel = INT_MAX;
        int bcount = 0;

        for(int i=0;i<n;i++){
            mindel = min(mindel , bcount + acount[i]);

            if(s[i]=='b'){
                bcount++;
            }
        }

        return mindel;
    }
};