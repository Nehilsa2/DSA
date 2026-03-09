class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }

        if(n==2){
            if(k==1){
                return 0;
            }
            else{
                return 1;
            }
        }

        int len = 1<<(n-1);
        int mid = len/2;

        if(k>mid){
            int new_k = k-mid;
            return (kthGrammar(n-1,new_k)==0) ? 1:0;
        }
        
        return kthGrammar(n-1,k);
         
    }

    //number of elements? 2^(n-1)

    // k from n 

    // if(k>mid){
    //     (n-k-1,n-1)
    // }

    // if(n-k-1 >mid){
    //     (n-(n-k-1)-1,n-1)
    // }


    // // 0 
    // // 01 
    // // 0123    
    // // 0110 
    // // 01101001
    // // 0110100110010110
    // 01101001100101101001011001101001
    

};