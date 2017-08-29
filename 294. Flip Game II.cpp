class Solution {
public:
    bool canWin(string s) {
        if(s.size() == 0 || s.size() == 1) return false;
        bool exist = false;
        bool result = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+'){
                if(i < s.size()-1 && s[i+1] == '+'){
                    string t = s;
                    t.at(i) = '-';
                    t.at(i+1) = '-';
                    exist = true;
                    bool tem = true;
                    for(int j = 0; j < t.size(); j++){
                        if(t[j] == '+'){
                             if(j < t.size()-1 && t[j+1] == '+'){
                                 string m = t;
                                 m.at(j) = '-';
                                 m.at(j+1) = '-';
                                 if(m == s) continue;
                                 if(canWin(m) == false){
                                     tem = false;
                                     break;
                                 }
                             }
                        }
                    }
                    result = result | tem;
                }
            }
        }
        return exist & result;
    }
};