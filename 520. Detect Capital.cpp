class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first = false;
        bool second = false;
        for(int i = 0; i < word.length(); i++){
            char tem = word[i];
            if ('A' <= tem && tem <= 'Z'){
                if(i == 0) first = true;
                else if(i == 1){
                    if(first == false) return false;
                    second = true;
                }
                else{
                    if((first && second) == false) return false;
                }
            }
            else if(i >= 2){
                if(first && second == true) return false;
            }
        }
        return true;
    }
};