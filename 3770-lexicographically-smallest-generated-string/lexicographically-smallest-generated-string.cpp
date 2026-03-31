class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int sz = n + m - 1;

        vector<char> word(sz, 'a');
        vector<bool> locked(sz, false);

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(!locked[i + j]){
                        word[i + j] = str2[j];
                        locked[i + j] = true;
                    }
                    else if(word[i + j] != str2[j]){
                        return "";
                    }
                }
            }
        }

        //Handle 'F'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                bool match = true;

                for(int j = 0; j < m; j++){
                    if(word[i + j] != str2[j]){
                        match = false;
                        break;
                    }
                }

                if(match){
                    bool changed = false;

                    // go RIGHTMOST for lexicographic minimality
                    for(int j = m - 1; j >= 0; j--){
                        if(!locked[i + j]){
                            for(char c = 'a'; c <= 'z'; c++){
                                if(c != str2[j]){
                                    word[i + j] = c;
                                    changed = true;
                                    break;
                                }
                            }
                            if(changed) break;
                        }
                    }

                    if(!changed) return "";
                }
            }
        }

        return string(word.begin(), word.end());
    }
};