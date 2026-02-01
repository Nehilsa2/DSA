class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int n = nums.size();

        int cost = nums[0];

        for(int i=1;i<n;i++){
            int curr = nums[i];

            if(curr < min1){
                min2 = min1;
                min1 = curr;
            }
            else if(curr<min2){
                min2 = curr;
            }

            // cout<<"min1 " << min1<<endl;
            // cout<<"min2 " << min2<<endl;

        }


        if(min1!=INT_MAX){
            cost+=min1;
        }

        if(min2!=INT_MAX){
            cost+=min2;
        }

        return cost;
    }

    //[10,3,1,1]

};