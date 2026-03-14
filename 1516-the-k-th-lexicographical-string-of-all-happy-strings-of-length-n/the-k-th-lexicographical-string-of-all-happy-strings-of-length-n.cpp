class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 *(1<<(n-1));

        if(k>total)  return "";

        string ans = "";


        for(int pos=0;pos<n;pos++){

            for(char c:{'a','b','c'}){

                if(!ans.empty() && ans.back()==c) continue;

                int rempositions = n - 1 - pos;

                int posiblestrings = (1<<rempositions);

                if(k>posiblestrings){
                    k-=posiblestrings;
                }
                else{
                    ans.push_back(c);
                    break;
                }
            }
        }

        return ans;
    }
};