class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>>adj(n);

        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});

            adj[i[1]].push_back({i[0],2*i[2]});

        }

        vector<int>dist(n,INT_MAX);
        set<pair<int,int>>s;

        dist[0] = 0;
        s.insert({0,0});

        while(!s.empty()){
            auto it = s.begin();
            int weight = it->first;
            int u = it->second;

            s.erase(it);

            for(auto [v,wt] : adj[u]){
                

                    if(dist[u] + wt < dist[v]){

                        if(dist[v]!=INT_MAX){
                            s.erase({dist[v],v});
                        }

                        dist[v] = dist[u] + wt;
                        s.insert({dist[v],v});
                    }
            }
        }
        if(dist[n-1]==INT_MAX) return -1;
        return dist[n-1];
    }
};