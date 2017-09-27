class Solution {
public:
    string findContestMatch(int n) {
        string result = output(1, 2, 2, n);
        return result;
    }
    
    string output(int x, int y, int c, int n){
        string result = "(";
        if(c == n) result = result + to_string(x) + "," + to_string(y) + ")";
        else result = result + output(x, 2*c-x+1, 2*c, n) + "," + output(y, 2*c-y+1, 2*c, n) + ")";
        return result;
    }
};