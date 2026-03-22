class Solution {
public:
    string solve(string num1, string num2){
        string ans = "";
        int carry = 0;

        int i=num1.length()-1;
        int j=num2.length()-1;


        while(j>=0){
            int sum = num1[i]-'0' + num2[j]-'0' + carry;

            carry = sum/10;

            ans += to_string(sum%10);    
            i--;
            j--;  
        }

        while(i>=0){
            int sum = num1[i]-'0'  + carry;

            carry = sum/10;
            ans += to_string(sum%10);    
            i--;
        }

        if(carry==1){
            ans+='1';
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
    string addStrings(string num1, string num2) {
        string ans;
        if(num1.length()>=num2.length()){
            ans = solve(num1,num2);
        }
        else{
            ans = solve(num2,num1);
        }

        return ans;
    }

    // 9956 
    //   77
}; //    33