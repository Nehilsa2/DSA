class Solution {
public:
int cnt = 0;
    void pallindrome(int l,int r,string s){
        int n = s.length();
        while(l>=0 && r<n && s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
            
    }
    int countSubstrings(string s) {
        int n = s.length();
        
        for(int i=0;i<n;i++){

            pallindrome(i,i,s);  
            pallindrome(i,i+1,s); 

        }

        return cnt;
    }
};