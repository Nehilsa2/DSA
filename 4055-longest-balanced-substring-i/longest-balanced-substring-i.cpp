class Solution {
public:

    bool isbalanced(int stat,int end,vector<int>&v,int curr){
        int n = v.size();
        for(int i=0;i<n;i++){
            if(v[i]!=0 && v[i]!=curr){
                return false;
            }
        }

        return true;
    }
    int longestBalanced(string s) {
        int maxlen = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            vector<int>v(26,0);
            for(int j=i;j<n;j++){
                v[s[j]-'a']++;
                if(isbalanced(i,j,v,v[s[j]-'a'])){
                    maxlen = max(maxlen,j-i+1);
                }
            }
        }

        return maxlen;
    }
};