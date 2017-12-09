class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int n = s.length();
        if(numRows == 1) return s;
        else if(numRows == 2){
            for(int i = 0; i < n; i = i + 2){
                result.push_back(s[i]);
            }
            for(int i = 1; i < n; i = i + 2){
                result.push_back(s[i]);
            }
            return result;
        }
        vector<vector<char>> lines(numRows);
        bool flag = true;
        int pos = 0;
        for(int i = 0; i < n; i++){
            if(flag){
                lines[pos].push_back(s[i]);
                pos++;
                if(pos == numRows){
                    flag = false;
                    pos = numRows - 2;
                }
            }
            else{
                lines[pos].push_back(s[i]);
                pos--;
                if(pos < 0){
                    flag = true;
                    pos = 1;
                }
            }
        }
        
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < lines[i].size(); j++){
                result.push_back(lines[i][j]);
            }
        }
        return result;
    }
};