class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int i=0;

        while(i<n){
            if(letters[i]>target){
                return letters[i];
            }
            i++;
        }

        return letters[0];

    }
};