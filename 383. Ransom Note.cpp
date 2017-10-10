class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters1[26];
        int letters2[26];
        for(int i = 0; i < 26; i++){
            letters1[i] = 0;
            letters2[i] = 0;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            letters1[ransomNote[i]-'a']++;
        }
        for(int i = 0; i < magazine.length(); i++){
            letters2[magazine[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(letters1[i] > letters2[i]) return false;
        }
        return true;
    }
};