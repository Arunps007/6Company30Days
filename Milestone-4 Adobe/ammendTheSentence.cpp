class Solution{
    public:
    string amendSentence (string s)
    {
        string res;
        res += tolower(s[0]);
        int n = s.length();
        for(int i = 1; i < n; i++) {
            if(isupper(s[i])) {
                res += ' ';
                res += tolower(s[i]);
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};