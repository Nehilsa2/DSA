class Solution {
public:
    int n;
    int binarytodecimal(string s){
        int ans = 0;

        for(int i=0;i<n;i++){
            ans += (1<<(n-i-1)) * (s[i]-'0');
        }

        return ans;
    }

    string decimaltobinary(int num){
        string ans="";

        while(num){
            ans += (num%2)+'0';
            num/=2;
        }

        reverse(ans.begin(),ans.end());

        while(ans.size()<n) ans="0"+ans;

        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,int>mp;
        n = nums.size();

        for(int i=0;i<n;i++){
            int num = binarytodecimal(nums[i]);
            mp[num]++;
        }

        int maxi = (1<<n) -1;

        int number = 0;

        for(int i=0;i<=maxi;i++){
            if(mp.count(i)==0){
                number = i;
                break;
            }
        }

        return decimaltobinary(number);
    }
};