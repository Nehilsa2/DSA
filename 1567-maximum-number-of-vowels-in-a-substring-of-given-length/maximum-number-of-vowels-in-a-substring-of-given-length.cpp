class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int n = s.length();
        int cntv = 0;
        int maxcnt = 0;

        while(j<n){
            char ch = s[j];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                cntv++;
            }
            
            if(j-i+1>k){
                char ch = s[i];
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                    cntv--;
                }
                i++;
            }

            if(j-i+1==k){
                maxcnt = max(maxcnt,cntv);
            }

            j++;
            
           
        }
        return maxcnt;
    }
};