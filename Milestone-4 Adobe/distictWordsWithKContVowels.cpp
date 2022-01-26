class Solution
{
  public:
  
    #define ll long long int
    const int MOD = 1e9 + 7;
  
    int kvowelwords(int n, int k) {
        vector<ll> prev(k+1, 1);
        
        for(int i = 1; i <= n; i++) {
            vector<ll> cur(k+1);
            
            for(int j = 0; j <= k; j++) {
                cur[j] = prev[k] * 21 % MOD;
                if(j > 0)
                    cur[j] = (cur[j] + prev[j-1] * 5 % MOD) % MOD;
            }
            
            prev = cur;
        }
        return prev[k];
    }
};