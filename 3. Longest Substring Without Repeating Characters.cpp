class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1) return n;
        int max = 0;
        for(int i = 0; i < n; i++){
            bool flag[128];
            int count = 0;
            for(int j = 0; j < 128; j++) flag[j] = false;
            for(int j = i; j < n; j++){
                if(!flag[s[j]]){
                    flag[s[j]] = true;
                    count++;
                    if(max < count) max = count;
                }
                else{
                    if(max < count) max = count;
                    break;
                }
            }
        }
        return max;
    }
};