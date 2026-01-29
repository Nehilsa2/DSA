class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if(m>n) return -1;

        int i=0;
        int j=m-1;

        while(j<n){
            if(haystack.substr(i,m).compare(needle)==0){
                return i;
            }
            i++;
            j++;
        }

        return -1;
    }
};