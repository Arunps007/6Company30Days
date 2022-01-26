class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
        vector<int> presum(n+1);
        for(int i = 1; i <= n; i++)
            presum[i] = presum[i-1] + A[i-1];
	    vector<int> prev(n+1);
	    for(int i = 1; i <= n; i++) {
	        vector<int> cur(n+1);
	        for(int j = 0; j < n-i+1; j++) {
	            int l = j, r = j+i-1;
	            int firstCost = A[l]+(presum[r+1]-presum[l+1] - prev[l+1]);
	            int lastCost = A[r]+(presum[r]-presum[l] - prev[l]);
	            cur[j] = max(firstCost, lastCost);
	        }
	        prev = cur;
	    }
	    return prev[0];
    }
};