class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxbhole  = INT_MIN;
        int maxlhole = INT_MIN;

        int x = hBars.size();
        int y = vBars.size();

        unordered_map<int,int>mph,mpv;

        for(int i=0;i<x;i++){
            mph[hBars[i]]++;
        }

        for(int i=0;i<y;i++){
            mpv[vBars[i]]++;
        }

        for(int i=0;i<x;i++){
            int currbar = hBars[i];

            int temp = currbar+1;


            while(mph.count(temp)>0){
                temp++;
            }

            int bottomlim = temp;

            cout << "bottomlim "<<bottomlim<<endl;

            temp = currbar-1;

            while(mph.count(temp)>0){
                temp--;
            }

            int upperlim = temp;

            cout << "upperlim " << upperlim <<endl;
            maxbhole = max(maxbhole , bottomlim - upperlim);
        }

        cout << "mbh " << maxbhole << endl;

        for(int i=0;i<y;i++){
            int currbar = vBars[i];

            int temp = currbar+1;


            while(mpv.count(temp)>0){
                temp++;
            }

            int rightlim = temp;

            cout<<"rightlim "<<rightlim<<endl;

            temp = currbar-1;

            while(mpv.count(temp)>0){
                temp--;
            }

            int leftlim = temp;
            cout<<"leftlim "<<leftlim<<endl;
            maxlhole = max(maxlhole , rightlim - leftlim);

            cout << "mlh " << maxlhole << endl; 
        }

        int mini = min(maxlhole,maxbhole);

        cout<<mini<<endl;

        return mini*mini;
    }
};