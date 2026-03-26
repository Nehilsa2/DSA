class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        string ans = "";

        for(int i:s){
            if(i!='-'){
                ans+=i;
            }
        }

        int len = ans.length();
        int ind = len-1;
        int temp = 0;

        s = "";

        while(ind>=0){
            s+=toupper(ans[ind]);
            temp++;

            if(temp%k==0 && ind!=0){
                s+='-';
            }
            ind--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};