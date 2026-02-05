class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();

        int i=0;
        int j = n-1;
        bool ispos = true;
        int done = 0;


        while(i<=j){  
            
            if(s[i]!=s[j]){
                if(!done){
                    j--;
                    done = 1;
                    continue;
                }
                else{
                    ispos = false;
                    break;
                }
               
            }
            i++;
            j--;
        }

        bool ispos1 = true;
        done = 0;
        i=0;
        j=n-1;

        while(i<=j){  
            
            if(s[i]!=s[j]){
                if(!done){
                    i++;
                    done = 1;
                    continue;
                }
                else{
                    ispos1 = false;
                    break;
                }
               
            }
            i++;
            j--;
        }

        return ispos1 || ispos;


    }
};