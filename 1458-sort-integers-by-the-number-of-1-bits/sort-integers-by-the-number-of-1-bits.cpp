class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int cnti = __builtin_popcount(arr[i]);  
                int cntj = __builtin_popcount(arr[j]);  

                if(cntj<cnti){
                    swap(arr[i],arr[j]);
                }
                else if(cntj==cnti && arr[j]<arr[i]){
                    swap(arr[i],arr[j]);
                }
            }
        }
        return arr;
    }
};