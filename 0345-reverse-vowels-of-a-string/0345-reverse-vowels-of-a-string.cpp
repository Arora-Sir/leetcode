class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!isVowel(s[i])) {
                i++;
            }
            if (!isVowel(s[j])) {
                j--;
            }
            if (isVowel(s[i]) && isVowel(s[j])) {
                cout<<s[i]<<" "<<s[j];
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        return s;
    }

    bool isVowel(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || 
            x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
            return true;
        else return false;
    }
};