class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool isPositive = (dividend<0 == divisor<0);
        unsigned int dnd = abs(dividend);
        unsigned int dsr = abs(divisor);
        if(dnd == dsr){
            return isPositive ? 1 : -1;
        }
        unsigned ans = 0;
        while(dnd >= dsr){
            short cnt = 0;
            while(dnd > (dsr<<(cnt+1))){
                cnt++;
            }
            dnd -= (dsr<<cnt);
            ans += (1<<cnt);
        }
        if(ans == (1<<31) and isPositive){
            return INT_MAX;
        }
        return isPositive ? ans : -ans;
    }
};
