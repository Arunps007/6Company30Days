class Solution {
    vector<int> dp;
    int n;
    int query(int low, int high){
        if(high==low){
            return 0;
        }
        if(dp[low*n+high]!=-1){
            return dp[low*n+high];
        }
        if(high-low==1){
            return low;
        }
        if(high-low==2){
            return low+1;
        }
        int ans=INT_MAX;
        for(int i=low+1;i<high;i++){
            ans = min(ans, max(query(low, i-1), query(i+1, high))+i);
        }
        return dp[low*n+high] = ans;
    }
public:
    int getMoneyAmount(int n) {
        this->n = n;
        dp = vector<int>((n+1)*(n+1), -1);
        return query(1, n);
    }
};
