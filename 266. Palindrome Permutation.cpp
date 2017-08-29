class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> list(128, 0);
        for(int i = 0; i < s.size(); i++){
            list[s.at(i)]++;
        }
        int count = 0;
        for(int i = 0; i < 128; i++){
            if(list[i] % 2 != 0) count++;
        }
        if(count <= 1) return true;
        else return false;
    }
};