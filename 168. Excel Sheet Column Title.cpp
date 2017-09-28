class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n > 0){
            s = string(1, (char)('A' + (((long)n+25) % 26) )) + s;
            n = (n-1) / 26;
        }
        return s;
    }
};