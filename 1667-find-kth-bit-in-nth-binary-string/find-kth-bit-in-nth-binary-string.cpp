class Solution {
public:
   

    char findKthBit(int n, int k) {
        string prev = "0";
        string curr = "0";

        for(int ind = 2;ind<=n;ind++){  //0(n)
            
            curr += "1";

            for(int i=prev.length()-1;i>=0;i--){ // o(len)
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

        int required = k-1;
        int index = 0;

        int low = 0;
        int high = curr.length()-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(mid==required){
                index = mid;
                break;
            }
            else if(mid>required){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return curr[index];
        
        
        
    }
};