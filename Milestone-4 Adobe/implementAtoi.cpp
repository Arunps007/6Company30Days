class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int res = 0;
        bool neg = false;
        for(char c: str) {
            if(c == '-') {
                if(neg)
                    return -1;
                else
                    neg = true;
                continue;
            }
                
            if(!isdigit(c))
                return -1;
            res *= 10;
            res += c-'0';
        }
        return neg ? -res : res;
    }
};