class Solution {
public:
    char findTheDifference(string s, string t) {
        int count1[26];
        int count2[26];
        for(int i = 0; i < 26; i++){
            count1[i] = 0;
            count2[i] = 0;
        }
        for(int i = 0; i < s.length(); i++){
            count1[s[i]-'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            count2[t[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(count1[i] != count2[i]) return 'a' + i;
        }
    }
};