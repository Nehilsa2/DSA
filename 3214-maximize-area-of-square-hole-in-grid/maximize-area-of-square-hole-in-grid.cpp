class Solution {
public:
    int longestHole(vector<int>& a) {
        if (a.empty()) return 1;

        sort(a.begin(), a.end());

        int best = 1;
        int cur = 1;

        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i-1] + 1) {
                cur++;
            } else if (a[i] != a[i-1]) {
                best = max(best, cur);
                cur = 1;
            }
        }

        best = max(best, cur);

        
        return best + 1;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int H = longestHole(hBars);
        int V = longestHole(vBars);

        int side = min(H, V);
        return side * side;
    }
};
