class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        if(n < 3)
            return 0;
        int prev = a[1] - a[0];
        int incCount = prev > 0, decCount = prev < 0;
        int res = 0;
        for(int i = 2; i < n; i++) {
            int cur = a[i] - a[i-1];
            if(cur == 0) {
                incCount = 0;
                decCount = 0;
                continue;
            }
            else if(cur < 0) {
                if(prev < 0) 
                    decCount++;
                else 
                    decCount = 1;
                if(incCount)
                    res = max(res, incCount + decCount + 1);
            }
            else {
                if(prev > 0) 
                    incCount++;
                else 
                    incCount = 1;
            }
            prev = cur;
        }
        return res;
    }
};