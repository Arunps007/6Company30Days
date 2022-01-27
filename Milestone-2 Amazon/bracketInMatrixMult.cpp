class Solution{
public:

    pair<string, int> solve(int a[], int l, int r, vector<vector<pair<string, int>>> &dp) {
        if(l == r)
            return {string(1, l-1+'A'), 0};
            
        if(dp[l][r].second != -1)
            return dp[l][r];
            
        int minCost = INT_MAX;
        string minString = "";
        
        for(int i = l; i < r; i++) {
            
            auto leftRes = solve(a, l, i, dp);
            auto rightRes = solve(a, i+1, r, dp);
            
            string leftString = leftRes.first, rightString = rightRes.first;
            int leftCost = leftRes.second, rightCost = rightRes.second;
            
            int totalCost = leftCost + rightCost + a[l-1] * a[i] * a[r];
            
            if(totalCost < minCost) {
                minCost = totalCost;
                minString = "(" + leftString + rightString + ")";
            }
        }
        return dp[l][r] = {minString, minCost};
    }

    string matrixChainOrder(int p[], int n){
        vector<vector<pair<string, int>>> dp(n, vector<pair<string, int>>(n, {"", -1}));
        return solve(p, 1, n-1, dp).first;
    }
};