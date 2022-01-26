class Solution {
public:
    
    int nextDot(string s, int ind, int n) {
      for(int i = ind ; i < n ; i++) {
          if(s[i] == '.') {
              return i;
          }
      }
      return n;
    }

    string removeLeadingZeroes(string s) {
      for(int i = 0 ; i < s.length() ; i++) {
          if(s[i] != '0') {
              return s.substr(i, s.length()-i);
          }
      }
      return "0";
    }

    int compareVersion(string a, string b) {
      int n = a.length();
      int m = b.length();
      int i = 0, j = 0;
      while(i < n || j < m) {
          int na = nextDot(a, i, n);
          int nb = nextDot(b, j, m);
          string sa = removeLeadingZeroes(a.substr(i, na-i));
          string sb = removeLeadingZeroes(b.substr(j, nb-j));
          i = min(n, na + 1);
          j = min(m, nb + 1);
          if(sa.length() > sb.length()){
            return 1;
          }
          else if(sa.length() < sb.length()){
            return -1;
          }
          else if(sa < sb) {
              return -1;
          }
          else if(sa > sb) {
              return 1;
          }
      }
      return 0;
    }

    
};