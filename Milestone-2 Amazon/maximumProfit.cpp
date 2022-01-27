class Solution {
  public:
    const int INF = 1e9 + 5;
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>> prevRes(K+1, vector<int>(2, -INF));
        prevRes[0][0] = 0;
        // prevRes[i][j] = i transactions done , with j stock in hand
        
        for(int i = 0; i < N; i++) {
            vector<vector<int>> curRes(K+1, vector<int>(2));
            for(int j = 0; j <= K; j++) {
                // 1 stock in hand(either buy here or prevously buyed)
                curRes[j][1] = max(prevRes[j][1], prevRes[j][0] - A[i]);
                // 0 stock in hand(either sold prevously or sell here)
                curRes[j][0] = prevRes[j][0];
                if(j > 0) // can sell here ?
                    curRes[j][0] = max(curRes[j][0], prevRes[j-1][1] + A[i]);
            }
            prevRes = curRes;
        }
        int ans = 0;
        for(auto i: prevRes) 
            for(auto j: i)
                ans = max(ans, j);
                
        return ans;
    }
};