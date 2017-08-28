class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int sindexl = -1;
        int sindexr = -1;
        int nindex = -1;
        int mindis = -1;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1 || words[i] == word2){
                if(sindexl == -1)   sindexl = i;
                else if(sindexr == -1){
                    if(words[sindexl] == words[i])  sindexl = i;
                    else{
                        sindexr = i;
                        mindis = i - sindexl;
                    }
                }
                else{
                    if(nindex == -1){
                        if(words[sindexr] == words[i])  nindex = i;
                        else{
                            if(i - sindexr < mindis){
                                sindexl = sindexr;
                                sindexr = i;
                                mindis = i - sindexl;
                            }
                            else nindex = i;
                        }
                    }
                    else{
                        if(words[nindex] == words[i])   nindex = i;
                        else{
                            if(i - nindex < mindis){
                                sindexl = nindex;
                                sindexr = i;
                                mindis = i - nindex;
                                nindex = -1;
                            }
                        }
                    }
                }
            }
        }
        return mindis;
    }
};