class Solution {
public:
    int maxlen = 1;
    int start = 0;

    void pallindrome(int l,int r,string s){
        int n = s.length();
        while(l>=0 && r<n && s[l]==s[r]){
            int currlen = r-l+1;

            if(currlen > maxlen){
                start = l;
                maxlen = currlen;
            }
            l--;
            r++;
        }
            
    }
    string longestPalindrome(string s) {
        int n = s.length();
        
        for(int i=0;i<n-1;i++){

            pallindrome(i,i,s);  //odd length
            pallindrome(i,i+1,s); //even length

        }

        return s.substr(start,maxlen);
    }
};