class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int titleNumber = 0;

        for(int i=0;i<n;i++){
            titleNumber += ((columnTitle[n-i-1] - 'A' + 1) * pow(26,i));
        }

        return titleNumber;
    }
};