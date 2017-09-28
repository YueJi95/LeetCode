class Solution {
public:
    int titleToNumber(string s) {
        if(s.length() == 0) return 0;
        int result = 0;
        for(int i = 0; i < s.length(); i++){
            result = result * 26;
            result = result + (s[i] - 'A' + 1);
        }
        return result;
    }
};