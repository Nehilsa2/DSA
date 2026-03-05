class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();

        for(int i=0;i<n-1;i++){
            int temp1 = arr[i];
            for(int j=i+1;j<n;j++){
                temp1 = temp1 ^ arr[j];

                if(temp1==0) cnt+=j-i;
            }
        }

        return cnt;
    }
};