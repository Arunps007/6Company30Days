class Solution{
  public:
    string nextPalin(string s) { 
        int n = s.length();
        int i = n/2-2;
        while(i >= 0) {
            if(s[i] < s[i+1]) {
                
                reverse(s.begin()+i+1, s.begin()+n/2);
                
                int l = i+1;
                while(s[l] <= s[i]) {
                    l++;
                }
                
                char temp = s[i];
                s[i] = s[l];
                s[l] = temp;
                
                string left = s.substr(0, n/2);
                string right = left;
                reverse(right.begin(), right.end());
                
                if(n&1) {
                    return left + s[n/2] + right;
                }
                return left + right;
            }
            i--;
        }
        return "-1";
    }
};