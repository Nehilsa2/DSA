class Solution {
public:
    bool isprime(int num){
        
        if(num==1) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }

        return true;
    }
    bool countsetbits(int num){
        int cnt= 0;

        while(num){
            num = num & (num-1);
            cnt++;
        }

        

        if(isprime(cnt)) {
            return true;
        }

        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt =0;
        for(int i = left;i<=right;i++){
            
            if(countsetbits(i)){
                cnt++;
            }

        }

        return cnt;
    }
};