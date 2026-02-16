class Solution {
public:
    void findbinary(int n,string &s){
        while(n){
            s+=char((n%2)+'0');
            n=n/2;
        }
        while(s.length() < 32){
            s += '0';
        }
    }
    int decimal(string s){
        int number = 0;
        for(int i = 31; i >= 0; i--){
            number += (s[i] - '0') * (1 << (31 - i));
        }

        return number;
    }
    int reverseBits(int n) {
        string s = "";

        findbinary(n,s);
        return decimal(s);

    }
};