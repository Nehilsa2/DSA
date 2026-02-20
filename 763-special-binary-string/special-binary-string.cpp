class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, start = 0;
        vector<string> res;
        
        for (int j = 0; j < s.size(); ++j) {    
            if (s[j] == '1') count++;
            else count--;
            
            if (count == 0) {
                string inner =  makeLargestSpecial(s.substr(start + 1, j - start - 1));
                string result = "1" + inner + "0";
                res.push_back(result);
                start = j + 1;
            }


        }
        
        sort(res.rbegin(), res.rend());
        string ans = "";
        for (const string& str : res) {
            ans += str;
        }
        
        return ans;
    }
};