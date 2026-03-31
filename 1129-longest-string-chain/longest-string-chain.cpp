class Solution {
public:
    static bool cmp(string &s1,string &s2){
        return s1.length() < s2.length();
    }

    bool compare(string s1,string s2){
        int n1 = s1.size();
        int n2 = s2.size();

        
        if(n1 != n2+1) return false;

        int i = 0;
        int j = 0;
        int mismatch = 0;
        while(i<n1){

            if(j<n2 && s1[i]==s2[j]){
                j++;
                i++;
                
            }
            else{
                i++;
                mismatch++;

                if(mismatch>1) return false;
            }
        }

        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(),words.end(),cmp);

        vector<int>dp(n,1);
        int maxi  = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(compare(words[i],words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1; 
                }

                maxi = max(maxi,dp[i]);
            }
        }

        return maxi;
        
    }
};