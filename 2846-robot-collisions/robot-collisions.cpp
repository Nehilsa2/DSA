class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<tuple<int,int,char,int>> robots;
        for(int i=0;i<n;i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        vector<tuple<int,int,char,int>> st;

        for(auto &robot : robots){
            auto [pos, health, dir, idx] = robot;

            bool alive = true;

            while(!st.empty() && get<2>(st.back())=='R' && dir=='L'){
                auto &[p2, h2, d2, i2] = st.back();

                if(h2 > health){
                    h2--;
                    alive = false;
                    break;
                }
                else if(h2 < health){
                    health--;
                    st.pop_back();
                }
                else{
                    st.pop_back();
                    alive = false;
                    break;
                }
            }

            if(alive){
                st.push_back({pos, health, dir, idx});
            }
        }

        vector<int> ans(n, 0);

        for(auto &[pos, health, dir, idx] : st){
            ans[idx] = health;
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(ans[i] > 0) res.push_back(ans[i]);
        }

        return res;
    }
};