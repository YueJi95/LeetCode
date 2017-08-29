class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+'){
                if(i < s.size()-1 && s[i+1] == '+'){
                    string t = s;
                    t.at(i) = '-';
                    t.at(i+1) = '-';
                    result.push_back(t);
                }
            }
        }
        return result;
    }
};