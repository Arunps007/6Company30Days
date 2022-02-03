class Solution {
int dp[501][501][2];
    int c=0;
    int winner(vector<int>& piles, bool turn, int st, int en){
        if(st>en){
            return 0;
        }
        if(dp[st][en][turn]!=-1){
            return dp[st][en][turn];
        }
        if(turn){
            int alice1 = piles[st]+winner(piles, false, st+1, en);
            int alice2 = piles[en]+winner(piles, false, st, en-1);
            dp[st][en][turn] = max(alice1,alice2);
            return max(alice1, alice2);
        }
        int alice1 = winner(piles, true, st+1, en);
        int alice2 = winner(piles, true, st, en-1);
        dp[st][en][turn] = max(alice1, alice2);
        return min(alice1, alice2);
    }
    
    public:
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int sum=0;
        for(int i:piles){
            sum+=i;
        }
        int alex = winner(piles, true, 0, piles.size()-1);
        return sum-alex<alex;
    }
};
