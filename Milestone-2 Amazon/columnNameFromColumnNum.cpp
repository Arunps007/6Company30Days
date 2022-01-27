class Solution{
    public:
    string colName (long long int n)
    {
        string res = "";
        while(n) {
            int i = n % 26;
            if(i == 0) {
                res += 'Z';
                n -= 26;
                n /= 26;
            }
            else {
                res += 'A' + i - 1;
                n -= i;
                n /= 26;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};