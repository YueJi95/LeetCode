class Solution {
public:
    int calPoints(vector<string>& ops) {
        int pos = 0;
        int score[ops.size()];
        for(int i = 0; i < ops.size(); i++){
            string s = ops[i];
            if(s == "C") pos--;
            else if(s == "D"){
                score[pos] = 2 *score[pos-1];
                pos++;
            }
            else if(s == "+"){
                score[pos] = score[pos-1] + score[pos-2];
                pos++;
            }
            else{
                score[pos] = stoi(s);
                pos++;
            }
        }
        int result = 0;
        for(int i = 0; i < pos; i++){
            result = result + score[i];
        }
        return result;
    }
};