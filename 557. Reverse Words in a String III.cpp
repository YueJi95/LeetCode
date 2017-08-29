class Solution {
public:
    string reverseWords(string s) {
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            if(s.at(i) != ' ')  continue;
            int length = i - index;
            for(int j = 0; j < length/2; j++){
                char tem = s.at(index + j);
                s.at(index + j) = s.at(index + length-j-1);
                s.at(index + length-j-1) = tem;
            }
            index = i + 1;
        }
        int length = s.size() - index;
        for(int j = 0; j < length/2; j++){
            char tem = s.at(index + j);
            s.at(index + j) = s.at(index + length-j-1);                
            s.at(index + length-j-1) = tem;
        }
        return s;
    }
};