class Solution {
public:
    int countSegments(string s) {
        if(s.length()==0) return 0;
        
        int cnt = 0;
        char lastone = ' ';
        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i]==' ' && lastone!=' '){
                cnt++;
            }
            lastone = s[i];
        }

        if(s[n-1]!=' '){
            return cnt+1;

        }

        return cnt;
    }
};