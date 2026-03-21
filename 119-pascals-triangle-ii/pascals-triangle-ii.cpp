class Solution {
public:
    vector<int> getRow(int rowIndex) {

        if(rowIndex==0)  return {1};
        else if(rowIndex==1) return {1,1};


        vector<int>lastrow = {1,1};
        int index = 2;

        while(index<=rowIndex){
            vector<int>temp;

            temp.push_back(1);

            for(int i=0;i<lastrow.size()-1;i++){
                temp.push_back(lastrow[i]+lastrow[i+1]);
            }
            temp.push_back(1);

            lastrow = temp;

            index++;
        }
        

        return lastrow;

    }
};