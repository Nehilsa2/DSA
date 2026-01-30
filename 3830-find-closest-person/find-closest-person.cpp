class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist_x_z = abs(z-x);
        int dist_y_z = abs(z-y);


        if(dist_x_z>dist_y_z){
            return 2;
        }
        else if(dist_x_z < dist_y_z){
            return 1;
        }

        return 0;
    }
};