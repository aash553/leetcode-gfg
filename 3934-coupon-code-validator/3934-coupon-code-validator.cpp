class Solution {
public:

    bool validcode(const string &s){
        if (s.empty()) return false;
        for ( char ch : s ){
            if(!(isalnum(ch) || ch == '_' )){
                return false;
            }
        }
        return true;
    }

   bool validbusiness(const string &s){
    return s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant";
   } 

   bool validactive(bool status){
    return status == true;
   }

    bool isvalid(const string& codeStr, const string& business, bool isActiveStatus){
    return validcode(codeStr) && validbusiness(business) && validactive(isActiveStatus);
    }
   

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<pair<string, string>> validCoupons;
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        int n = code.size();
        for (int i = 0; i < n; i++) {
            if (isvalid(code[i], businessLine[i], isActive[i])) {
                validCoupons.push_back({businessLine[i], code[i]});
            }
        }
         sort(validCoupons.begin(), validCoupons.end(), [&](auto &a, auto &b) {
            if (order[a.first] != order[b.first])
                return order[a.first] < order[b.first];
            return a.second < b.second; 
        });
        vector<string> result;
        for (auto &entry : validCoupons) {
            result.push_back(entry.second);
        }
        return result;
    }
};