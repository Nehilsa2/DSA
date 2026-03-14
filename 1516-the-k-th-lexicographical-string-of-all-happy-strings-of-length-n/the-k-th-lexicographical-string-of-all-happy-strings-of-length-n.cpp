class Solution {
public:
    string res = "";

    void solve(int n, int &k, string &curr){
        
        if(curr.length() == n){
            k--;
            if(k == 0) res = curr;
            return;
        }

        for(char c : {'a','b','c'}){
            if(!curr.empty() && curr.back() == c) continue;

            curr.push_back(c);

            solve(n,k,curr);

            if(k == 0) return;

            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        solve(n,k,curr);
        return res;
    }
};