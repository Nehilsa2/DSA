class Solution {
public:
    bool check(string &s, int len){
    int n = s.size();

        for(int i = len; i < n; i++){
            if(s[i] != s[i % len]){
                return false;
            }
        }
        return true;
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int len = 1; len <= n/2; len++){
            if(n % len == 0 && check(s, len)){
                return true;
            }   
        }

        return false;
    }
};