class Solution {
public:
   

    char findKthBit(int n, int k) {
        string prev = "0";
        string curr = "0";

        for(int ind = 2;ind<=n;ind++){
            
            curr += "1";

            for(int i=prev.length()-1;i>=0;i--){
                if(prev[i]=='0'){
                    curr+='1';
                }
                else{
                    curr+='0';
                }
            }

            prev = curr;
            curr = prev;
        }

        int index = 0;
        for(int i=0;i<curr.length();i++){
            if(i==k-1) {
                index = i;
                break;
            }
        }

        return curr[index];
        
        
        
    }
};