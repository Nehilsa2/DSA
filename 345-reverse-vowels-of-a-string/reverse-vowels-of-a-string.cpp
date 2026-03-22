class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int i=0;
        int j = n-1;

        while(i<=j){
            char c = tolower(s[i]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                char c1 = tolower(s[j]);
                if(c1=='a' || c1=='e' || c1=='i' || c1=='o' || c1=='u'){
                    swap(s[j],s[i]);
                    i++;
                    j--;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
            }
        }

        return s;
    }
};