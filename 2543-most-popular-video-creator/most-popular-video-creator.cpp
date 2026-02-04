class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {

        map<pair<string,string>,long long>mp_creator_id;
        unordered_map<string,long long>mp_creator_views;
        unordered_map<string,string>mp;

        int n = creators.size();

        long long maxpop = LLONG_MIN;

        for(int i=0;i<n;i++){ //o(n)
            mp_creator_views[creators[i]] += 1LL*views[i];

            maxpop = max(maxpop,mp_creator_views[creators[i]]);

            mp_creator_id[{creators[i],ids[i]}]+= 1LL*views[i];
        }

        vector<vector<string>>ans;

        for (auto it = mp_creator_views.begin(); it != mp_creator_views.end(); ) {
            if (it->second != maxpop) {
                it = mp_creator_views.erase(it); 
            }        
            else {
                ++it;
            }
        }
        string creator = "";
        string id = "";
        long long view = 0;

        for(auto i:mp_creator_id){ //o(n)

            if(mp_creator_views.count(i.first.first)==0) continue;
            
            if(creator==""){
                creator = i.first.first;
                id = i.first.second;
                view = i.second;
                mp[creator] = id;
            }
            else if(creator == i.first.first){
                if(i.second > view ||                              
                   (i.second == view && i.first.second < id)){
                    view = i.second;
                    id = i.first.second;
                    mp[creator] = id;
                }
            }
            else{
                creator = i.first.first;
                id = i.first.second;
                view = i.second;
                mp[creator] = id;
            }
              
        }
         
        for(auto i:mp_creator_views){
            ans.push_back({i.first,mp[i.first]});
        }


        return ans;


    }

    //
};