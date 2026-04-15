class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(target==words[startIndex]){
            return 0;
        }
        int n = words.size();
        int mindist = INT_MAX;
        //check left
        int i = startIndex-1;

        while(((i+n)%n)!=startIndex){
            if(target==words[(i+n)%n]){
                mindist = min(mindist,abs(i-startIndex));
                break;
            }
            i--;
        }
        i = startIndex+1;
        while((i%n)!=startIndex){
            if(target==words[i%n]){
                mindist = min(mindist,abs(i-startIndex));
                break;
            }
            i++;
        }


        return (mindist==INT_MAX) ? -1 : mindist;
    }
};