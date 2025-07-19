class Solution {
public:

    bool validcode( const string & s){
        if(s.empty()) return false;
        for(char ch : s){
            if(!(isalnum(ch) || ch == '_')){
                return false;
            }
        }
        return true;
    }

    bool validbusiness(const string &s){
        return s == "electronics" || s == "grocery" || s == "pharmacy" || s =="restaurant" ;
    }

    bool validactive(bool status){

    return status == true;
    }

    
    bool isvalid(const string &abc , const string & def , bool ghi){
        return validcode(abc) && validbusiness(def) && validactive(ghi);
    }


    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>result;
        vector<pair<string,string>>validcoupons;

        unordered_map<string,int>order = {
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };

        int n = code.size();
        for(int i =0;i<n;i++){
            if(isvalid(code[i],businessLine[i],isActive[i])){
                validcoupons.push_back({businessLine[i],code[i]});
            }
        }

        sort(validcoupons.begin(), validcoupons.end() ,[&] (auto &a, auto &b){
            if(order[a.first]!=order[b.first])
                return order[a.first] < order[b.first];
            return a.second < b.second;
        });

        for(auto &entry : validcoupons){
            result.push_back(entry.second);
        }
        return result;
    }
};