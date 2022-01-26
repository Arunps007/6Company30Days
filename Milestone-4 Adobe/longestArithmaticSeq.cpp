class Solution{   
public:
    int lengthOfLongestAP(int a[], int n) {
        vector<vector<int>> dp(n, vector<int>(a[n-1]+1));
        int ans = 1;
        for(int i = n-2; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                int dif = a[j] - a[i];
                dp[i][dif] = 1 + dp[j][dif];
                ans = max(ans, dp[i][dif]+1);
            }
        }
        return ans;
    }
};