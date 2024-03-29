class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string result = str1; 
        result = gcd(result, str1);
        result = gcd(result, str2);
        return result;
    }
    
    string gcd(string str1, string str2)
    {
        if (str1.length() < str2.length()) 
        {
            return gcd(str2, str1);
        }
        else if(str1.find(str2) != 0) 
        {
            return "";
        }
        else if (str2 == "") 
        {
            return str1;
        }
        else
        {
            return gcd(str1.substr(str2.length()), str2);
        }
    }
};