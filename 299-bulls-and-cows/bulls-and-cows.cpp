class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp;
        int n = secret.length();

        for(int i=0;i<n;i++){
            mp[secret[i]]++;
        }
        
        string ans = "";
        int cow = 0,bulls = 0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                mp[secret[i]]--;
                cow++;
            }
        }

        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]){
                if(mp.find(guess[i])!=mp.end() && mp[guess[i]]!=0){
                    bulls++;
                    mp[guess[i]]--;
                }
            }
            
        }

        ans += to_string(cow) + "A" + to_string(bulls) + "B";
        return ans;
    }

    //[1->2,2->1,3->1] 

    // "0321"  B=3  A=1
    //     
    // "0111"
};