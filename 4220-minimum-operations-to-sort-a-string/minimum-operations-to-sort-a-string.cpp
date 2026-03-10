class Solution {
public:

    bool isSorted(int start, int end, string &s){
        for(int i = start; i < end; i++){
            if(s[i] > s[i+1]) return false;
        }
        return true;
    }

    int minOperations(string s) {

        int n = s.length();

        if(n == 2 && !isSorted(0,1,s)) return -1;

        char mini = s[0];
        char maxi = s[0];

        for(char c : s){
            mini = min(mini, c);
            maxi = max(maxi, c);
        }

        if(s[0] == mini && s[n-1] == maxi){
            if(!isSorted(1,n-2,s)){
                return 1;
            }
            else{
                return 0;
            }
        }
            

        if((s[0] != mini && s[n-1] == maxi) || (s[0] == mini && s[n-1] != maxi))
            return 1;

       if(s[0]==maxi && s[n-1]==mini) 
        {
            for(int i=1;i<n-1;i++){
                if(s[i]==mini || s[i]==maxi) return 2;
            }
            return 3;
        }
        return 2;

    }
};