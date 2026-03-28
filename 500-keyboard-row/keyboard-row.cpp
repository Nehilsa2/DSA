class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        unordered_map<char,int>row1,row2,row3;

        for(char i:"qwertyuiop"){
            row1[i]++;
        }

        for(char i:"asdfghjkl"){
            row2[i]++;
        }

        for(char i:"zxcvbnm"){
            row3[i]++;
        }

        

        vector<string>ans;

        for(string i:words){
            int currRow = -1;
            bool issamerow = true;
            for(char ch:i){
                ch = tolower(ch);
                
                if(row1[ch]==1){
                    if(currRow==-1){
                        currRow = 1;
                    }
                    else if(currRow!=1){
                        issamerow = false;
                        break;
                    }
                }
                else if(row2[ch]==1){
                   if(currRow==-1){
                        currRow = 2;
                    }
                    else if(currRow!=2){
                        issamerow = false;
                        break;
                    }
                }
                else{
                    if(currRow==-1){
                        currRow = 3;
                    }
                    else if(currRow!=3){
                        issamerow = false;
                        break;
                    }
                }
                
            }

            if(issamerow){
                ans.push_back(i);
            }
        }

        return ans;
    }
};