class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        int totalv = 0;
        int totalc = 0;

        for(auto i :s){
            mp[i]++;
        }
        for(auto i:mp){
            char ch = i.first;
            if(ch=='a' || ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                totalv=max(totalv,i.second);
            }
            else{
                totalc = max(totalc,i.second);
            }
        }

        
      return totalv+totalc;


    }
};