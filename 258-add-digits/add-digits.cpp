class Solution {
public:
    int addDigits(int num) {
        int newn = num;

        while((newn/10)!=0){
            int sum = 0;
            while(num){
                sum+= (num%10);
                num/=10; 
            }
            newn = sum;
            num = newn;
           
        }
        return newn;
    }

    
};