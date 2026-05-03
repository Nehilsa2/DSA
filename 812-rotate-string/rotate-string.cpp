class Solution {
public:
    bool rotateString(string s, string goal) {
        int sh = s.length();

        for(int i=1;i<=sh;i++){
            reverse(s.begin(),s.begin()+1);
            reverse(s.begin()+1,s.end());
            reverse(s.begin(),s.end());

            if(s==goal){
                return true;
            }
        }

        return false;
    }
};