class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        int i=0;
        int j=0;
        int n = s1.length();

        while(j<n){
            if(j-i>2){
                i++;
            }
            if(j-i==2){
                if(s1[i]==s2[i]){
                    if(s1[j]!=s2[j]){
                        return false;
                    }
                }
                else{
                    if(s1[i]!=s2[j] || s1[j]!=s2[i]){
                        return false;
                    }
                }
            }
            j++;
        }

        return true;
    }
};