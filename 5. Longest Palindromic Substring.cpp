class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max = 0;
        int index1 = 0;
        int index2 = 0;
        bool dp[n][n];
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(s[i] != s[j]) dp[i][j] = false;
                else if(j == i+1) dp[i][j] = true;
                else dp[i][j] = dp[i+1][j-1];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(!dp[i][j]) continue;
                if(max < j - i + 1){
                    max = j - i + 1;
                    index1 = i;
                    index2 = j;
                }
            }
        }
        string r;
        for(int i = index1; i <= index2; i++){
            r.push_back(s[i]);
        }
        return r;
    }
};