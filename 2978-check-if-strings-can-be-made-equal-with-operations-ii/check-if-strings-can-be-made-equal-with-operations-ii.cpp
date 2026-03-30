class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>mpO,mpE;

        int n = s1.length(); 

        for(int i=0;i<n;i++){
            if(i&1){
                mpO[s1[i]]++;
                if(mpO[s1[i]]==0){
                    mpO.erase(s1[i]);
                }

                mpO[s2[i]]--;
                if(mpO[s2[i]]==0){
                    mpO.erase(s2[i]);
                }

            }
            else{
                mpE[s1[i]]++;
                if(mpE[s1[i]]==0){
                    mpE.erase(s1[i]);
                }

                mpE[s2[i]]--;

                if(mpE[s2[i]]==0){
                    mpE.erase(s2[i]);
                }
                
            }
        }

        return (mpO.size()==0 && mpE.size()==0);
    }
};