class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int count0=0,count1=0;
        int ans = 0;
        int n = s.length();

        for(int i=0;i<n;i++){
           if(s[i]=='0'){
            count0++;

            if(count1>=count0 ){
                ans++;
            }

            
            

            if(i<n-1 && s[i+1]=='1'){
                count1 = 0;
            }
           }
           else{
            count1++;

            if(count0>=count1){
                ans++;
            }
        

            if(i<n-1 && s[i+1]=='0'){
                count0 = 0;
            }
           }
        }

        return ans;

    }
};