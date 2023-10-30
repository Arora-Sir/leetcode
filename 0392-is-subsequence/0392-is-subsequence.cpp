class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        int j = 0;
        if(tSize<sSize) return false;
        if(sSize==0) return true;

        for(int i=0;i<tSize;i++){
            if(s[j] == t[i]) { 
                j++;
                if(j==sSize) 
                    return true;
            }
        }
        return false;
    }
};