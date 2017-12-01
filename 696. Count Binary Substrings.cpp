class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int n = s.size();
        if(n == 1) return 0;
        int countpre = -1;
        int countcur = 1;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]) countcur++;
            else{
                if(countpre == -1){
                    countpre = countcur;
                    countcur = 1;
                    continue;
                }
                if(countpre <= countcur) count = count + countpre;
                else count = count + countcur;
                countpre = countcur;
                countcur = 1;
            }
        }
        if(countpre != -1){
            if(countpre <= countcur) count = count + countpre;
            else count = count + countcur;
        }
        return count;
    }
};