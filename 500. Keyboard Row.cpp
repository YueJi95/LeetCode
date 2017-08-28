class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        int list[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        for(int i = 0; i < words.size(); i++){
            string tem = words[i];
            int wline = -1;
            bool flag = true;
            for(int j = 0; j < tem.size(); j++){
                int index = tem[j] - 'A';
                if(index >= 26) index = tem[j] - 'a';
                int cline = list[index];
                if(wline == -1) wline = cline;
                else if(wline != cline){
                    flag = false;
                    break;
                }
            }
            if(flag == true)  result.push_back(tem);
        }
        return result;
    }
};