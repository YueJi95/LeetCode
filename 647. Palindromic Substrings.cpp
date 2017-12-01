class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < n; j++){
                bool flag = true;
                if(j + i - 1 >= n) break;
                for(int k = 0; k < i; k++){
                    if(s[j+k] != s[j+i-k-1]){
                        flag = false;
                        break;
                    }
                }
                if(flag == true) count++;
            }
        }
        return count;
    }
};