class Solution {
public:
    vector<int>h = {8,4,2,1};
    vector<int>m = {32,16,8,4,2,1};
    void findHours(int index ,int leds,int sum,set<int>&hrs){
        if(leds==0 && sum<=11){
            hrs.insert(sum);
            return;
        }

        if(sum>11 || index<0 || leds<0) return;

        findHours(index-1,leds-1,sum+h[index],hrs);
        findHours(index-1,leds,sum,hrs);

    }
    void findMins(int index , int leds,int sum,set<int>&mins){
        if(leds==0 && sum<=59){
            mins.insert(sum);
            return;
        }

        if(sum>59 || index<0 || leds<0) return;

        findMins(index-1,leds-1,sum+m[index],mins);
        findMins(index-1,leds,sum,mins);

    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        if(turnedOn>=9) return {};
        int hrs = 0;
        int mins = 0;

        for(int i=0;i<=3;i++){
            hrs = i;
            mins = turnedOn - i;
            set<int>hr,min;

            if(mins<0 || mins>5) continue;

            int hs = h.size();
            int ms = m.size();

            findHours(hs-1,hrs,0,hr);
            findMins(ms-1,mins,0,min);

            if(hr.empty()){
                for(auto j:min){
                    if(log10(j)+1 < 2){
                        ans.push_back("0:0" + to_string(j));
                    }
                    else{
                        ans.push_back("0:" + to_string(j));
                    }
                    
                }
            }

            else if(min.empty()){
                for(auto i:hr){
                    string mm = "00";
                    ans.push_back(to_string(i) + ":" + mm);
                }
            }
            else{
                for(auto i:hr){
                    for(auto j:min){
                    
                        string mm = (j < 10 ? "0" : "") + to_string(j);
                        ans.push_back(to_string(i) + ":" + mm);
                    }
                }
            }

            
        }

        return ans;
    }

    // maximum turn on for valid time = 8 leds

    //hour -> 8 4 2 1
    //MIN  -> 32 16 8 4 2 1
};