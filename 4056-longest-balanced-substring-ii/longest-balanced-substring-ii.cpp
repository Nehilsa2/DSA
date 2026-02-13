class Solution {
public:
    struct comp {
        size_t operator()(const pair<int,int>& p) const {
            return hash<long long>()(((long long)p.first << 32) ^ p.second);
        }
    };
    int single(string &s,char x){
        int n = s.length();
        int maxlen = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]==x){
                cnt++;
                maxlen = max(maxlen ,cnt);
            }
            else{
                cnt = 0;
            }
        }

        return maxlen;
    }

    int two(string &s,char x,char y){
        unordered_map<int,int>mp;

        mp[0] = -1;
        int sum  = 0;
        int laststart=-1;
        int ans= 0;

        for(int i=0;i<s.size();i++){
            if(s[i]!=x && s[i]!=y){
                sum = 0;
                laststart = i;
                mp.clear();
                mp[0] = i;
                continue;
            }

            if(s[i]==x){
                sum++;
            }
            else{
                sum--;
            }

            if(mp.count(sum)){
                ans = max(i - mp[sum],ans);
            }
            else{
                mp[sum] = i;
            }
        }

        return ans;
    }
    int three(string &s){
        int a=0,b=0,c=0;

        unordered_map<pair<int,int>,int,comp> mp;

        mp[{0,0}] = -1;
        int ans = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;

            int d1 = a - b;
            int d2 = a - c;

            if(mp.count({d1,d2})){
                ans = max(ans, i - mp[{d1,d2}]);
            }
            else{
                mp[{d1,d2}] = i;
            }
        }

        return ans;
    }
    int longestBalanced(string s) {
        int ans = 0;

        int Abalance = single(s,'a');
        int Bbalance = single(s,'b');
        int Cbalance = single(s,'c');

        ans = max(ans,max(Abalance,max(Bbalance,Cbalance)));

        int ABbalance = two(s,'a','b');
        int ACbalance = two(s,'a','c');
        int BCbalance = two(s,'b','c');


        cout << BCbalance;
        ans = max(ans,max(ABbalance,max(BCbalance,ACbalance)));

        int ABCbalance = three(s);

        ans= max(ans,ABCbalance);
        

        return ans;
    }

};