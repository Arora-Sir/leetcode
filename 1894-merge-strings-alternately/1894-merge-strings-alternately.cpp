class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1Length = word1.length();
        int word2Length = word2.length();
        int minLengthWord = min(word1Length,word2Length);
        string newString = "";

        for (int i = 0; i < minLengthWord; i++){
            newString+=word1[i];
            newString+=word2[i];
        }

        if(word1Length <= word2Length){
            for(int i = minLengthWord;i<word2Length; i++){
                newString+=word2[i];
            }
        }
        else{
            for(int i = minLengthWord;i<word1Length; i++){
                newString+=word1[i];
            }
        }
        return newString;
    }
};