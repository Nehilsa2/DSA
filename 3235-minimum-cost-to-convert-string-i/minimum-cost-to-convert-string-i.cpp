class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>dist(26, vector<long long>(26, INT_MAX));

        for(int i=0;i<26;i++){
            dist[i][i] = 0;
        }

        for(int i=0;i<original.size();i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a' ;

            dist[u][v] = min((long long)cost[i],dist[u][v]);
        }


        for(int v=0;v<26;v++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][v] < INT_MAX && dist[v][j] < INT_MAX){
                    dist[i][j] = min(dist[i][j],dist[i][v] + dist[v][j]);
                    }
                }
            }
        }
        long long mincost = 0;

        for(int i=0;i<source.length();i++){
            int src = source[i]-'a';
            int tar = target[i]-'a';

            if(dist[src][tar]==INT_MAX) return -1;

            mincost += dist[src][tar];
        }

        
        return mincost;
    }
};