class Solution {
public:
    int findzeros(vector<int>v){
        int n =  v.size();
        int zeros = 0;
        for(int i=n-1;i>=0;i--){
            if(v[i]!=0){
                return zeros;
            }
            else{
                zeros++;
            }
        }
        return zeros;
    }
    bool check(vector<vector<int>>&grid){
        int n = grid.size();
        int zeros = n-1;

        for(int i=0;i<n;i++){
            if(findzeros(grid[i])<zeros){
                return false;
            }
            else{
                zeros--;
            }
        }

        return true;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int swaps = 0;

        int maxextreme = 0;
        int maxindex = n-1;
        int minindex = 0;
        int minextreme = n-1;
        int i = minindex;
        while(i<=maxindex){
            if(check(grid)) return swaps;

            int zeros = findzeros(grid[i]);

            if(zeros==maxextreme){
                if(i!=maxindex){
                    int j = i;
                    while(j<maxindex){
                        swap(grid[j],grid[j+1]);
                        j++;
                        swaps++;
                    }
                }
                maxextreme++;
                maxindex--;
                 
            }

            else if(zeros>=minextreme){
                if(i!=minindex){
                    int j = i;
                    while(j>minindex){
                        swap(grid[j],grid[j-1]);
                        j--;
                        swaps++;
                    }
                }
                
                minextreme--;
                minindex++;
            }
            else{
                i++;
                continue;
            }
            i = minindex;
        }

        
        if(!check(grid)) return -1;
        
        return swaps;;
    }
};