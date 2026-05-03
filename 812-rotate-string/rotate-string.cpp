class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();

        s = s+s;
        int i = 0;
        int j = 0;

        string temp = "";
        while(j<2*n){
            temp+=s[j];
            if(j-i+1>n){
                temp.erase(0,1);
                i++;
            }

            if(j-i+1==n){
                if(goal==temp){
                    return true;
                }
            }
            j++;
        }
        
        return false;
    }
};