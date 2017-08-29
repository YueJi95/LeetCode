class Solution {
public:
    string reverseString(string s) {
        for(int i = 0; i < s.size()/2; i++){
            char tem = s.at(i);
            s.at(i) = s.at(s.size() - i-1);
            s.at(s.size()-i-1) = tem;
        }
        return s;
    }
};